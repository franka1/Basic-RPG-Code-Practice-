//
//  Character.hpp
//  C++ Practice
//
//  Created by Alex Frank on 11/25/17.
//  Copyright © 2017 Alex Frank. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

enum Weapon_type {
    sword,
    mace,
    staff
};

enum Char_class {
    wizard,
    knight,
    cleric
};

class Character {
public:
    Char_class job;
    Weapon_type wep;
    string name;
    int level;
    int max_hp;
    int cur_hp;
    int max_mp;
    int cur_mp;
    
    void adjust_hp(int amount);
    void adjust_mp(int amount);
};

#endif /* Character_hpp */
