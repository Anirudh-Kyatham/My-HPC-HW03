#include<iostream>
#include<iomanip>
#include<unordered_map>
#include<string>
/*
here the time complexity is O(n) as filling the unordered map are O(n)
and the for loop also has time complexity O👎
Here I have used c++ standard
*/
bool isAnagram(std::string s, std::string t) {
    if (s.size() != t.size())
    {
        return false;
    }
    std::unordered_map<char, int> datastore_s, datastore_t;
    for (char ch : s)
        datastore_s[ch]++;
    for (char ch : t)
        datastore_t[ch]++;
    for (auto [ch, count] : datastore_s) {
        auto it = datastore_t.find(ch);
        if (it == datastore_t.end() || it->second != count) {
            return false;
        }
    }

    return true;
}


int main(int argc, char const* argv[]) {

    std::string s{ "anagram" };
    std::string t{ "nagaram" };
    std::cout << std::boolalpha;
    std::cout << isAnagram(s, t) << std::endl;

    return 0;
}
