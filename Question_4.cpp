#include<iostream>
#include<string>
#include<unordered_map>
#include<cmath>
//complexity O👎
//as the inner while loop runs n times only if it is the correct substring


int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> datastore;
    int start{ 0 }, end{ 0 };
    int res{ 0 };

    while (end < s.length())
    {
        char ch_end = s[end];
        datastore[ch_end]++;

        while (datastore[ch_end] > 1) {
            char ch_start = s[start];
            datastore[ch_start]--;
            start++;
        }
        res = std::max(res, end - start + 1);
        end++;
    }
    return res;

}

int main(int argc, char const* argv[])
{
    std::string s{ "abcabcbb" };
    int res = lengthOfLongestSubstring(s);

    std::cout << res << std::endl;

    return 0;
}