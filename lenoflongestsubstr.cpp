#include <string>
#include <iostream>

using namespace std;
    
int strfind(const string& s, int b, int e, char c)
{
    for(uint32_t i = b; i < e; ++i)
    {
        if(s[i] == c)
            return i;
    }

    return -1;
}
int lengthOfLongestSubstring(const string& s) {
    if(s.empty())
        return 0;
    uint32_t maxlen = 0;
    uint32_t i = 0, j = 1;
    for(; j < s.size();)
    {
        int index = strfind(s, i, j, s[j]);
        if(index != -1)
        {
            uint32_t len = j - i;
            if(len > maxlen)
                maxlen = len;
            i = index+1;
        }
        ++j;
    }

    return std::max(maxlen, j - i);

}
int main()
{
    std::cout << lengthOfLongestSubstring("abccb") << std::endl;

    return 0;
}