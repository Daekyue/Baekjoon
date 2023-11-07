#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1)
	{
		string s;
		getline(cin, s);
		if (s == ".")
			break;
		bool check = true;
		stack <char> stck;
		for (int i = 0; i< s.length(); i++)
		{
			char c = s[i];
			if (c == '(' || c == '[')
				stck.push(c);
			else if (c == ')')
			{
				if (stck.empty() || stck.top() != '(')
				{
					check = false;
					break;
				}
				stck.pop();
			}
			else if (c == ']')
			{
				if (stck.empty() || stck.top() != '[')
				{
					check = false;
					break;
				}
				stck.pop();
			}
		}
		if (!stck.empty() || !check)
			cout << "no\n";
		else
			cout << "yes\n";
	}
}
