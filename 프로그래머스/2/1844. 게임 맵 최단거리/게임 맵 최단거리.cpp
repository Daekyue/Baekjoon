#include<bits/stdc++.h>
#include<utility>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    int answer = 0;
    vector<vector<int>> visit(n, vector<int>(m, 0));
    
    queue<pair<int, int> > q;
    q.push({0,0});
    visit[0][0] = 1;
    
    
    
    while(!q.empty())
    {
        pair<int,int> current = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(visit[nx][ny] || maps[nx][ny] != 1)
                continue;
            q.push({nx, ny});
            visit[nx][ny] = visit[current.first][current.second] + 1;
        }
    }
    if(visit[n-1][m-1])
        answer = visit[n-1][m-1];
    else
        answer = -1;
    return answer;
}