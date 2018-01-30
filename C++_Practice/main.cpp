//
//  main.cpp
//  C++ Practice
//
//  Created by Alex Frank on 12/19/16.
//  Copyright © 2016 Alex Frank. All rights reserved.
//

#include "Common.hpp"
#include "Enemy.hpp"
#include "Knight.hpp"
#include "Cleric.hpp"
#include "Wizard.hpp"
#include "Potion.hpp"

using namespace std;

int main() {
    Cleric *Axel = new Cleric("Axel");
    Wizard *Rolain = new Wizard("Rolain");
    Knight *Kirios = new Knight("Kirios");
    
    //Test level up/skill learning
    Kirios->level_up();
    Kirios->level_up();
    
    //Basic scripted combat test
    /*while (Kirios->cur_hp > 0 && Axel->cur_hp > 0) {
        Axel->heal(Axel);
        Kirios->double_attack(Axel);
        cout << "Kirios' current health is: " << Kirios->cur_hp << endl;
        cout << "Axel's current health is: " << Axel->cur_hp << endl;
    }*/
    //Restore stats
    Axel->cur_hp = Axel->max_hp;
    Axel->cur_mp = Axel->max_mp;
    Kirios->cur_hp = Kirios->max_hp;
    Kirios->cur_mp = Kirios->max_mp;

    cout << endl;
    
    //Skill test
    /*Rolain->level_up();
    
    for (const auto& kv: Rolain->skills) {
        if (kv.second) {
            cout << "Rolain knows " << kv.first << endl;
        } else {
            cout << "Rolain does not know " << kv.first << endl;
        }
    }
    
    cout << endl;*/
    
    //Inventory test
    Potion *healpot = new Potion("Heal Potion", 5, 3);
    Potion *acidpot = new Potion("Acid Potion", 5, 2);
    Kirios->inventory.push_back(healpot);
    Kirios->inventory.push_back(acidpot);
    
    //Test combat() method
    Rolain->cur_hp = 100;
    Kirios->combat(Rolain);
    
    return 0;
}

//Notes:

//Classification:   An ITEM is an object that can be stored in the inventory.
//                  A CONSUMABLE is an ITEM with a "use" method.
//                  A WEAPON can be equipped and has a "power" stat.
//                  Armor and Quest items to come later.

//TODO: add miss chances to skills/attacks
