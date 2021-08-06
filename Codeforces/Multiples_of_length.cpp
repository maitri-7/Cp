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
 
void io(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

    
void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    if(n==1){
        cout<<"1 1"<<endl<<"0 "<<endl<<"1 1"<<endl<<"0 "<<endl<<"1 1"<<endl<<-v[0]<<endl;
        return;
    }
    // making 1st element 0
    cout<<"1 1"<<endl;
    cout<<-v[0]<<endl;
    v[0] = 0;
    cout<<"2 "<<n<<endl;
    ll len = n-1;
    rep(i,1,n){
        // we have to make all other elements multiple of n so at that last step 
        // we can add a multiple of n and everything becomes 0. At the same time for
        // 2nd step we  should add multiple of n-1 since for 2nd step we are choosing 
        // a length of n-1
        ll temp = v[i]%n; 
        ll multiple_of_n_1 = temp*len;
        v[i] += multiple_of_n_1;
        cout<<multiple_of_n_1<<" ";


    }
    cout<<endl;
    cout<<"1 "<<n<<endl;
    rep(i,0,n){
        cout<<-v[i]<<" ";
    }
}
  

int main() {
    
   
     solve();
    
    return 0;
}
