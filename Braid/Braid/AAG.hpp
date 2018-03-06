//
//  AAG.hpp
//  Braid_AAG
//
//  Created by Alex Frank on 2/28/18.
//

#ifndef AAG_hpp
#define AAG_hpp

#include <stdio.h>
#include <vector>
#include "Braid_Grp.hpp"
#include <string>

class AAG {
    Braid_Grp *group;
    
public:
    AAG(Braid_Grp* new_group = nullptr);
    std::vector<std::string> public_key();
    std::vector<std::string> private_key();
    std::string key_product(std::vector<char> pub, std::vector<char> pri);
    std::string gen_left_key(std::vector<char> pri, std::string product, std::vector<char> send);
    std::string gen_right_key(std::vector<char> pri, std::string product, std::vector<char> send);
};

#endif /* AAG_hpp */
