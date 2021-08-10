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
    string s,t;
    cin>>s>>t;
    ll j = 0;
    if(t.length()>s.length()){
        cout<<"NO"<<endl;
        return;
    }
   
    bool del = false;
 // check if the difference between the two strings is even or odd
    ll i = (s.length()-t.length())&1;
    bool first_char = false;
    string to_check = "";
    while(i<s.length() && j<t.length()){
        if(del == true){
            i++;
            del=false;
            continue;
        }
        if(s[i]==t[j]){
            to_check += s[i];
            i++;
            j++;
        } 
     // if the characters in both strings are not equal we have to skip two characters i.e we will type one character and delete the next one
        else {
            del = true;
            i++;
        }
    }
    // cout<<to_check<<endl;
    if(to_check == t){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}
  

int main() {
    
    int t;
    cin>>t;
      while(t--)
        solve();
    
    return 0;
}
