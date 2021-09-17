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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

#define mod 1000000007
#define inf 1e9
#define f(i,n) for(int i=0;i<n;i++)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t) ll tt;cin>>tt;while(tt--)
#define pb push_back
#define endl "\n"
#define read(arr,n) for(ll i=0;i<n;i++){cin>>arr[i];};
#define pi pair<ll,ll>
#define all(arr) arr.begin(),arr.end()

template <typename T>
using ordered_set = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


void solve(ll tc){
    ll n;
    cin>>n;

    vector<ll> arr(n);

    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    stack<ll> s;
    s.push(1);

    cout<<1<<endl;

    for(ll i=1;i<n;i++){
        ll val = s.top();
        if(arr[i]==1){
            s.push(arr[i]);
        }
        else if(arr[i] == val+1){
            debug(val);
            s.pop();
            s.push(arr[i]);
        }
        else{
            while(!s.empty() && s.top() != arr[i]-1){
                s.pop();
            }
            if(!s.empty()){
                s.pop();
            }
            s.push(arr[i]);
        }

        stack<ll> temp = s;

        vector<ll> t;;

        while(!temp.empty()){
            t.pb(temp.top());
            temp.pop();
        }

        reverse(t.begin(),t.end());
        for(ll i=0;i<t.size();i++){
            if(i == t.size()-1){
                cout<<t[i];
                continue;
            }
            cout<<t[i]<<".";
        }
        cout<<endl;
        debug(t);
    }

    debug(arr);
}

int main() {

    FIO;
    //seiveFill();
    //factorialFill();
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    ll tt;
    cin>>tt;
    for(ll i=1;i<=tt;i++){
        solve(i);
    }

    return 0;
}
