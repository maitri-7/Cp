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
void BuildTree(vector<ll>& v,vector<ll>& tree,int start,int end,int treeNode){
    if(start==end){
        tree[treeNode] = v[start];
        return;
    }
    int mid=(start+end)/2;

    BuildTree(v,tree,start,mid,2*treeNode);//left subtree
    BuildTree(v,tree,mid+1,end,(2*treeNode)+1);//right subtree
    tree[treeNode]=tree[2*treeNode]+tree[(2*treeNode)+1];//main_node

}
void UpdateTree(vector<ll>& v,vector<ll>& tree,int start,int end,int treeNode,int index,int value){
    if(start==end){
        v[index] = value;
        tree[treeNode] = value; 
        return;
    }
    int mid=(start+end)/2;
    if(index<mid)//i.e the index to be updated lies on the left sub-tree
        UpdateTree(v,tree,start,mid,2*treeNode,index,value);//left subtree
    else
        UpdateTree(v,tree,mid+1,end,(2*treeNode)+1,index,value);//right subtree
    tree[treeNode]=tree[2*treeNode]+tree[(2*treeNode)+1];//main_node

}

ll query(vector<ll> &tree,int start,int end,int treeNode,int left,int right){
    if(start>right || end<left)//completely outside the req. range
        return 0;
    if(start>=left && end<=right)//completely inside the req. range
        return tree[treeNode];
    //Partially inside and partially outside
    int mid=(start+end)/2;
    ll ans1=query(tree,start,mid,treeNode*2,left,right);
    ll ans2=query(tree,mid+1,end,treeNode*2+1,left,right);
    return ans1+ans2;
}
void solve(){
    read(n);//reading array
    vector<ll> tree(2*n);//segment tree
    BuildTree(v,tree,0,n-1,1);
    int update_index,update_value;
    cin>>update_index>>update_value;
    UpdateTree(v,tree,0,n-1,1,update_index,update_value);

    int ans=query(tree,0,n-1,1,1,5);//get ans for a particular query
    cout<<ans<<endl;
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
