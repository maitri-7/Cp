#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <climits>
#include <iterator>
#include <list>
#include <queue>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

//define
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define all(cont) cont.begin(), cont.end()
#define read(n) ll n;cin>>n;vector<ll> v(n);for(int i=0;i<n;i++){cin>>v[i];}
#define rep(i,s,n) for(ll i=s;i<n;i++)
#define repn(i,n,s) for(ll i=n-1;i>=s;i--)
#define print(arr,n) for(ll i=0;i<n;i++)cout<<arr[i]<<" ";
#define pi pair<int,int>
#define pb push_back
#define read_2d(n,m) ll n,m; cin>>n>>m; vector<vector<ll>> v(n,vector<ll>(m,0));for(ll i=0;i<n;i++){for(ll j=0;j<m;j++){cin>>v[i][j];}}
#define print_2d(v,n,m) for(ll i=0;i<n;i++){for(int j=0;j<m;j++){cout<<v[i][j]<<" ";}cout<<endl;}

void io(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
bool bfs(vector<int> adj[],vector<bool> &visited,int v1,int v2){
    queue<int> q;
    visited[v1]=true;
    q.push(v1);
    while(!q.empty()){
        int u = q.front();
        if(u==v2){
            cout<<"true";
            return true;
        }
        // cout<<u<<" ";
        q.pop();
        for(int ver:adj[u]){
            if(!visited[ver]){
                visited[ver]=true;
                q.push(ver);
            }
        }
    } 
    return false;
}


void MakeGraph(vector<int> adj[],int a,int b){
    adj[a].pb(b);
    adj[b].pb(a);
}
void solve(){
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];
    vector<bool> visited(v);
    rep(i,0,e){
        int a,b;
        cin>>a>>b;
        MakeGraph(adj,a,b);
    }
    int v1,v2;
    cin>>v1>>v2;
    if(!bfs(adj,visited,v1,v2)){

        cout<<"false";
    }
}  
int main(){ 
    io();
    IOS;

    solve();

    return 0;
    
}
