//
//  Weapon.hpp
//  C++ Practice
//
//  Created by Alex Frank on 11/25/17.
//  Copyright © 2017 Alex Frank. All rights reserved.
//

#ifndef Weapon_hpp
#define Weapon_hpp

#include "Item.hpp"

class Weapon: public Item {
public:
    int power;
    Weapon_type type;
    
    Weapon(string new_name, Weapon_type new_type, int new_power, int new_value, int new_quant = 1);
};

#endif /* Weapon_hpp */
