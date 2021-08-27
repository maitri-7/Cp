struct item{
    ll val;
};

struct segtree{
    ll sz;
    vector<item> seg;

    item merge(item a, item b) {
        return {a.val + b.val};
    }

    void init(int n) {
        sz = 4*n + 1;
        seg.resize(2 * sz);
    }

    item single(int v) {
        return {v};
    }

    void BuildMySeg(vector<ll>& arr,ll start,ll end,ll treenode){

        if(start==end){
            seg[treenode] = single(arr[start]);
            return;
        }
        ll mid = (start+end)/2;

        BuildMySeg(arr,start,mid,2*treenode);
        BuildMySeg(arr,mid+1,end,2*treenode + 1);

        // Example:
        // seg[4] -> seg[8] + seg[9];
        // seg[4] -> seg[2*4] + seg[2*4 + 1];

        seg[treenode] = merge(seg[2*treenode],seg[2*treenode + 1]);

    }
    void build(vector<ll> &arr){
        BuildMySeg(arr,0,arr.size()-1,1);
    }

    void UpdateMySeg(vector<ll>& arr,ll start,ll end,ll treenode,ll idx,ll value){

        if(start==end){
            arr[idx] = value;
            seg[treenode] = single(value);
            return;
        }

        ll mid = (start+end)/2;
        if(idx>mid){
            //Go Right
            UpdateMySeg(arr,mid+1,end,2*treenode + 1,idx,value);
        }
        else{
            // Go Left
            UpdateMySeg(arr,start,mid,2*treenode,idx,value);
        }

        seg[treenode] = merge(seg[2*treenode],seg[2*treenode + 1]);

    }

    void update(vector<ll>& arr,ll idx,ll val){
        UpdateMySeg(arr,0,(ll)arr.size()-1,1,idx,val);
    }

    item QueryMySeg(ll start,ll end,ll treenode,ll left,ll right){

        //Three cases
        //1. Completely outside given range
        // Return 0

        if(start>right || end<left){
            return {0};
        }

        //2. Completely inside given range
        // Return tree[treenode]

        if(start>=left && end<=right){
            return seg[treenode];
        }

        //3. Partially Inside and Partially Outside
        // Calculate for left half and right half

        ll mid = (start+end)/2;
        item leftHalfTreeAnswer = QueryMySeg(start,mid,2*treenode,left,right);
        item rightHalfTreeAnswer = QueryMySeg(mid+1,end,2*treenode + 1,left,right);

        return merge(leftHalfTreeAnswer,rightHalfTreeAnswer);

    }
    item query(vector<ll>& arr,ll l,ll r){
        return QueryMySeg(0,(ll)arr.size()-1,1,l,r);
    }


};
    
