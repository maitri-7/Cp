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
  
}
  

int main() {
    
    string s;
    cin>>s;
    
    ll nb,ns,nc,pb,ps,pc,rubles;
    cin>>nb>>ns>>nc>>pb>>ps>>pc>>rubles;
    ll b = count(all(s),'B');
    ll sa = count(all(s),'S');
    ll c = count(all(s),'C');
    ll ans = 0;
    ll l = 0,r = 1e15;
    while(l<r){
        ll mid = (l+r)/2;
        // cout<<mid<<endl;
        // break;
        bool b_done=true,s_done=true,c_done=true;
        ll temp = rubles;
        // bread////////////////////////
        if(nb - (mid*b) >= 0) b_done = true;
        else{
            ll b_req = abs(nb - (mid*b));
            if(b_req*pb<=temp){
                temp-=(b_req*pb);
                b_done = true;
            }
            else{
                b_done = false;
            }
        }
        //sauce///////////////
        if(ns - (mid*sa) >= 0) s_done = true;
        else{
            ll s_req = abs(ns - (mid*sa));
            if(s_req*ps<=temp){
                temp-=(s_req*ps);
                s_done = true;
            }
            else{
                s_done = false;
            }
        }
       // cheeze//////////
        if(nc - (mid*c) >= 0) c_done = true;
        else{
            ll c_req = abs(nc - (mid*c));
            if(c_req*pc<=temp){
                temp-=(c_req*pc);
                c_done = true;
            }
            else{
                c_done = false;
            }
        }

        if(c_done && s_done && b_done){
            ans = max(ans,mid);
            l = mid+1;
        }  
        else{
            r = mid;
        }
    }
    cout<<ans<<endl;    
    return 0;
}
