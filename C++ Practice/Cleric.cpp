//
//  Cleric.cpp
//  C++ Practice
//
//  Created by Alex Frank on 11/25/17.
//  Copyright © 2017 Alex Frank. All rights reserved.
//

#include "Cleric.hpp"

Cleric::Cleric(string new_name) {
    job = cleric;
    wep_type = mace;
    wep = new Weapon("Basic Mace", mace, 1, 0);
    name = new_name;
    level = 1;
    max_hp = 8;
    cur_hp = 8;
    max_mp = 8;
    cur_mp = 8;
    
    skills["Heal"] = false;
    skills["Smite"] = false;
    skills["Cure"] = false;
}

void Cleric::attack(Character *target) {
    cout << name << " swings his weapon." << endl;
    target->take_damage(wep->power);                    //this will be calculated based on weapon damage, enemy armor, etc
}

void Cleric::level_up() {
    level++;
    max_hp += 1;
    max_mp += 1;
    cur_hp = max_hp;
    cur_mp = max_mp;
    switch (level) { //learn new skills
        case 2:
            skills["Heal"] = true;
            break;
            
        case 3:
            skills["Smite"] = true;
            break;
            
        case 4: skills["Cure"] = true;
            break;
            
        default:
            break;
    }
}

bool Cleric::use_skill(Character *enemy) {
    cout << "Known skills:" << endl;
    for (const auto& kv: this->skills) {
        if (kv.second) {
            cout << kv.first << endl;
        }
    }
    bool valid_com = false;
    string command;
    bool heal = false;
    bool smite = false;
    bool cure = false;
    while (!valid_com) {
        getline(cin, command);
        heal = command == "Heal" || command == "heal" || command == "1";
        smite = command == "Smite" || command == "smite" || command == "2";
        cure = command == "Cure" || command == "cure" || command == "3";
        if (heal || smite || cure) {
            valid_com = true;
        } else {
            cout << "Invalid command. Please try again." << endl;
        }
    }
    if (heal) {
        if (this->heal(this)) {
            return true;
        } else {
            return false;
        }
    } else if (smite) {
        if (this->smite(enemy)) {
            return true;
        } else {
            return false;
        }
    } else if (cure) {
        if (this->cure(this)) {
            return true;
        } else {
            return false;
        }
    } else {
        cout << "Cleric is confused as to how you got to this line of code." << endl;
        return false;
    }
}

bool Cleric::heal(Character *target) {
    if (cur_mp >= 1) {
        cout << name << " heals " << target->name << "." << endl;
        cur_mp -= 1;
        target->gain_health(2);
        return true;
    } else {
        cout << "Not enough MP to use this skill." << endl;
        return false;
    }
}

bool Cleric::smite(Character *target) {
    if (cur_mp >= 1) {
        cout << name << " uses Smite." << endl;
        cur_mp -= 1;
        target->take_damage(wep->power * 2);
        return true;
    } else {
        cout << "Not enough MP to use this skill." << endl;
        return false;
    }
}

bool Cleric::cure(Character *target) {
    if (cur_mp >= 3) {
        cout << name << " cures " << target->name << "." << endl;
        cur_mp -= 3;
        target->gain_health(4);
        return true;
    } else {
        cout << "Not enough MP to use this skill." << endl;
        return false;
    }
}
