/*A가 B보다 큰 경우에는 '>'를 출력한다.
A가 B보다 작은 경우에는 '<'를 출력한다.
A와 B가 같은 경우에는 '=='를 출력한다.*/
#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    
    if(a > b)
        cout << ">";
    else if (a < b)
        cout << "<";
    else
        cout << "==";
}
