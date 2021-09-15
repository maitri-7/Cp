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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

ll dp[1<<13];

ll get_min(ll mask){
    ll ans = INT_MAX;
    if(dp[mask]!=-1) return dp[mask];
    bool inside = 0;
    for(ll i=0;i<10;i++){
        ll temp = mask;

        ll val1 = (temp>>i) & 1;
        ll val2 = (temp>>(i+1)) & 1;
        ll val3 = (temp>>(i+2)) & 1;
        // cout<<val1<<" "<<val2<<" "<<val3<<endl;
        if(val1 && val2 && val3==0){
            inside = 1;
            temp = temp ^ (1<<i);
            temp = temp ^ (1<<(i+1));
            temp = temp ^ (1<<(i+2));
            dp[mask] = ans = min(ans,get_min(temp));
        }
        else if(val1==0 && val2 && val3){
            inside = 1;
            temp = temp ^ (1<<i);
            temp = temp ^ (1<<(i+1));
            temp = temp ^ (1<<(i+2));
            dp[mask] = ans = min(ans,get_min(temp));

        }
    }
    if(!inside){
        return dp[mask] = __builtin_popcount(mask);
    }
    return dp[mask] = ans;
}  
void solve(){
    string s;
    cin>>s;
    memset(dp,-1,sizeof(dp));
    vector<ll> v(s.length());
    rep(i,0,s.length()){
        v[i] = s[i]=='-' ? 0:1;
    }
    ll mul = 0;
    ll mask = 0;
    ll cnt = 0;
    for(ll i=s.length()-1;i>=0;i--){
        if(v[i]==1) {
            mask += v[i]*pow(2,mul);
            cnt++;
        }
        mul++;
    }

    ll ans = get_min(mask);

    cout<<ans<<endl;

}
  

int main() {
    FIO;
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    int t;
    cin>>t;
      while(t--)
        solve();
    
    return 0;
}
