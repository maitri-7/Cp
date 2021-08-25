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

    
void solve(){
    ll a,b;
    cin>>a>>b;
    set<ll> ans;
    ll c1 =  (a+b)/2;
    ll c2 = (a+b) - c1;
    //here alice has to win a times and bob has to win b times
    //so first we'll assume alice will serve c1 times and then
    // alice will serve c2 times(if we satisdy wins for anyone player the other will be automatically satisfied)
    // we'll run a loop from 0 to min(a,c1) and we'll assume that alice wins i times
    //while iterating. since alice was serving and if she wins/hold a times
    //that means during c2-i serves alice will lose in her service which will be a break for bob
    // and since alice has to win a times bob has to lose b-i times

    for(ll i=0;i<=min(a,c1);i++){
        if(a-i <= c2){
            ll bob_breaks = a-i;
            ll alice_breaks = c1 - i;
            ans.insert(bob_breaks+alice_breaks);
        }
    }
    for(ll i=0;i<=min(a,c2);i++){
        if(a-i <= c1){
            ll bob_breaks = a-i;
            ll alice_breaks = c2 - i;
            ans.insert(bob_breaks+alice_breaks);
        }
    }
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}
  

int main() {
    FIO;
    int t;
    cin>>t;
      while(t--)
        solve();
    
    return 0;
}
