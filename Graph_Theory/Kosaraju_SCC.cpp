   //       ▄████▄   ▒█████  ▓█████▄ ▓█████ 
        // ▒██▀ ▀█  ▒██▒  ██▒▒██▀ ██▌▓█   ▀ 
        // ▒▓█    ▄ ▒██░  ██▒░██   █▌▒███   
        // ▒▓▓▄ ▄██▒▒██   ██░░▓█▄   ▌▒▓█  ▄ 
        // ▒ ▓███▀ ░░ ████▓▒░░▒████▓ ░▒████▒
        // ░ ░▒ ▒  ░░ ▒░▒░▒░  ▒▒▓  ▒ ░░ ▒░ ░
        //   ░  ▒     ░ ▒ ▒░  ░ ▒  ▒  ░ ░  ░
        // ░        ░ ░ ░ ▒   ░ ░  ░    ░   
        // ░ ░          ░ ░     ░       ░  ░
        // ░                  ░             

#include <iostream>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <climits>
#include <bits/stdc++.h>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds; 
//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, //tree_order_statistics_node_update>;
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
#define rep(i,s,n) for(ll i=s;i<n;i++)
#define repn(i,n,s) for(ll i=n-1;i>=s;i--)
#define print(arr,n) for(ll i=0;i<n;i++)cout<<arr[i]<<" ";
#define pi pair<int,int>
#define pb push_back
#define sorta(v) sort(v.begin(),v.end());
#define sortd(v) sort(v.begin(),v.end(),greater<int>());

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

vector<vector<ll>> vec(100001);
ll cnt=-1;

void dfs(ll curr,vector<bool>& vis,vector<ll> adj[],stack<ll> &st){
    vis[curr]=true;

    for(auto it:adj[curr]){
        if(!vis[it]){
            dfs(it,vis,adj,st);
        }
    }
    st.push(curr);
    return;
}


void dfs2(ll curr,vector<ll> rev[],vector<bool>& vis){
    vis[curr]=true;
    vec[cnt].pb(curr);

    for(auto it:rev[curr]){
        if(!vis[it]){
            dfs2(it,rev,vis);
        }
    }
}
    
void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    rep(i,0,n) cin>>v[i];

    ll m;
    cin>>m;
    vector<ll> adj[n],rev[n];

    rep(i,0,m){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].pb(b);
        rev[b].pb(a);
    }

    stack<ll> st;
    vector<bool> vis(n);
    rep(i,0,n){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }

    rep(i,0,n){
        vis[i]=false;
    }
    

    while(!st.empty()){
        ll tp=st.top();
        st.pop();

        if(!vis[tp]){
            cnt++;
            dfs2(tp,rev,vis);
        }
    } 

    
    for(ll i=0;i<cnt+1;i++){
        for(ll it=0;it<vec[i].size();it++){
            cout<<vec[i][it]<<" ";
        }
        cout<<endl;
    }
    


}
  

int main() {
    FIO;
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    // int t;
    // cin>>t;
    //   while(t--)
        solve();
    
    return 0;
}
