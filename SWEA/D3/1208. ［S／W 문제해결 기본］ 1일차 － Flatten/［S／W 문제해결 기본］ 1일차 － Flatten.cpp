#include<bits/stdc++.h>

using namespace std;

int num[100];
int box[100];
int main(int argc, char** argv)
{
	int test_case;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int dump;
		cin >> dump;

		int min= 99 , max = 0;
		memset(num, 0, sizeof(num));
		memset(box, 0, sizeof(box));
		for (int i = 0; i < 100; i++)
		{
			cin >> num[i];
			box[num[i]]++;
			if (min > num[i])
				min = num[i];
			if (max < num[i])
				max = num[i];
		}
		for (int i = 0; i < dump; i++)
		{
			box[max]--;
			box[max - 1]++;
			box[min]--;
			box[min+1]++;

			if (box[max] == 0)
				max--;

			if (box[min] == 0)
				min++;
			
			if (max - min <= 1)
				break;
		}
		cout << "#" << test_case << " " << max - min <<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}