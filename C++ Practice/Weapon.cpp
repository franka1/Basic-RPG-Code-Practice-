//
//  Weapon.cpp
//  C++ Practice
//
//  Created by Alex Frank on 11/25/17.
//  Copyright © 2017 Alex Frank. All rights reserved.
//

#include "Weapon.hpp"

Weapon::Weapon(string new_name, Weapon_type new_type, int new_power, int new_value) {
    name = new_name;
    type = new_type;
    power = new_power;
    sell_value = new_value;
}
