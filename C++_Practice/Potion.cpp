//
//  Potion.cpp
//  C++ Practice
//
//  Created by Alex Frank on 1/17/18.
//  Copyright © 2018 Alex Frank. All rights reserved.
//

#include "Potion.hpp"

Potion::Potion(string new_name, int new_value, int new_quant) {
    name = new_name;
    sell_value = new_value;
    quantity = new_quant;
}

bool Potion::use(Character *target) {
    bool success = true;
    if (quantity > 0) {
        if (name == "Heal Potion") {
            target->gain_health(5);
        } else if (name == "Cure Potion") {
            //TODO: this will cure a status condition, once those are implemented
        } else if (name == "Acid Potion") {
            //TODO: add miss chance
            target->take_damage(3);
        } else {
            cout << "Invalid Potion Type" << endl;
            return false;
        }
        quantity -= 1;
    }
    return success;
}
