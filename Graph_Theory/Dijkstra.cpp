vector<int> shortestPath(vector<vector<int>> roads,int n)
{
    vector<pair<int,int>> adj(n+1);//weight,node;
    set<pair<int,int>> s;
    vector<int> dist(n+1,INT_MAX);

    for(int i=0;i<roads.size();i++){
        int a,b,c;
        a=roads[i][0];
        b=roads[i][1];
        c=roads[i][2];
        a--;
        b--;

        adj[a].push_back({c,b});
        adj[b].push_back({c,a});


    }

    s.insert({0,0});
    while(!s.empty()){
        auto best = s.begin();
        int node = best.second;
        int till_now = best.first;
        s.erase(*s.begin());

        for(auto nbr:adj[best.second]){
            if(nbr.second + till_now < dist[nbr]){
                if(s.count({dist[nbr],nbr})){
                    s.erase({dist[nbr],nbr});
                }
                dist[nbr] = nbr.second + till_now ;
                s.insert({dist[nbr],nbr});
            }
        }
    }
    vector<int> ans;
    for(int i=1;i<n;i++){
        ans.push_back(dist[nbr]);
    }
    return ans;


}
    
