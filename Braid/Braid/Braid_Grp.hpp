//
//  Braid_Grp.hpp
//  Braid_AAG
//
//  Created by Alex Frank on 2/28/18.
//

#ifndef Braid_Grp_hpp
#define Braid_Grp_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <climits>

class Braid_Grp {
    std::vector<char> elems;
    std::vector<char> inverses;
    std::vector<char> all_elems;
    
public:
    std::map<char,char> inverse_map;
    Braid_Grp(std::vector<char>& new_elems);
    
    std::vector<char>& get_elems(int mode);
    void add_elems(char elem, char inverse);
    std::string inv(std::string braid);
    bool valid_handle(std::string braid);
    int* loc_handle(std::string braid);     //points to a 2-element array
    std::string reduce_handle_step(std::string braid, int start, int end);
    std::string reduce(std::string braid);
    void print_handle(std::string braid);
    std::string mult(std::string b1, std::string b2);
    bool braid_eq(std::string b1, std::string b2);
    std::string conj(std::string b1, std::string b2);
    std::string conj(std::string braid, char elem);
};



#endif /* Braid_Grp_hpp */
