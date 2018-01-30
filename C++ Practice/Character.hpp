//
//  Character.hpp
//  C++ Practice
//
//  Created by Alex Frank on 11/25/17.
//  Copyright © 2017 Alex Frank. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include "Common.hpp"
#include "Weapon.hpp"
#include "Consumable.hpp"

enum Char_class {
    wizard,
    knight,
    cleric,
    monster
};

class Character {
public:
    Char_class job;
    Weapon_type wep_type;
    Weapon *wep;
    string name;
    int level;
    int max_hp;
    int cur_hp;
    int max_mp;
    int cur_mp;
    std::vector<Consumable*> inventory;
    
    void take_damage(int amount);
    void gain_health(int amount);
    void adjust_mp(int amount);
    void add_weapon(Weapon *new_wep);
    void use_item();                    //calls the item's (consumable) "use" method
    void combat(Character *enemy);
    virtual void attack(Character *target) = 0;
    virtual bool use_skill(Character *enemy) = 0;
    virtual void level_up() = 0;
};

#endif /* Character_hpp */
