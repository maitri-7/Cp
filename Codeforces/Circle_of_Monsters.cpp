using namespace std;
#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <climits>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <sstream>

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
      vector<ll> a(n+10),b(n+10);

      for(ll i=0;i<n;i++){
        cin>>a[i]>>b[i];
      }

      ll ans = 0;

      ll min_support = 1e18;

      for(ll i=0;i<n;i++){
        ll next = (i+1)%n;
        ll support_from_prev = min(a[next],b[i]);
        ll extra = a[next] - support_from_prev;
        ans += extra;

        min_support = min(min_support,support_from_prev);
        //Ignoring the min_support is optimal
      }

      ans += min_support;
      cout<<ans<<endl;
} 

int main() {

    ll t;
    cin>>t;
    while(t--)
        solve();

    
    return 0;
}
