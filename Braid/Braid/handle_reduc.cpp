//
//  handle_reduc.cpp
//  Braid_AAG
//
//  Created by Alex Frank on 2/28/18.
//

#include "handle_reduc.hpp"

//A Braid Group is a set of elements and their inverses
//which behave according to certain properties.
//We can represent individual braids as strings (an ordered set of elements).
Braid_Grp::Braid_Grp(std::vector<char>& new_elems) {
    //We need an even number of elements so that we can
    //establish element/inverse pairs
    if(new_elems.size() % 2 == 1) {
        std::cout << "Need even number of elements." << std::endl;
        return;
    }
    
    //Sort elements into appropraite vectors and generate the inverse map
    for(int i = 0; i < new_elems.size(); i++) {
        //std::cout << "Testing " << i << "\n";
        if(i % 2 == 0) {
            elems.push_back(new_elems[i]);
            all_elems.push_back(new_elems[i]);
            inverse_map[new_elems[i]] = new_elems[i+1];
        } else {
            inverses.push_back(new_elems[i]);
            all_elems.push_back(new_elems[i]);
            inverse_map[new_elems[i]] = new_elems[i-1];
        }
    }
}

std::vector<char>& Braid_Grp::get_elems(int mode) {
    if(mode >= 1) {
        return elems;
    } else if(mode <= -1) {
        return inverses;
    } else {
        return all_elems;
    }
}

void Braid_Grp::add_elems(char elem, char inverse) {
    elems.push_back(elem);
    all_elems.push_back(elem);
    inverses.push_back(inverse);
    all_elems.push_back(inverse);
    inverse_map[elem] = inverse;
    inverse_map[inverse] = elem;
}

std::string Braid_Grp::inv(std::string braid) {
    std::string inverse = "";
    for(int i = 0; i < braid.length(); i++) {
        inverse = inverse_map[braid[i]] + inverse;
    }
    return inverse;
}

int main(){
    char init[] = {'a','b','c','d','e','f'};
    std::vector<char> new_elems(init,init+6);
    Braid_Grp *test = new Braid_Grp(new_elems);
    
    for(const auto &pair : test->inverse_map) {
        std::cout << pair.first << " " << pair.second << "\n";
    }
    
    test->add_elems('g','h');
    
    std::vector<char> test_get = test->get_elems(0);
    std::cout << test_get.size() << "\n";
    
    std::cout << test->inv("abc") << "\n"; //should result in "dab"
    //std::cout << "WHY" << std::endl;
    return 0;
}
