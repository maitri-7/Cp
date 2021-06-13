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
struct node{
    ll maxi;//maximum
    ll smaxi;//second_maximum
};

void BuildTree(vector<ll> &v,vector<node>& tree,int start,int end,int treeNode){
    if(start==end){
        tree[treeNode].maxi = v[start];
        tree[treeNode].smaxi = 0;
        return;
    }
    int mid=(start+end)/2;
    BuildTree(v,tree,start,mid,2*treeNode);//LeftTree
    BuildTree(v,tree,mid+1,end,2*treeNode+1);//RightTree

    tree[treeNode].maxi=max(tree[2*treeNode].maxi,tree[2*treeNode+1].maxi);
    tree[treeNode].smaxi=min(max(tree[2*treeNode].maxi,tree[2*treeNode+1].smaxi),
                             max(tree[2*treeNode].smaxi,tree[2*treeNode+1].maxi));

}
void UpdateTree(vector<ll> &v,vector<node>& tree,int start,int end,int idx,int val,int treeNode){
    if(start==end){
        // cout<<idx<<endl;
        v[idx] = val;
        tree[treeNode].maxi = val;
        return;
    }
    int mid=(start+end)/2;
    if(idx<=mid)
        UpdateTree(v,tree,start,mid,idx,val,2*treeNode);//LeftTree
    else
        UpdateTree(v,tree,mid+1,end,idx,val,2*treeNode+1);//RightTree

    tree[treeNode].maxi=max(tree[2*treeNode].maxi,tree[2*treeNode+1].maxi);
    tree[treeNode].smaxi=min(max(tree[2*treeNode].maxi,tree[2*treeNode+1].smaxi),
                            max(tree[2*treeNode].smaxi,tree[2*treeNode+1].maxi));

}


node query(vector<ll> &v,vector<node>& tree,int start,int end,int left,int right,int treeNode){
    if(start>right || end<left){
        return {0,0};
    }
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    int mid=(start+end)/2;
    node l = query(v,tree,start,mid,left,right,2*treeNode);//LeftTree
    node r = query(v,tree,mid+1,end,left,right,2*treeNode+1);//RightTree
    node ans;
    ans.maxi = max(l.maxi,r.maxi);
    ans.smaxi = min(max(l.maxi,r.smaxi),
                max(l.smaxi,r.maxi));
    return ans;

}


void solve(){
    read(n);
    vector<node> tree(3*n+1);
    BuildTree(v,tree,0,n-1,1);
    int q;
    cin>>q;
    while(q--){
        char act;
        int l,r;
        cin>>act>>l>>r;
        if(act=='Q'){
            node ans=query(v,tree,0,n-1,l-1,r-1,1);
            cout<<ans.maxi+ans.smaxi<<endl;
        }
        if(act=='U'){
            int idx=l;
            int val=r;
            UpdateTree(v,tree,0,n-1,idx-1,val,1);
            // rep(i,0,3*n)cout<<tree[i].maxi<<" "<<tree[i].smaxi<<endl;
        }
    }

}  
int main(){ 
    io();
    IOS;
    solve();
    return 0;
    
}
