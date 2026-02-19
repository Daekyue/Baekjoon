#include <bits/stdc++.h>
using namespace std;

int main() {
    string word;
    cin >> word;

    vector<int> v(26, 0);

    for (int i=0; i < word.length(); i++) {
        v[word[i] - 'a']++;
    }
    
    for (int i : v)
    {
      cout << i <<' ';
    }

    return 0;
}