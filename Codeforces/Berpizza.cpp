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

struct func{
    bool operator()(pair<int,int> p1,pair<int,int> p2){
        return p1.first>p2.first;
       
    }
   
};

void solve(){
    ll q;
    cin>>q;
    multiset<pair<int,int>,func> s1; // money,i
    multiset<pair<int,int>> s2; //i,money
    int i=1;
    while(q--){
        int a;
        cin>>a;
        if(a==1){
            int b;
            cin>>b;
            s1.insert({b,i});
            s2.insert({i,b});
            i++;
        }
        if(a==2){
            auto it = s2.begin();
            cout<<it->first<<" ";
            s2.erase(s2.begin());
            s1.erase({it->second,it->first});
        }
        if(a==3){
            auto it = s1.begin();
            cout<<it->second<<" ";
            s1.erase(s1.begin());
            s2.erase({it->second,it->first});
        }


    }
}
  

int main() {
    solve();
    return 0;
}
