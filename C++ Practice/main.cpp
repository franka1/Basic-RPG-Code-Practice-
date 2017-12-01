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

using namespace std;

int main() {
    Cleric *Axel = new Cleric("Axel");
    Wizard *Rolain = new Wizard("Rolain");
    Knight *Kirios = new Knight("Kirios");
    
    //Basic scripted combat test
    Kirios->level_up();
    Kirios->level_up();
    
    while (Kirios->cur_hp > 0 && Axel->cur_hp > 0) {
        Axel->heal(Axel);
        Kirios->double_attack(Axel);
        cout << "Kirios' current health is: " << Kirios->cur_hp << endl;
        cout << "Axel's current health is: " << Axel->cur_hp << endl;
    }
    //Restore stats
    Axel->cur_hp = Axel->max_hp;
    Axel->cur_mp = Axel->max_mp;
    Kirios->cur_hp = Kirios->max_hp;
    Kirios->cur_mp = Kirios->max_mp;

    cout << endl;
    
    //Skill test
    Rolain->level_up();
    
    for (const auto& kv: Rolain->skills) {
        if (kv.second) {
            cout << "Rolain knows " << kv.first << endl;
        } else {
            cout << "Rolain does not know " << kv.first << endl;
        }
    }
    
    cout << endl;
    
    //Test combat() method
    Rolain->cur_hp = 100;
    Kirios->combat(Rolain);
    
    return 0;
}

//Notes:
//TODO: Make Skills objects. They have a cost, a name, and a "use" method that contain the effect.
//TODO: Skill's "use()" method should return a bool. True if succesful, false otherwise.
