#include<bits/stdc++.h>
using namespace std;


int MST(int n, vector<vector<int>> edges)
{
    int m = edges.size();

    set<pair<int,int>> q;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<bool> visited(n+1);

    
    for(int i=0;i<m;i++){
        int a,b,c;
        a=edges[i][0];
        b=edges[i][1];
        c=edges[i][2];
        a--;
        b--;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    
    q.insert({0,0});
    int ans = 0;

    while(!q.empty()){
        auto best = *q.begin();
        q.erase(q.begin());

        if(visited[best.second]) continue;

        visited[best.second] = true;
        ans += best.first;

        for(auto e:adj[best.second]){
            if(!visited[e.second]){
                q.insert(e);
            }
        }



    }
    return ans;
    

}
