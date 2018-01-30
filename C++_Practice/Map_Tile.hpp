//
//  Map_Tile.hpp
//  C++_Practice
//
//  Created by Alex Frank on 1/29/18.
//  Copyright © 2018 Alex Frank. All rights reserved.
//

#ifndef Map_Tile_hpp
#define Map_Tile_hpp

#include "Common.hpp"
#include "Item.hpp"

class Map_Tile {
public:
    Map_Tile *north;
    Map_Tile *south;
    Map_Tile *east;
    Map_Tile *west;
    
    Item *treasure;

    Map_Tile(Item *new_item);
};

#endif /* Map_Tile_hpp */
