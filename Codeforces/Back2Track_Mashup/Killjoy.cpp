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

const int N=2e5+5;
const long long infll = 0x3f3f3f3f3f3f3f3fLL;
int p[N];

ll modulo(int a, int b, int n){
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

ll value[1000001];
void fillNumberOfDivisorsArray(){
    for(ll i=1;i<=1000000;i++){
        for(ll j=1;i*j<=1000000;j++){
            value[i*j]++;
        }
    }
}

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

void addEdge(vector<ll> adj[],ll u,ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

ll __lcm(ll a,ll b){
    return a*b/(__gcd(a,b));
}

struct cmp {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
        return a.first < b.first;
    }
};

void solve(){
     ll n,x;
     cin>>n>>x;

     vector<ll> arr(n);
     ll cnt = 0;
     bool can = false;
     bool allequal = true;
     for(ll i=0;i<n;i++){
        cin>>arr[i];
        
        if(arr[i]!=x){
            allequal = false;
        }
        
        if(arr[i] == x){
            can = true;
        }
        cnt += (arr[i] - x);
     }

     if(cnt==0){
        can = true;
     }

     if(allequal){
        cout<<0<<endl;
     }
     else if(can){
        cout<<1<<endl;
     }
     else{
        cout<<2<<endl;
     }
}

int main() {

    FIO;
    //seiveFill();
    w(t)
        solve();

    
    return 0;
}
