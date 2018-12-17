#include <iostream>
#include <cassert>
#include <set>
#include <string>

using namespace std;

class Solution
{
  public:
    // 暴力法，超时
    // int lengthOfLongestSubstring(string s)
    // {
    //     int n   = s.length();
    //     int ans = 0;
    //     for (int i = 0; i < n; i++)
    //         for (int j = i + 1; j <= n; j++)
    //             if (allUnique(s, i, j))
    //                 ans = max(ans, j - i);
    //     return ans;
    // }
    // bool allUnique(string s, int start, int end)
    // {
    //     set<char> set;
    //     for (int i = start; i < end; i++)
    //     {
    //         char ch = s[i];
    //         if (set.find(ch) != set.end())
    //             return false;
    //         set.insert(ch);
    //     }
    //     return true;
    // }

    // 正确解
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length(), ans = 0;
        int index[128] = {0};
        for (int j = 0, i = 0; j < n; j++)
        {
            i           = max(index[s[j]], i);
            ans         = max(ans, j - i + 1);
            index[s[j]] = j + 1;
        }
        return ans;
    }
};

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++)
    {
        char currentChar = input[i];
        if (input[i] == '\\')
        {
            char nextChar = input[i + 1];
            switch (nextChar)
            {
                case '\"': result.push_back('\"'); break;
                case '/': result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b': result.push_back('\b'); break;
                case 'f': result.push_back('\f'); break;
                case 'r': result.push_back('\r'); break;
                case 'n': result.push_back('\n'); break;
                case 't': result.push_back('\t'); break;
                default: break;
            }
            i++;
        }
        else
        {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);

        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
