//
//  main.cpp
//  Braid
//
//  Created by Alex Frank on 3/5/18.
//  Copyright © 2018 Alex Frank. All rights reserved.
//

#include <stdio.h>
#include "Braid_Grp.hpp"
#include "AAG.hpp"

int main(){
    
    //Testing Braid_Grp
    
    char init[] = {'a','f','b','e','c','d'};
    std::vector<char> new_elems(init,init+6);
    Braid_Grp *test = new Braid_Grp(new_elems);
    
    for(const auto &pair : test->inverse_map) {
        std::cout << pair.first << " " << pair.second << "\n";
    }
    
    test->add_elems('g','h');
    
    std::vector<char> test_get = test->get_elems(0);
    std::cout << test_get.size() << "\n";
    
    std::cout << test->inv("abc") << "\n"; //should result in "def"
    //std::cout << "WHY" << std::endl;
    
    std::cout << "\n";
    std::string braid1 = "baedd";
    std::cout << test->reduce(braid1) << "\n"; //same
    std::string braid2 = "dbcbaeede";
    std::cout << test->reduce(braid2) << "\n"; //same
    std::string braid3 = "abacfec";
    std::cout << test->reduce(braid3) << "\n"; //adbcc
    std::cout << "1 == 2: " << test->braid_eq(braid1, braid2) << "\n"; //True
    std::cout << "2 == 3: " << test->braid_eq(braid2, braid3) << "\n"; //False
    std::cout << "1 == 3: " << test->braid_eq(braid1, braid3) << "\n"; //False
    
    //Testing AAG
    
    return 0;
}
