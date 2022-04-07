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
#define mod 1000000007
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
        fact[i] = (i%mod*fact[i-1]%mod)%mod;
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

    ll a = fact[n]%mod;
    ll b = B_expo(fact[r],(ll)mod-2,(ll)mod)%mod;
    ll c = B_expo(fact[n-r],(ll)mod-2,(ll)mod)%mod;

    ll val = (a*b)%mod;        

    return (val*c)%mod;
}

ll __lcm(ll a,ll b){
    return a*b/(__gcd(a,b));
}
    
struct TrieNode{
    struct TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for(ll i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};

TrieNode *root;
bool searchString(string str){
    TrieNode *curr = root;
    ll n = str.length();
    for(ll i=0;i<n;i++){
        int idx = str[i] - 'a';
        if(curr->child[idx]==NULL){
            return false;
        }
        curr = curr->child[idx];
    }
    return curr->isEnd;
}

void insertString(string str){
    TrieNode *curr = root;
    ll n = str.length();
    for(ll i=0;i<n;i++){
        int idx = str[i] - 'a';
        if(curr->child[idx] == NULL){
            curr->child[idx] = new TrieNode();
        }
        curr = curr->child[idx];
    }
    curr->isEnd = true;
}

void solve(){
    string str;
    cin>>str;

    ll n;
    cin>>n;

    root = new TrieNode();

    for(ll i=0;i<n;i++){
        string st;
        cin>>st;
        insertString(st);
    }

    ll len = str.length();


    vector<int> dp(len+1);
    //Ways to make complete string from i to n


    dp[len] = 1;


    for(ll i=len-1;i>=0;i--){
        TrieNode *test = root;
        for(ll j=i;j<len;j++){
            ll idx = str[j] - 'a';
            if(test->child[idx] == NULL){
                break;
            }
            test = test->child[idx];
            if(test->isEnd){
                dp[i] = dp[i]%mod + dp[j+1]%mod;
                dp[i] = dp[i]%mod;
            }
        }
    }
    cout<<dp[0]<<endl;
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    auto start1 = high_resolution_clock::now();

    // int t;
    // cin>>t;
    //   while(t--)
        solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);

    debug(duration.count()/1000);
    
    return 0;
}
