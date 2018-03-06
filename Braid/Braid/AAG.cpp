//
//  AAG.cpp
//  Braid_AAG
//
//  Created by Alex Frank on 2/28/18.
//

#include "AAG.hpp"

AAG::AAG(Braid_Grp *new_group) {
    group = new_group;
}

std::vector<std::string> AAG::public_key() {
    std::vector<std::string> result;
    std::vector<char> generators = group->get_elems(0);
    while(rand() % 10 < 8) {                                //80% chance
        std::string elem = "";
        while(rand() % 10 < 8) {
            elem += generators[rand() % generators.size()]; //pick a random generator
        }
        //if(elem.compare("") != 0) {                       //check for empty string
        //    result.push_back(elem);
        //}
    }
    if(result.empty()) {                                    //if vector is empty, try again
        return AAG::public_key();
    } else {
        return result;
    }
}
