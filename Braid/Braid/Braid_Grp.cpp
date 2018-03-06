//
//  Braid_Grp.cpp
//  Braid_AAG
//
//  Created by Alex Frank on 2/28/18.
//

#include "Braid_Grp.hpp"

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

//inverts a braid
std::string Braid_Grp::inv(std::string braid) {
    std::string inverse = "";
    for(int i = 0; i < braid.length(); i++) {
        inverse = inverse_map[braid[i]] + inverse;
    }
    return inverse;
}

//checks to see if a given handle is valid
bool Braid_Grp::valid_handle(std::string braid) {
    ptrdiff_t index;
    ptrdiff_t elem_index = std::find(elems.begin(),elems.end(),braid[0]) - elems.begin();
    if(elem_index < elems.size()) { //if the first char of the braid is an elem and not an inverse
        index = elem_index;
    } else { //first element is an inverse
        index = std::find(inverses.begin(),inverses.end(),braid[0]) - inverses.begin();
    }
    
    if(index == 0) {
        for(int i = 1; i < braid.length(); i++) {
            if(braid[i] == elems[index] or braid[i] == inverses[index]) {
                return false;
            }
        }
    } else {
        for(int i = 1; i < braid.length(); i++) {
            if(braid[i] == elems[index] or braid[i] == inverses[index]) {
                return false;
            }
            if(braid[i] == elems[index-1] or braid[i] == inverses[index-1]) {
                return false;
            }
        }
    }
    return true;
}

//locates potential handles until a valid one is found,
//then returns the start and end points of the handle
int* Braid_Grp::loc_handle(std::string braid) {
    int* coords = new int[2] {0,0};
    for(int i = 0; i < braid.length(); i++) {
        for(int j = i+1; j < braid.length(); j++) {
            //std::cout << braid[j] << "\n";
            if(braid[j] == inverse_map[braid[i]] and valid_handle(braid.substr(i,j-i))) {
                int* recur = loc_handle(braid.substr(i+1,j-i+1));
                if(recur[0] == 0 and recur[1] == 0) {
                    coords[0] = i;
                    coords[1] = j+1;
                    return coords;
                }
            }
        }
    }
    return coords;
}

//helper function for reduce, performs a single step of the reduction algorithm
std::string Braid_Grp::reduce_handle_step(std::string braid, int start, int end) {
    //std::cout << "Reducing " << braid << "\n";
    std::string result = braid.substr(0,start);
    
    ptrdiff_t index;
    ptrdiff_t elem_index = std::find(elems.begin(),elems.end(),braid[start]) - elems.begin();
    if(elem_index < elems.size()) { //if the first char of the braid is an elem and not an inverse
        index = elem_index;
        if(index == elems.size() - 1) {
            result = result + braid.substr(start + 1,(end - 1) - (start + 1));
        } else {
            for(int i = start + 1; i < end - 1; i++) {
                if(braid[i] == elems[index + 1]) {
                    result = result + inverse_map[braid[i]] + braid[start] + braid[i];
                } else if (braid[i] == inverses[index + 1]) {
                    result = result + braid[i] + inverse_map[braid[start]] + inverse_map[braid[i]];
                } else {
                    result = result + braid[i];
                }
            }
        }
        
    } else { //first element is an inverse
        index = std::find(inverses.begin(),inverses.end(),braid[start]) - inverses.begin();
        if(index == elems.size() - 1) {
            result = result + braid.substr(start + 1,(end - 1) - (start + 1));
        } else {
            for(int i = start + 1; i < end - 1; i++) {
                if(braid[i] == elems[index + 1]) {
                    result = result + braid[i] + inverse_map[braid[start]] + inverse_map[braid[i]];
                } else if (braid[i] == inverses[index + 1]) {
                    result = result + inverse_map[braid[i]] + braid[start] + braid[i];
                } else {
                    result = result + braid[i];
                }
            }
        }
    }
    
    result = result + braid.substr(end,INT_MAX);
    return result;
}

//recursively performs dehornoy reduction algorithm
//through calls to the reduce_handle_step helper function
std::string Braid_Grp::reduce(std::string braid) {
    int* handle_loc = new int[2];
    handle_loc = loc_handle(braid);
    if(handle_loc[0] == 0 and handle_loc[1] == 0) {
        return braid;
    } else {
        return(reduce(reduce_handle_step(braid, handle_loc[0], handle_loc[1])));
    }
}

//prints the location of the first valid handle in a braid,
//or prints "Handle Free" if none are found
void Braid_Grp::print_handle(std::string braid) {
    int* handle_loc = new int[2];
    handle_loc = loc_handle(braid);
    if(handle_loc[0] == 0 and handle_loc[1] == 0) {
        std::cout << "Handle Free\n";
    } else {
        std::cout << braid.substr(handle_loc[0],handle_loc[1]-handle_loc[0]);
    }
}

//multiplies two braid elements
std::string Braid_Grp::mult(std::string b1, std::string b2) {
    return reduce(b1 + b2);
}

//compares two braids, checking for equality
bool Braid_Grp::braid_eq(std::string b1, std::string b2) {
    if( mult( b1, inv(b2) ).compare( "" ) == 0) {
        return true;
    } else {
        return false;
    }
}

//conjugates a braid by another braid
std::string Braid_Grp::conj(std::string b1, std::string b2) {
    return reduce(inv(b2) + b1 + b2);
}

//conjugates a braid by a single element
std::string Braid_Grp::conj(std::string braid, char elem) {
    return reduce(inverse_map[elem] + braid + elem);
}
