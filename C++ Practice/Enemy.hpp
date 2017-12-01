//
//  Enemy.hpp
//  C++ Practice
//
//  Created by Alex Frank on 11/26/17.
//  Copyright © 2017 Alex Frank. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include "Common.hpp"
#include "Character.hpp"

class Enemy: public Character {
public:
    Enemy(string new_name);
};

#endif /* Enemy_hpp */
