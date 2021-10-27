#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> area, int i, int j) {
    int rows = area.size();
    int cols = area[0].size();
    if(i>=0 && j>=0 && i<rows && j<cols && area[i][j]!=0) {
        return true;
    }
    return false;
}

int minimumDistance(vector<vector<int>> area) {
    int rows = area.size();
    int cols = area[0].size();
    bool visited[rows][cols];
    memset(visited, false, sizeof visited);
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0,0), 0));
    visited[0][0]=true;
    bool flag=false;
    int ans=-1;
    while(!q.empty()) {
        pair<pair<int, int>, int> tmp = q.front();
        q.pop();
        int x=tmp.first.first;
        int y=tmp.first.second;
        int cur_dis = tmp.second;
        visited[x][y]=true;
        if(area[x][y]==9) {
            flag=true;
            ans=tmp.second;
        }
        if(isValid(area, x+1, y) && !visited[x+1][y]) {
            q.push(make_pair(make_pair(x+1, y), cur_dis+1));
        }
        if(isValid(area, x, y+1) && !visited[x][y+1]) {
            q.push(make_pair(make_pair(x, y+1), cur_dis+1));
        }
        if(isValid(area, x-1, y) && !visited[x-1][y]) {
            q.push(make_pair(make_pair(x-1, y), cur_dis+1));
        }
        if(isValid(area, x, y-1) && !visited[x][y-1]) {
            q.push(make_pair(make_pair(x, y-1), cur_dis+1));
        }
    }
    return ans;
}
int main() {
    vector<vector<int>> area
    {
        {1, 0, 0},
        {1, 0, 0},
        {1, 9, 1}
    };
    
    cout <<minimumDistance(area)<<endl;
    return 0;
}
