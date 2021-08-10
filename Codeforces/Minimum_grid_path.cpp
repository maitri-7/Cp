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
#define sorta(v) sort(v.begin(),v.end());
#define sortd(v) sort(v.begin(),v.end(),greater<int>());


void solve(){
    //Approach: We are considering the minimum element that we can take
    //so that the answer is minimum. It doesnt matter whatever is the first direction i.e 
    //right or up bcoz we have to cover same distance both ways.
    //here we'll consider taking every element as the min element and cover rest of the distance 
    //taking into consideration this particular element
    ll n;
    cin>>n;
    vector<ll> v(n);
    rep(i,0,n) cin>>v[i]; 
    multiset<ll> up,right;
    ll prev=0,ans=LLONG_MAX;
    rep(i,0,n){
        if(i%2==0) up.insert(v[i]);
        else right.insert(v[i]);
        prev += v[i]; // keeps prefix sum
        if(i){
            ll up_min = *up.begin();
            ll right_min = *right.begin();
            // cout<<prev<<" "<<(n-up.size())*(up_min)<<" "<<(n-right.size()*(right_min))<<endl;
            ans = min(ans,prev + ((n-up.size())*(up_min)) + ((n-right.size())*(right_min)));

        }
    }
    cout<<ans<<endl;
}
  

int main() {
    
    int t;
    cin>>t;
      while(t--)
        solve();
    
    return 0;
}
