//
//  Character.cpp
//  C++ Practice
//
//  Created by Alex Frank on 11/25/17.
//  Copyright © 2017 Alex Frank. All rights reserved.
//

#include "Character.hpp"

void Character::take_damage(int amount) {
    if (cur_hp < amount) {
        cur_hp = 0;
    } else {
        cur_hp -= amount;
    }
    cout << this->name << " takes " << amount << " damage " << endl;
}

void Character::gain_health(int amount) {
    if (max_hp - cur_hp < amount) {
        cur_hp = max_hp;
    } else {
        cur_hp += amount;
    }
    cout << this->name << " gains " << amount << " health." << endl;
}

void Character::adjust_mp(int amount) {
    if (cur_mp < amount) {
        cur_mp = 0;
    } else {
        cur_mp += amount;
    }
}

void Character::add_weapon(Weapon *new_wep) {
    if (new_wep->type == wep_type) {
        wep = new_wep;
        cout << name << " has equipped " << wep->name << "." << endl;
    } else {
        cout << name << " cannot use that type of weapon." << endl;
    }
}

void Character::combat(Character *enemy) {
    cout << this->name << " has been attacked by " << enemy->name << "!" << endl;
    while (this->cur_hp > 0 && enemy->cur_hp > 0) {
        
        //Player's Turn
        
        cout << endl;
        cout << "HP: " << this->cur_hp << " MP: " << this->cur_mp << endl;
        cout << "| [1] Attack | [2] Skill |" << endl;
        cout << "|------------------------|" << endl;
        cout << "| [3] Item   | [4] Run   |" << endl;
        cout << endl;
        bool valid_com = false;
        string command;
        bool attack = false;
        bool skill = false;
        bool item = false;
        bool run = false;
        while (!valid_com) {
            getline(cin, command);
            attack = (command == "Attack" || command == "attack" || command == "1");
            skill = (command == "Skill" || command == "skill" || command == "2");
            item = (command == "Item" || command == "item" || command == "3");
            run = (command == "Run" || command == "run" || command == "4");
            if (attack || skill || item || run) {
                valid_com = true;
            } else {
                cout << command << endl;
                cout << "Invalid command. Please try again." << endl;
            }
        }
        
        if (attack) {
            this->attack(enemy);
            
        } else if (skill) {
            //If no mana to use skill, skill will fail. Player must choose different action.
            if(!this->use_skill(enemy)) {
                continue;
            }
            
        } else if (item) {
            int list_index = 1;
            cout << "| Key |     Item     | Qty |" << endl;
            cout << "|-----|--------------|-----|" << endl;
            for (auto const& i : inventory) {
                cout << "| [" << list_index << "] | " << i->name << "  |  " << i->quantity << "  |"<< endl;
                list_index++;
            }
            //TODO: Deal with invalid input here
            string index_string;
            getline(cin, index_string);
            int index = std::stoi(index_string);
            
            cout << "Use " << inventory[index-1]->name << " on [1] " << this->name;
            cout << " or [2] " << enemy->name << "?" << endl;
            
            string target_string;
            getline(cin, target_string);
            int target = std::stoi(target_string);
            
            //Attempt to use item (checks quantity)
            if (target == 1) {
                if(!inventory[index-1]->use(this)) {
                    continue;
                };
            } else if (target == 2) {
                if(!inventory[index-1]->use(enemy)) {
                    continue;
                };
            }
               
        } else if (run) {
            cout << this->name << " bravely ran away!" << endl;
            return;
            
        } else {
            cout << "Some strange error led us astray." << endl;
        }
        
        //Enemy Turn
        if (enemy->cur_hp > 0) {
            enemy->attack(this);
        } else {
            //If enemy has no health, they cannot take an action. Combat ends.
            break;
        }
    }
    
    //Enemy has zero or less HP
    if (this->cur_hp > 0) {
        cout << this->name << " defeated " << enemy->name << "!" << endl;
    } else {
        cout << this->name << " was defeated!" << endl;
    }
}
