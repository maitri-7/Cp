void prims(){
    ll n,m;
    cin>>n>>m;

    set<pair<int,int>> q;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<bool> visited(n+1);

    
    rep(i,0,m){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        adj[a].pb({c,b});
        adj[b].pb({c,a});
    }

    
    q.insert({0,0});
    ll ans = 0;

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
    cout<<ans<<endl;


  
}
