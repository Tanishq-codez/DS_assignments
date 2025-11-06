#include <iostream>
#include <queue>
#include <string>
using namespace std;

string FirstnonrepChar(string s)
{
    queue<char> q;
    int frequency[26] = {0};
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {

        char ch = s[i];

        frequency[ch - 'a']++;

        q.push(ch);

        while (!q.empty() && frequency[q.front() - 'a'] > 1)
        {
            q.pop();
        }
        if (q.empty())
        {
            ans = ans + "-1";
        }
        else
        {
            ans = ans + q.front();
        }
    }
    return ans;
}
int main()
{
    string inp = "aabc";
    string out = FirstnonrepChar(inp);
    cout << out << endl;
}