//
//  Map.hpp
//  C++_Practice
//
//  Created by Alex Frank on 1/29/18.
//  Copyright © 2018 Alex Frank. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include "Common.hpp"
#include "Map_Tile.hpp"

class Map {
    Map_Tile *entrance;
    
public:
    Map(Map_Tile *new_tile = nullptr);
    void generate_empty_map();
};

#endif /* Map_hpp */
