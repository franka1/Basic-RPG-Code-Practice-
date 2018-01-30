//
//  Potion.hpp
//  C++ Practice
//
//  Created by Alex Frank on 1/17/18.
//  Copyright © 2018 Alex Frank. All rights reserved.
//

#ifndef Potion_hpp
#define Potion_hpp

#include "Consumable.hpp"
#include "Character.hpp"

class Potion: public Consumable {
public:
    Potion(string new_name, int new_value, int new_quant);
    bool use(Character *target);
};

#endif /* Potion_hpp */
