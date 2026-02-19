#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    bool stchar = true; 
        
    for (char &c : s)
    {
        if (c == ' ')
        {
            stchar = true;
            continue;
        }
        if(stchar && c >= 'a' && c <= 'z')
            c -= 'a' - 'A';
        else if(!stchar && c >= 'A' && c <= 'Z')
            c += 'a' - 'A';
        stchar = false;
    }
    return s;
}