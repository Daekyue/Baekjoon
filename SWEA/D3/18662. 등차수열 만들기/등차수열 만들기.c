#include <stdio.h>
int main(void)
{
	int test_case;
	int T;
    int input_num;
    int count;
    float a, b, c;
    float x;

	setbuf(stdout, NULL);
	scanf("%d", &T);
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
        x = 0.0;
        scanf("%f", &a);
        scanf("%f", &b);
        scanf("%f", &c);
        if ((b - a) != (c - b))
        {
            if ((b - a) > (c - b))
            {
                x = b - ((c + a) / 2);
            }
            else
            {
                x = ((c + a) / 2) - b;
            }
        }
        printf("#%d %.1f\n", test_case, x);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}