//
//  Wizard.hpp
//  C++ Practice
//
//  Created by Alex Frank on 11/25/17.
//  Copyright © 2017 Alex Frank. All rights reserved.
//

#ifndef Wizard_hpp
#define Wizard_hpp

#include "Character.hpp"
#include "Enemy.hpp"

class Wizard: public Character {
public:
    Wizard(string new_name);
    void attack(Character *target);
    bool use_skill(Character *enemy);
    void level_up();
    
    //Skills:
    map<string, bool> skills;
    bool fireball(Character *target);
    bool ice_prison(Character *target);
    bool lightning_strike(Character *target);
};

#endif /* Wizard_hpp */
