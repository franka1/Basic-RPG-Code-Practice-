//
//  Cleric.hpp
//  C++ Practice
//
//  Created by Alex Frank on 11/25/17.
//  Copyright © 2017 Alex Frank. All rights reserved.
//

#ifndef Cleric_hpp
#define Cleric_hpp

#include "Character.hpp"
#include "Enemy.hpp"

class Cleric : public Character {
public:
    Cleric(string new_name);
    void attack(Character *target);
    bool use_skill(Character *enemy);
    void level_up();
    
    //Skills:
    map<string, bool> skills;
    bool heal(Character *target);
    bool smite(Character *target);
    bool cure(Character *target);
};

#endif /* Cleric_hpp */
