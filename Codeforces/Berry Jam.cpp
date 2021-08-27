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

//here the difference in the whole array is due to the right part diff + left part diff
//so we can right diff(l)+diff(r)=diff(whole array)
//now we want that diff - diff(l) - diff(r) =0
// i.e diff - diff(l) = diff(r)
// we'll find all possible difference on the right side 

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(2*n);
    map<ll,ll> mp;
    rep(i,0,2*n){
        cin>>v[i];
    }
    ll diff = 0;
    mp[0] = 0;
    //we'll iterate from n middle element 2*n-1 i.e right part
    for(ll i=n ;i <= 2*n-1; i++){
        if(v[i] == 1) diff++;
        else diff--;
        //we are storing the number of jam jars to be eaten as per current diff
        // the reason we are storing mp[diff] only once and not updating it is bcoz we want to eat min jam jars

        if(!mp.count(diff)) mp[diff] = i - (n-1);

    }
    ll ans = INT_MAX;
    ll diff_whole_array = count(v.begin(), v.end(), 1) - count(v.begin(), v.end(), 2);
    diff = 0;
    for(ll i=n-1;i>=0;i--){
        if(v[i] == 1) diff++;
        else diff--;
        if (mp.count(diff_whole_array - diff)){
            ll from_left = n-i;
            ll from_right = mp[diff_whole_array - diff];
            ans = min(ans, from_left +from_right);
        }
    }
    if (mp.count(diff_whole_array)){
        ans = min(ans, mp[diff_whole_array]);
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
