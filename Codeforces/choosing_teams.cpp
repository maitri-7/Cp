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


bool SeiveArray[40000];
vector<ll> PrimeNumArray;
void seiveFill(){
    memset(SeiveArray,true,sizeof(SeiveArray));
    SeiveArray[0] = SeiveArray[1] = false;
    for(ll i=2;i<40000;i++){
        if(SeiveArray[i]) PrimeNumArray.pb(i);
        for(ll j=i*2;j<40000;j+=i){
            SeiveArray[j] = false;
        }
    }
}
ll PrimeF(ll num){
    ll count = 0;
    
    for(auto n:PrimeNumArray){
        while(num%n==0){
            num = num/n;
            count++;
        }
    }
    if(num>1) count++;
    return count;
}
ll B_expo(int a, int b, int n){
    ll x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
            
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}
ll __lcm(ll a,ll b){
    return a*b/(__gcd(a,b));
}
    
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    rep(i,0,n) cin>>v[i];
    sorta(v);
    auto ub = upper_bound(all(v),5-k);
    cout<<(ub-v.begin())/3<<endl;
}
  

int main() {
    
    // int t;
    // cin>>t;
    //   while(t--)
        solve();
    
    return 0;
}
