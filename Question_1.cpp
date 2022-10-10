// Question_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
/*
here the time complexity is O(n)(n squared)
beacuae the loop runs n times and the time complexity of unordered_map.find algorithm is O(1) (constant)
*/
void solution(std::vector<int>& v, int target) {
    std::unordered_map<int, int> datastore;
    int index{ 0 };
    for (int val : v) {
        if (datastore.find(target - val) != datastore.end()) {
            std::cout << "The answer is " << val << " and " << target - val << std::endl;
        }
        datastore[val] = index;
        ++index;
    }
}

int main(int argc, char const* argv[]) {
    std::vector<int> v{ 2, 7, 11, 4,1 };
    int target = 13;
    solution(v, target);
    return 0;

}




