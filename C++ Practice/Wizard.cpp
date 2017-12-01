//
//  Wizard.cpp
//  C++ Practice
//
//  Created by Alex Frank on 11/25/17.
//  Copyright © 2017 Alex Frank. All rights reserved.
//

#include "Wizard.hpp"

Wizard::Wizard(string new_name) {
    job = wizard;
    wep_type = staff;
    wep = new Weapon("Basic Staff", staff, 3, 0);
    name = new_name;
    level = 1;
    max_hp = 5;
    cur_hp = 5;
    max_mp = 10;
    cur_mp = 10;
    
    skills["Fireball"] = false;
    skills["Ice Prison"] = false;
    skills["Lightning Strike"] = false;
}

void Wizard::attack(Character *enemy) {
    cout << name << " fires a bolt of magic energy." << endl;
    enemy->take_damage(wep->power);                     //this will be calculated based on weapon damage, enemy armor, etc
}

void Wizard::level_up() {
    level++;
    max_hp += 1;
    max_mp += 2;
    cur_hp = max_hp;
    cur_mp = max_mp;
    switch (level) { //learn new skills
        case 2:
            skills["Fireball"] = true;
            break;
            
        case 3:
            skills["Ice Prison"] = true;
            break;
            
        case 4: skills["Lightning Strike"] = true;
            break;
            
        default:
            break;
    }
}

bool Wizard::use_skill(Character *enemy) {
    cout << "Known skills:" << endl;
    for (const auto& kv: this->skills) {
        if (kv.second) {
            cout << kv.first << endl;
        }
    }
    bool valid_com = false;
    string command;
    bool fireball = false;
    bool ice_prison = false;
    bool lightning_strike = false;
    while (!valid_com) {
        getline(cin, command);
        fireball = command == "Fireball" || command == "fireball" || command == "1";
        ice_prison = command == "Ice Prison" || command == "ice prison" || command == "2";
        lightning_strike = command == "Lightning Strike" || command == "lightning strike" || command == "3";
        if (fireball || ice_prison || lightning_strike) {
            valid_com = true;
        } else {
            cout << "Invalid command. Please try again." << endl;
        }
    }
    if (fireball) {
        //attempt to use Fireball
        if(this->fireball(enemy)) {
            return true;
        } else {
            return false;
        }
    } else if (ice_prison) {
        if(this->ice_prison(enemy)) {
            return true;
        } else {
            return false;
        }
    } else if (lightning_strike) {
        if (this->lightning_strike(enemy)) {
            return true;
        } else {
            return false;
        }
    } else {
        cout << "Wizard is confused as to how you got to this line of code." << endl;
        return false;
    }
}

bool Wizard::fireball(Character *target) {
    if (cur_mp >= 1) {
        cout << name << " casts Fireball." << endl;
        cur_mp -= 1;
        target->take_damage(wep->power + 1);
        return true;
    } else {
        cout << "Not enough MP to use this skill." << endl;
        return false;
    }
}

bool Wizard::ice_prison(Character *target) {        //TODO: "stun" status
    if (cur_mp >= 2) {
        cout << name << " casts Ice Prison." << endl;
        cur_mp -= 2;
        target->take_damage(wep->power / 2);
        return true;
    } else {
        cout << "Not enough MP to use this skill." << endl;
        return false;
    }
}

bool Wizard::lightning_strike(Character *target) {
    if (cur_mp >= 3) {
        cout << name << " casts Lightning Strike." << endl;
        cur_mp -= 3;
        target->take_damage(wep->power + 2);
        return true;
    } else {
        cout << "Not enough MP to use this skill." << endl;
        return false;
    }
}
