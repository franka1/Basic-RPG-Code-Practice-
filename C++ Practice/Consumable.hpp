//
//  Consumable.hpp
//  C++ Practice
//
//  Created by Alex Frank on 1/17/18.
//  Copyright © 2018 Alex Frank. All rights reserved.
//

#ifndef Consumable_hpp
#define Consumable_hpp

#include "Item.hpp"

class Character;

class Consumable: public Item {
public:
    virtual bool use(Character *target) = 0;
};

#endif /* Consumable_hpp */
