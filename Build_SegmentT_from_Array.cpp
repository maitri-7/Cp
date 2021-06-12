#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <climits>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include<unordered_map>
#include <unordered_set>
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
void BuildTree(vector<ll>& v,int* tree,int start,int end,int treeNode){
    if(start==end){
        tree[treeNode] = v[start];
        return;
    }
    int mid=(start+end)/2;
    BuildTree(v,tree,start,mid,2*treeNode);
    BuildTree(v,tree,mid+1,end,(2*treeNode)+1);
    tree[treeNode]=tree[2*treeNode]+tree[(2*treeNode)+1];

}
void solve(){
    read(n);
    int* tree=new int[2*n];
    BuildTree(v,tree,0,n-1,1);
    for(int i=1;i<2*n;i++){
        cout<<tree[i]<<" ";
    }
}  
int main(){ 
    io();
    IOS;
    solve();
    return 0;
    
}