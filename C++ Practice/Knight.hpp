//
//  Knight.hpp
//  C++ Practice
//
//  Created by Alex Frank on 11/25/17.
//  Copyright © 2017 Alex Frank. All rights reserved.
//

#ifndef Knight_hpp
#define Knight_hpp

#include "Character.hpp"
#include "Enemy.hpp"

class Knight: public Character {
public:
    Knight(string new_name);
    void attack(Character *target);
    bool use_skill(Character *enemy);
    void level_up();
    
    //Skills:
    map<string, bool> skills;
    bool power_swing(Character *target);
    bool double_attack(Character *target);
    bool spin_attack(Character *target);
};

#endif /* Knight_hpp */
