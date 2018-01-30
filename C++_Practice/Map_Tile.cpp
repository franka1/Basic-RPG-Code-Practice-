//
//  Map_Tile.cpp
//  C++_Practice
//
//  Created by Alex Frank on 1/29/18.
//  Copyright © 2018 Alex Frank. All rights reserved.
//

#include "Map_Tile.hpp"

Map_Tile::Map_Tile(Item *new_item) {
    north = nullptr;
    south = nullptr;
    east = nullptr;
    west = nullptr;
    
    treasure = new_item;
}
