//
//  handle_reduc.hpp
//  Braid_AAG
//
//  Created by Alex Frank on 2/28/18.
//

#ifndef handle_reduc_hpp
#define handle_reduc_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

class Braid_Grp {
public:
    std::vector<char> elems;
    std::vector<char> inverses;
    std::map<char,char> inverse_map;
    std::vector<char> all_elems;
    Braid_Grp(std::vector<char>& new_elems);
    std::vector<char>& get_elems(int mode);
    void add_elems(char elem, char inverse);
    std::string inv(std::string braid);
    //bool valid_handle(std::string braid);
};

#endif /* handle_reduc_hpp */
