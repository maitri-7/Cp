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

ll __lcm(ll a,ll b){
    return a*b/(__gcd(a,b));
}
    
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> dp(n+1);
    // dp[0] = 0;
    dp[1] = 1;
    // dp[2] = 2;
    ll sum = 1;
  //consider the number 11
  // now in the question we can divide the number with any values between 2 to 11
  //2  3  4  5  6  7  8  9  10  11----> i 
  //5  3  2  2  1  1  1  1  1    1 ---> quotient when divided by i
  // now we have to count how many times these number will appear and as they will always occur in pair
  // i.e 11/2=5 and as we can see 5 appears only once while iterating through the repeated elements we have to add the number i,e its pair once
  
    for(ll i=2;i<=n;i++){
        dp[i] = sum;
        for(ll j=1;j*j<=i;j++){
            dp[i] = dp[i] + (dp[j]%m*((i/j)-(i/(j+1)))%m)%m;
            dp[i] = dp[i]%m;
            if(j!=i/j && j>1){
                dp[i] = dp[i] + dp[i/j];
                dp[i] = dp[i]%m;
            }
        }
        sum += dp[i]%m;
    }
    cout<<dp[n]<<endl;


}
  

int main() {
    FIO;
    // int t;
    // cin>>t;
    //   while(t--)
        solve();
    
    return 0;
}
