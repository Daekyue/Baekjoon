#include<bits/stdc++.h>

using namespace std;
int head = 0;
int tail = 0;
int queueq[10001];

void push(){
  int num;
  cin >> num;
  queueq[tail++] = num;
}

void pop(){
    if (tail==head)
        cout << "-1"<< "\n";
    else
        cout << queueq[head++]<< "\n";
}

void size()
{
  cout << tail - head << "\n";
}

void empty()
{
  cout << (tail==head) << "\n";
}

void front()
{
    if(tail==head)
        cout << "-1" << "\n";
    else
        cout << queueq[head] << "\n";
}

void back()
{ 
    if(queueq[head] != 0)
        cout << queueq[tail-1] << "\n";
    else
        cout << "-1" << "\n";
}


int main(void)
{
    int num;
    cin >> num;
    string str = "";

    for (int i = 0; i < num; i++)
    {
        cin >> str;
        if(str == "push")
            push();
        else if(str == "pop")
            pop();
        else if(str == "size")
            size();
        else if(str == "empty")
            empty();
        else if(str == "front")
            front();
        else if(str == "back")
            back();
    }
}