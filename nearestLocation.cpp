#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>> location, int num) {
    vector<pair<int,int>> arr;
    for (int i=0;i<location.size();i++) {
        int x = location[i][0];
        int y = location[i][1];
        int dis = (x*x) + (y*y);
        arr.push_back(make_pair(dis,i));
    }
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i=0;i<num;i++) {
        vector<int> tmp;
        tmp.push_back(location[arr[i].second][0]);
        tmp.push_back(location[arr[i].second][1]);
        ans.push_back(tmp);
    }
    return ans;
}

int main() {
    vector<vector<int>> location
    {
        {1, -1},
        {3, 4},
        {1, 2}
    };
    
    vector<vector<int>> ans = solve(location, 2);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }   
        cout << endl;
    }
    return 0;
}
