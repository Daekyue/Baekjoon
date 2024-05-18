#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

unordered_map <string, int> str_to_num = {
	{"ZRO", 0}, {"ONE", 1}, {"TWO", 2}, {"THR", 3}, {"FOR", 4},
	{"FIV", 5}, {"SIX", 6}, {"SVN", 7}, {"EGT", 8}, {"NIN", 9}
};
unordered_map<int, string> num_to_str = {
	{0, "ZRO"}, {1, "ONE"}, {2, "TWO"}, {3, "THR"}, {4, "FOR"},
	{5, "FIV"}, {6, "SIX"}, {7, "SVN"}, {8, "EGT"}, {9, "NIN"}
};

string arr[10000];
int arr2[10000];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(arr2, 0, sizeof(arr2));

		string tc;
		int n;
		cin >> tc >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			arr2[i] = str_to_num[arr[i]];
		}
		sort(arr2, arr2 + n);
		for (int i = 0; i < n; i++)
		{
			arr[i] = num_to_str[arr2[i]];
		}
		cout << tc << "\n";
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}