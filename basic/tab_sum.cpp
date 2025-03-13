#include <iostream> // for std::cout
#include <vector>  // for std::vector (dynamic array)


// sum of the elements of a tab
int tab_sum(const std::vector<int>& tab){
    // & means that tab is passed by reference and is not a copy.
    int sum = 0;
    for (int nb : tab){
        sum += nb;
    }
    return sum;
}

int main(){
    std::vector<int> tab = {2, 24,53, 398, 359};
    std::cout << "sum of the tab is " << tab_sum(tab) << std::endl;
    // std::endl is a newline character and flushes the buffer
    return 0;
}
