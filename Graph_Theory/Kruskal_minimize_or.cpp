#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef int ll;

#define mod 1000000007
#define inf 1e9
#define f(i,n) for(int i=0;i<n;i++)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t) ll tt;cin>>tt;while(tt--)
#define pb push_back
#define endl "\n"
#define read(arr,n) for(ll i=0;i<n;i++){cin>>arr[i];};
#define pi pair<ll,ll>
#define all(arr) arr.begin(),arr.end()


ll getPar(ll x,vector<ll>& par){

    if(par[x]==x) return x;
    
    //Path compression optimisation
    par[x] = getPar(par[x],par);

    return par[x];
}
  
//Initialize the sz with vector with 1s
void unitePar(ll x,ll y,vector<ll>& par,vector<ll>& sz){

    ll p1=getPar(x,par),p2=getPar(y,par);

    if(p1==p2){
        return;
    }

    if(sz[p1]>sz[p2]){
      par[p2]=p1;
      sz[p1] += sz[p2];
    }
    else{
      par[p1]=p2;
      sz[p2] += sz[p1];
    }
}

ll KruskalMST(vector< pair<ll,pair<ll,ll>> >& edgeList,ll vertices){

    ll ans = 0;

    sort(edgeList.begin(),edgeList.end());

    vector<ll> par(vertices+1);

    // iota(begin(par),end(par),0);
    for(ll i=1;i<=vertices;i++){
        par[i] = i;
    }

    vector<ll> sz(vertices+1,1);


    for(auto edge:edgeList){

      int w = edge.first;
      int x = edge.second.first;
      int y = edge.second.second;

      if(getPar(x,par)!=getPar(y,par)){
        unitePar(x,y,par,sz);
        ans |= w;
      }

    }

    ll p = getPar(1,par);
    ll sze = sz[p];

    if(sze==vertices){
        return ans;
    }

    return -1;
}

void solve(ll tc){

    ll vertices,edges;
    cin>>vertices>>edges;

    vector< pair<ll,pair<ll,ll>> > edgeList;

    for(ll i=0;i<edges;i++){
      ll x,y,w;
      cin>>x>>y>>w;
      edgeList.pb(make_pair(w,make_pair(x,y)));
    }

    for(ll b=30;b>=0;b--){

        vector< pair<ll,pair<ll,ll>> > tempEdgeList;

        for(auto e:edgeList){
            if(e.first&(1ll<<b)){
                continue;
            }
            tempEdgeList.pb(e);
        }

        auto ans = KruskalMST(tempEdgeList,vertices);

        if(ans!=-1){
            edgeList = tempEdgeList;
        }
    }

    cout<<KruskalMST(edgeList,vertices)<<endl;
}

int main(){

    FIO;
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    ll tt;
    cin>>tt;
    for(ll i=1;i<=tt;i++){
        solve(i);
    }    

    return 0;
}
