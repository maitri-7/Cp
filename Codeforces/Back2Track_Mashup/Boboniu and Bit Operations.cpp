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

vector<ll> fact(100001);

void fillfactorial(){

    fact[0] = 1;

    fact[1] = 1;

    for(ll i =2;i<=100000;i++){
        fact[i] = (i%MOD*fact[i-1]%MOD)%MOD;
    }
}
ll B_expo(ll a, ll b, ll n){
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

ll nCr(ll n,ll r){
    
    fillfactorial();

    // Fermat Little Theorem
    // If m is prime then for integer a
    // the number pow(a,m) - a is an integral
    // multiple of m
    // So, It can be proved that
    // pow(a,m-2)%m = pow(a,-1)%m

    ll a = fact[n]%MOD;
    ll b = B_expo(fact[r],(ll)MOD-2,(ll)MOD)%MOD;
    ll c = B_expo(fact[n-r],(ll)MOD-2,(ll)MOD)%MOD;

    ll val = (a*b)%MOD;        

    return (val*c)%MOD;
}

ll __lcm(ll a,ll b){
    return a*b/(__gcd(a,b));
}
    
void solve(){
   ll n, m;
    cin>>n>>m;
    vector<ll> a(n),b(m);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<m;i++){
        cin>>b[i];
    }
 
    ll min_ans = INT_MAX;
 
    for(ll c=0;c<=513;c++){
        ll target = c;
        bool satisified = true;
        for(ll i=0;i<n;i++){
 
            bool found_pair = false;
 
            for(ll j=0;j<m;j++){
                ll cmp = a[i]&b[j];
                ll check = cmp|target;
                if(check == target){
                    found_pair = true;
                    break;
                }
            }
 
            if(found_pair==false){
                satisified = false;
                break;
            }
        }
        if(satisified){
            cout<<c<<endl;
            return;
        }
    }
}
  

int main() {
    FIO;
    // int t;
    // cin>>t;
    //   while(t--)
        solve();
    
    return 0;
}
