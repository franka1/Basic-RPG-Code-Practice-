//
//  Map.cpp
//  C++_Practice
//
//  Created by Alex Frank on 1/29/18.
//  Copyright © 2018 Alex Frank. All rights reserved.
//

#include "Map.hpp"

Map_Tile* north_helper(Map_Tile *parent);
Map_Tile* south_helper(Map_Tile *parent);
Map_Tile* east_helper(Map_Tile *parent);
Map_Tile* west_helper(Map_Tile *parent);

Map::Map(Map_Tile *new_tile) {
    entrance = new_tile;
}

//Generation method. Creates a map devoid of treasure.
//The generated map may also defy conventional physics,
//since collision checking is not currently implemented.
void Map::generate_empty_map() {
    entrance = new Map_Tile(nullptr);
    entrance->north = north_helper(entrance);
    entrance->south = south_helper(entrance);
    entrance->east = east_helper(entrance);
    entrance->west = west_helper(entrance);
}

Map_Tile* north_helper(Map_Tile *parent) {
    if(rand() % 100 < 25) {
        Map_Tile *tile = new Map_Tile(nullptr);
        tile->north = east_helper(tile);
        tile->south = parent;
        tile->east = east_helper(tile);
        tile->west = west_helper(tile);
        return tile;
    } else {
        return nullptr;
    }
}

Map_Tile* south_helper(Map_Tile *parent) {
    if(rand() % 100 < 25) {
        Map_Tile *tile = new Map_Tile(nullptr);
        tile->north = parent;
        tile->south = east_helper(tile);
        tile->east = east_helper(tile);
        tile->west = west_helper(tile);
        return tile;
    } else {
        return nullptr;
    }
}


Map_Tile* east_helper(Map_Tile *parent) {
    if(rand() % 100 < 25) {
        Map_Tile *tile = new Map_Tile(nullptr);
        tile->north = north_helper(tile);
        tile->south = south_helper(tile);
        tile->east = east_helper(tile);
        tile->west = parent;
        return tile;
    } else {
        return nullptr;
    }
}

Map_Tile* west_helper(Map_Tile *parent) {
    if(rand() % 100 < 25) {
        Map_Tile *tile = new Map_Tile(nullptr);
        tile->north = north_helper(tile);
        tile->south = south_helper(tile);
        tile->east = parent;
        tile->west = west_helper(tile);
        return tile;
    } else {
        return nullptr;
    }
}
