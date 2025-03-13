#include <iostream> 
#include <vector>
#include <algorithm> // for std::max_element

// max of the elements of a tab
int tab_max(const std::vector<int>& tab){
    return *std::max_element(tab.begin(), tab.end());
    // max_element takes two iterators that point to the beginning and end of the tab
}

int main(){
    std::vector<int> tab = {2, 34, 353, 3, 24090, 24};
    std::cout << "max of the tab is " << tab_max(tab) << "\n";
    return 0;
}

/*
An iterator is a c++ object that allows to iterate over a container (like a vector 
or a list). 

"*" is an operator 'dereference' that allows to access the value pointed by an iterator.

auto it = tab.begin();
int value = *it; (2 here)

*/