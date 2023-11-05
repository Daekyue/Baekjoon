#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int ans[26];
    for (int i = 0; i < 26; i++) {
        ans[i] = 0;
    }
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        ans[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        cout << ans[i] << " ";
    }
}