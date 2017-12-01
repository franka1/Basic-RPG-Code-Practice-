//
//  Knight.cpp
//  C++ Practice
//
//  Created by Alex Frank on 11/25/17.
//  Copyright © 2017 Alex Frank. All rights reserved.
//

#include "Knight.hpp"

Knight::Knight(string new_name) {
    job = knight;
    wep_type = sword;
    wep = new Weapon("Basic Sword", sword, 2, 0);
    name = new_name;
    level = 1;
    max_hp = 10;
    cur_hp = 10;
    max_mp = 5;
    cur_mp = 5;
    
    skills["Power Swing"] = false;
    skills["Double Attack"] = false;
    skills["Spin Attack"] = false;
}

void Knight::attack(Character *target) {
    cout << name << " swings his weapon." << endl;
    target->take_damage(wep->power);                    //this will be calculated based on weapon damage, enemy armor, etc
}

void Knight::level_up() {
    level++;
    max_hp += 2;
    max_mp += 1;
    cur_hp = max_hp;
    cur_mp = max_mp;
    switch (level) { //learn new skills
        case 2:
            skills["Power Swing"] = true;
            break;
            
        case 3:
            skills["Double Attack"] = true;
            break;
            
        case 4: skills["Spin Attack"] = true;
            break;
            
        default:
            break;
    }
}

bool Knight::use_skill(Character *enemy) {
    cout << "Known skills:" << endl;
    for (const auto& kv: this->skills) {
        if (kv.second) {
            cout << kv.first << endl;
        }
    }
    bool valid_com = false;
    string command;
    bool power_swing = false;
    bool double_attack = false;
    bool spin_attack = false;
    while (!valid_com) {
        getline(cin, command);
        cout << command << endl;
        power_swing = (command == "Power Swing" || command == "power swing" || command == "1");
        double_attack = (command == "Double Attack" || command == "double attack" || command == "2");
        spin_attack = (command == "Spin Attack" || command == "spin attack" || command == "3");
        if (power_swing || double_attack || spin_attack) {
            valid_com = true;
        } else {
            cout << "Invalid command. Please try again." << endl;
        }
    }
    if (power_swing) {
        if (this->power_swing(enemy)) {
            return true;
        } else {
            return false;
        }
    } else if (double_attack) {
        if (this->double_attack(enemy)) {
            return true;
        } else {
            return false;
        }
    } else if (spin_attack) {
        if (this->spin_attack(enemy)) {
            return true;
        } else {
            return false;
        }
    } else {
        cout << "Knight is confused as to how you got to this line of code." << endl;
        return false;
    }
}

bool Knight::power_swing(Character *target) {
    if (cur_mp >= 1) {
        cout << name << " uses Power Swing." << endl;
        cur_mp -= 1;
        target->take_damage(wep->power + 1);
        return true;
    } else {
        cout << "Not enough MP to use this skill." << endl;
        return false;
    }
}

bool Knight::double_attack(Character *target) {
    if (cur_mp >= 2) {
        cout << name << " uses Double Attack." << endl;
        cur_mp -= 2;
        target->take_damage(wep->power);
        target->take_damage(wep->power);
        return true;
    } else {
        cout << "Not enough MP to use this skill." << endl;
        return false;
    }
}

bool Knight::spin_attack(Character *target) {
    if (cur_mp >= 3) {
        cout << name << " uses Spin Attack." << endl;
        cur_mp -= 3;
        target->take_damage(wep->power + 2);
        return true;
    } else {
        cout << "Not enough MP to use this skill." << endl;
        return false;
    }
}
