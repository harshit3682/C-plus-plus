#include<iostream>
#include<vector>
using namespace std;

class NumArray {
    vector<int>seg;
    int size;
public:
// function to initially construct the seg tree...
void construct_seg_tree(vector<int>&nums, vector<int>&seg, int segind ,int L, int R){
    if(L>R)return;
    if(L==R){
        seg[segind]=nums[R];
        return;
    }
    int mid=(L+R)/2;
    construct_seg_tree(nums,seg,2*segind+1,L,mid);
    construct_seg_tree(nums,seg,2*segind+2,mid+1,R);
    seg[segind]=seg[2*segind+1]+seg[2*segind+2];

}
// function to update eleemnts in it....
void update_element(vector<int>&seg,int upind, int L, int R ,int segind, int val){
    if(L>R)return;
    if(L==R){
        seg[segind]=val;
        return;
    }
    int mid=(L+R)/2;
    if(mid<upind){
        update_element(seg,upind,mid+1,R,2*segind+2,val);
    }
    else{
        update_element(seg,upind,L,mid,2*segind+1,val);

    }
    seg[segind]=seg[2*segind+1]+seg[2*segind+2];

}
// function to get sum range queries...
int sumrange_query(vector<int>&seg,int qleft, int qright, int L, int R, int segind){
    // three cases 
    // 1 case when the rnge is out of limit
    if(qleft>R||qright<L)return 0;
    // 2nd case
    // when it is completly merging
    if(qleft<=L&&qright>=R){
        return seg[segind];
    }
    // for overlapppoing case just spit the array
    int mid=(L+R)/2;
    return sumrange_query(seg,qleft,qright,L,mid,2*segind+1)+sumrange_query(seg,qleft,qright,mid+1,R,2*segind+2);

}

    NumArray(vector<int>& nums) {
        int n=nums.size();
        size=n;
        seg.resize(4*n);
       
        construct_seg_tree(nums,seg,0,0,n-1);

        
    }
    
    void update(int index, int val) {
    
        update_element(seg,index,0,size-1,0,val);
        
    }
    
    int sumRange(int left, int right) {
       return sumrange_query(seg,left,right,0,size-1,0);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 * L=Array Begin(0) , R=Array End(n-1)
 */