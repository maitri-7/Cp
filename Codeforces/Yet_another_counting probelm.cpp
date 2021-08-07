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
 
ll __lcm(ll a,ll b){
    return a*b/(__gcd(a,b));
}
  
ll get_val(ll right,ll lc,ll b){
    ll blocks = right/lc;
    ll last_prod = blocks*lc;
    ll ans = right;
    
    if(blocks!=0){
        //excluding last block because we dont know if the last block has all b elements
        ans -= (blocks-1)*b;
        //considering last block
        ans -= min(b,right-last_prod+1);
    }
    //subtracting 1st b-1 elements
    ans -= min(right,b-1);
 
    return ans;
}
void solve(){
    ll a,b,q;
    cin>>a>>b>>q;
    // always taking b as greater element
    if(a>b){
        swap(a,b);
    }
 
    ll lc = __lcm(a,b);
 
    while(q--){ 
        ll left,right;
        cin>>left>>right;
        ll ans = get_val(right,lc,b) - get_val(left-1,lc,b);
    
        cout<<ans<<" ";
 
    }
    cout<<endl;
}
 

int main() {
    
    int t;
    cin>>t;
      while(t--)
        solve();
    
    return 0;
}
