#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <climits>
#include <iterator>
#include <list>
#include <bits/stdc++.h>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
    // <!-- ordered_set<int>  s;
    // s.insert(1); 
    // s.insert(3);
    // cout << s.order_of_key(2) << endl; // the number of elements in the s less than 2
    // cout << *s.find_by_order(0) << endl; // print the 0-th smallest number in s(0-based) -->
//define
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
#define sorta(v) sort(v.begin(),v.end());
#define sortd(v) sort(v.begin(),v.end(),greater<int>());


set<char> se;

bool has_cycle(set<ll> adj[],vector<bool>& visited,ll curr,ll parent){
    visited[curr] = true;
    for(auto u:adj[curr]){
        if(visited[u] && u!=parent) {
            // cout<<curr<<" "<<u<<" "<<parent<<endl;
            return true;
        }
        if(!visited[u]){
            return has_cycle(adj,visited,u,curr);
        }
    }
    return false;

}

void dfs(set<ll> adj[],vector<bool>& visited,ll curr,string& ans){
    se.insert((char)curr+'a');
    visited[curr] = true;
    ans += (char) curr+'a';
    for(auto u:adj[curr]){
        if(!visited[u]){
            dfs(adj,visited,u,ans);
        }
    }
}

void solve(){
    string s;
    cin>>s;
    ll n = s.length();
    set<ll> adj[30];
 
    if(n==1){
        cout<<"YES"<<endl;
        for(char c='a';c<='z';c++){
            cout<<c;
        }
        cout<<endl;
        return;
    }
    for(ll i=0;i<n-1;i++){
        adj[s[i]-'a'].insert(s[i+1]-'a');
        adj[s[i+1]-'a'].insert(s[i]-'a');
        if((adj[s[i]-'a'].size()>2) || (adj[s[i+1]-'a'].size()>2)){
            cout<<"NO"<<endl;
            return;
        }
    } 

    vector<bool> visited(30,false);
    if(has_cycle(adj,visited,s[0]-'a',-1)){
        cout<<"NO"<<endl;
        return;
    }
    visited = vector<bool> (30,false);
    string ans = "";
    for(ll i=0;i<26;i++){
        if(adj[i].size()==1){
            se = set<char> ();
            dfs(adj,visited,i,ans);
            break;
        }
    }
    for(char i='a';i<='z';i++){
        if(se.find(i)==se.end()) ans += i;
    }
    cout<<"YES"<<endl;
    cout<<ans<<endl;

}
  

int main() {
    FIO;
    int t;
    cin>>t;
      while(t--)
        solve();
    
    return 0;
}
