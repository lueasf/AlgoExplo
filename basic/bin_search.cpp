#include <iostream>
#include <vector>


// binary search in a sorted array (famous algorithm)
// O(log(n)) time complexity
// O(1) space complexity
// return the index of the target if found, -1 otherwise
int bin_search(const std::vector<int>& tab, int cible){
    int left = 0;
    int right = tab.size() - 1;

    while (left <= right){
        int mid = left + (right - left) / 2; // avoid overflow
        if (tab[mid] == cible){
            return mid;
        } else if (tab[mid] < cible){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    std::vector<int> tab = {1, 3, 4, 7, 9, 32, 234, 249, 2322, 9433, 10100};
    std::cout << bin_search(tab, 32) << std::endl;
    return 0; // return 5
}