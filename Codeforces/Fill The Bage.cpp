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
    ll n,m;
    cin>>n>>m;
    vector<ll> v(100);
    ll sum = 0;
    rep(i,0,m){
        ll a;
        cin>>a;
        // cout<<a<<endl;
        sum += a;
        v[log2(a)]++;
    }
    // cout<<sum<<endl;
    if(sum < n){
        cout<<-1<<endl;
        return;
    }
    ll i = 0,ans=0;
    // ll val = 1<<i;
    // cout<<val<<endl;
    while(i<60){
        ll val = (1ll<<i);

        val = val&n;
        // cout<<val<<endl;


        if(val != 0ll){
            if(v[i]>0) {
                v[i]-=1;
            }
        
            else{
                while(i<60 && v[i]==0){
                    ans ++;
                    i++;
                }
                v[i]-=1;
                continue;
            }
        }
        v[i+1] += v[i]/2;
        i++;
    }
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
