
    
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
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;


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
    

struct item {
    vector<int> val;
};

struct segtree{
    int sze;
    vector<item> seg;

    item merge(item a, item b) {
        vector<int> v3;
        auto v1 = a.val;
        auto v2 = b.val;
        int i = 0;
        int j = 0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]<=v2[j]){
                v3.pb(v1[i]);
                i++;
            }   
            else{
                v3.pb(v2[j]);
                j++;
            }
        }
        while(i<v1.size()){
            v3.pb(v1[i]);
            i++;
        }
        while(j<v2.size()){
            v3.pb(v2[j]);
            j++;
        }
        return {v3};
    }

    item single(int v){
        return {{v}};
    }

    void init(int n) {
        seg.resize(5*n);
    }

    void BuildMySeg(vector<int>& arr,int start,int end,int treenode){

        if(start==end){
            seg[treenode] = single(arr[start]);
            return;
        }
        int mid = (start+end)/2;
        BuildMySeg(arr,start,mid,2*treenode);
        BuildMySeg(arr,mid+1,end,2*treenode + 1);
        seg[treenode] = merge(seg[2*treenode],seg[2*treenode + 1]);
    }

    void build(vector<int>& arr){
        BuildMySeg(arr,0,(int)arr.size()-1,1);
    }

    int QueryMySeg(int start,int end,int treenode,int left,int right,int k){
        if(start>right || end<left){
            return 0;
        }

        if(start>=left && end<=right){
            int count = upper_bound(seg[treenode].val.begin(),seg[treenode].val.end(),k-1) - seg[treenode].val.begin(); 
            return count;
        }

        int mid = (start+end)/2;
        int leftHalfTreeAnswer = QueryMySeg(start,mid,2*treenode,left,right,k);
        int rightHalfTreeAnswer = QueryMySeg(mid+1,end,2*treenode + 1,left,right,k);

        return leftHalfTreeAnswer+rightHalfTreeAnswer;
    }

    int query(vector<int>& arr,int left,int right,int k){
        return QueryMySeg(0,(int)arr.size()-1,1,left,right,k);
    }
};

vector<int> euler;
vector<int> in,out,val,vis;
int t;

void dfs(int curr,int par,vector<vector<int>>& adj){
    euler.pb(val[curr-1]);
    in[curr] = t++;
    vis[curr] = true;
    for(auto el:adj[curr]){
        if(el!=par){
            dfs(el,curr,adj);
        }
    }
    euler.pb(val[curr-1]);
    out[curr] = t++;    
}

void solve(){
    int n;
    cin>>n;

    t = 0;

    val.clear();
    vis.clear();
    in.clear();
    out.clear();
    euler.clear();

    val.resize(n);
    vis.resize(n+1);
    in.resize(n+1);
    out.resize(n+1);

    for(int i=0;i<n;i++){
        cin>>val[i];
    }


    vector<vector<int>> adj(n+1);

    int edges = n-1;
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }   

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,-1,adj);
        }
    }
    
    segtree seg;
    seg.init(euler.size());
    seg.build(euler);    

    int q;
    cin>>q;

    while(q--){
        int node,k;
        cin>>node>>k;
        int val = seg.query(euler,in[node],out[node],k);
        val = val/2;
        int rem = t - (out[node]-in[node]+1);
        int smainterThanK = 0;
        if(in[node]-1 >= 0){
            smainterThanK += seg.query(euler,0,in[node]-1,k);
        }
        if(out[node]+1 <= t-1){
            smainterThanK += seg.query(euler,out[node]+1,t-1,k);  
        }
        int available = rem - smainterThanK;
        available = available/2;

        if(available<val){
            cout<<-1<<endl;
            continue;
        }
        cout<<val<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    auto start1 = high_resolution_clock::now();

    int t;
    cin>>t;
      while(t--)
        solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);

    debug(duration.count()/1000);
    
    return 0;
}

