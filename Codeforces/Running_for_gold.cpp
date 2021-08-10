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
    ll n;
    cin>>n;
    vector<vector<ll>> v(n,vector<ll> (5));
    rep(i,0,n){
        rep(j,0,5)
            cin>>v[i][j];
    }
  // we'll consider that the 1st player will be the winner
    ll max_till_now = 0;
    rep(i,1,n){
        ll cnt=0;
        rep(j,0,5){
            if(v[max_till_now][j] > v[i][j]) cnt++;

        }
      // if we find someone better we'll consider that particular player to be the winner
        if(cnt>=3){
            max_till_now = i;
        }
    }
  // now we'll check for the possibility that max_till_now is actually the winner
    rep(i,0,n){
        ll cnt=0;
        rep(j,0,5){
            if(max_till_now != i){
                if(v[max_till_now][j] > v[i][j]) cnt++;
            }
        }
        if(cnt>=3){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<max_till_now+1<<endl;
}
  

int main() {
    
    int t;
    cin>>t;
      while(t--)
        solve();
    
    return 0;
}
