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
int dp[6][100005];
ll get_max(vector<ll> &v,ll k,ll z,ll curr){
    if(k==0) return 0;
    if(curr<0 || curr>=v.size()) return 0;
    if(dp[z][curr] != -1) return dp[z][curr];
    ll res = 0;
    // we have two options taking next/ previous element
    // taking the next element
    if(curr<v.size()-1){
        res = max(res,v[curr+1] + get_max(v,k-1,z,curr+1));
    }
    // taking the previous element
    if(curr>0 && z!=0){
        res = max(res,v[curr-1] + get_max(v,k-1,z-1,curr-1));
    }
 
    return dp[z][curr] = res;
}
   
void solve(){
    ll n,k,z;
    cin>>n>>k>>z;
    vector<ll> v(n);
    memset(dp,-1,sizeof(dp));
    rep(i,0,n) cin>>v[i];
    cout<<get_max(v,k,z,0)+v[0]<<endl;
}
  

int main() {
    
    int t;
    cin>>t;
      while(t--)
        solve();
    
    return 0;
}
