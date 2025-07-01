// You’re given an array A of n integers and q queries.
// Each query can be one of the following two types:
// • Type 1 Query: (1, l, r) - Replace A[i] with 
// (i-l+1)*A[l] for each index i, where l <= i <= r.

// • Type 2 Query: (2, l, r) - Calculate the sum of the 
// elements in A from index l to index r.

// Find the sum of answers to all type 2 queries. Since 
// answer can be large, return it modulo 109+7.

// Sample Input 1

// 7

// 1
// 4
// 5
// 1
// 6
// 7
// 8

// 5
// 1 1 6
// 1 1 5
// 2 5 5
// 2 3 4
// 2 3 3

// Sample Output 1
// 60

// Sample Output Description 1
// Here, n = 7
// A = [1, 4, 5, 1, 6, 7, 8]

// q = 5
// queries = [[1, 1, 6], [1, 1, 5], [2, 5, 5], [2, 3, 4], [2, 3, 3]]

// for query 1 -> (1, 1, 6)
// Applying the operation on subarray from index 1 to 6,
// A becomes, A = [1, 4, 8, 12, 16, 20, 24]

// for query 2 -> (1, 1, 5)
// Applying the operation on subarray from index 1 to 5,
//  A becomes, A = [1, 4, 8, 12, 16, 20, 24]

// for query 3 -> (2, 5, 5)
// calculate sum of array from index 5 to 5 -> sum = 
// A[5] = 20

// for query 4 -> (2, 3, 4)
// calculate sum of array from index 3 to 4 -> sum = 
// A[3]+A[4] = 28

// for query 5 -> (2, 3, 3)
// calculate sum of array from index 3 to 3 -> sum = 
// A[3] = 12
// Hence, answer is 20+28+12 = 60

#include <iostream>
#include<vector>
#include<tuple>
using namespace std;

const long long MOD = 1'000'000'007LL;
const long long INV2 = 500000004LL;          // inverse of 2 mod MOD

long long add(long long a, long long b) { return (a += b) >= MOD ? a-MOD : a; }
long long mul(long long a, long long b) { return (a * 1LL * b) % MOD; }

long long sum_n(long long n) {               // 1+2+…+n mod MOD
    if (n <= 0) return 0;
    return mul(mul(n % MOD, (n + 1) % MOD), INV2);
}

struct Node {
    long long sum = 0;
    int  lazy_l = 0;
    long long lazy_val = 0;
    bool lazy_flag = false;
};

struct SegmentTree {
    int n;
    vector<Node> tr;
    const vector<long long>& A;

    SegmentTree(const vector<long long>& arr) : n((int)arr.size() - 1), tr(4*n), A(arr) {
        build(1, 1, n);
    }
    void build(int v,int l,int r){
        if(l==r){ tr[v].sum = A[l] % MOD; return; }
        int m=(l+r)>>1;
        build(v<<1,l,m); build(v<<1|1,m+1,r);
        tr[v].sum = add(tr[v<<1].sum, tr[v<<1|1].sum);
    }

    void apply(int v,int l,int r,int ql,long long val){
        long long len = r-l+1;
        long long k_start = l - ql + 1;
        long long k_end   = r - ql + 1;
        long long sum_k = add(sum_n(k_end), MOD - sum_n(k_start-1));
        tr[v].sum = mul(val, sum_k);
        tr[v].lazy_flag = true;
        tr[v].lazy_l = ql;
        tr[v].lazy_val = val;
    }
    void push(int v,int l,int r){
        if(!tr[v].lazy_flag || l==r) return;
        int m=(l+r)>>1;
        apply(v<<1,     l, m, tr[v].lazy_l, tr[v].lazy_val);
        apply(v<<1|1, m+1, r, tr[v].lazy_l, tr[v].lazy_val);
        tr[v].lazy_flag = false;
    }

    void update(int v,int l,int r,int ql,int qr,int ref_l,long long val){
        if(qr < l || r < ql) return;
        if(ql<=l && r<=qr){ apply(v,l,r,ref_l,val); return; }
        push(v,l,r);
        int m=(l+r)>>1;
        update(v<<1,l,m,ql,qr,ref_l,val);
        update(v<<1|1,m+1,r,ql,qr,ref_l,val);
        tr[v].sum = add(tr[v<<1].sum, tr[v<<1|1].sum);
    }
    long long query(int v,int l,int r,int ql,int qr){
        if(qr < l || r < ql) return 0;
        if(ql<=l && r<=qr)   return tr[v].sum;
        push(v,l,r);
        int m=(l+r)>>1;
        return add(query(v<<1,l,m,ql,qr), query(v<<1|1,m+1,r,ql,qr));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;  cin >> n;
    vector<long long> A(n + 1);
    for (int i = 1; i <= n; ++i) { cin >> A[i]; A[i] %= MOD; }

    int q;  cin >> q;

    SegmentTree st(A);
    long long total = 0;

    for (int i = 0; i < q; ++i) {
        int type, l, r;
        cin >> type >> l >> r;
        ++l,++r;
        if (type == 1){
            long long base = st.query(1, 1, n, l, l);
            st.update(1, 1, n, l, r, l, base);
        }
            
        else
            total = add(total, st.query(1, 1, n, l, r));
    }
    cout << total << '\n';
}


// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n; cin>>n;
//     vector<long long> A(n+1);
//     for(int i=1;i<=n;++i){ cin>>A[i]; A[i]%=MOD; }

//     int q; cin>>q;
//     vector<tuple<int,int,int>> queries(q);
//     for(auto& t:queries){
//         int type,l,r; cin>>type>>l>>r;
//         t = {type,l,r};
//     }

//     SegmentTree st(A);
//     long long total = 0;
//     for(auto [type,l,r]:queries){
//         if(type==1) st.update(1,1,n,l,r,l,A[l]);
//         else        total = add(total, st.query(1,1,n,l,r));
//     }
//     cout<<total<<"\n";
//     return 0;
// }