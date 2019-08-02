#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define repi(i, a, b) for(int i=(a); i>(b); i--)
#ifdef CP
  #define db(x) (cerr << #x << ": " << (x) << '\n')
#else
  #define db(x) 1
#endif
#define sync ios_base::sync_with_stdio(false), cin.tie(NULL)
#define iceil(n, x) (((n) + (x) - 1) / (x))
#define ll long long
#define gcd __gcd
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define sz size()
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vi>
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define si(a) scanf("%d", &a)
#define sll(a) scanf("%lld", &a)
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC
#define PI acos(-1.0)
#define EPS 1e-9
#define mod 1000000007
#define MOD 1000000007
#define N 500005
#define int ll
using namespace std;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;

//#define int ll
//All indexing is 0-based
/*using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
       tree_order_statistics_node_update> ordered_set;*/
//methods: find_by_order(k); & order_of_key(k);
//To make it an ordered_multiset, use pairs of (value, time_of_insertion)
//to distinguish values which are similar.

//a and b are assumed to be taken modulo p
inline int add(int a, int b, int p = mod){ int c = a + b; if(c >= p) c -= p; return c;}
inline int sub(int a, int b, int p = mod){ int c = a - b; if(c < 0) c += p; return c;}
inline int mul(int a, int b, int p = mod){ return (a * 1ll * b) % p;}

int n, q;
int a[N];
int bt[N][32], ansq[N];

struct query {
  int l, r, idx;
  bool operator < (query q) const {
    return q.l < l;
  }
};

query Q[N];

struct ans{
  //val: Value at the node in the original st
  //lazy: Value at the node in the lazy st
  int val=0, lazy=0;
};

ans st[N<<2];

ans op(ans u, ans v) {
  ans w;
  w.val = u.val + v.val;
  return w;
}

void propagate(int i,int l,int r)
{
  st[i].val += st[i].lazy * (r - l + 1);
  int lc = (i<<1) , rc = (i<<1)|1;
  if(l != r){
    st[lc].lazy += st[i].lazy,\
    st[rc].lazy += st[i].lazy;
  }
  st[i].lazy = 0;
}

void build(int i, int l, int r)
{
  //lazy[0] = n;
  if(l == r){
    st[i].val = 0;
    st[i].lazy = 0;
  }
  else{
    int lc = (i<<1) , rc = (i<<1)|1 , m = (l+r)>>1;
    build(lc, l, m);
    build(rc, m+1, r);
    st[i] = op(st[lc], st[rc]);
  }
}

void update(int ql, int qr, int x, int i, int l, int r)
{
  propagate(i, l, r);

  int m = (l + r) >> 1;
  int lc = i << 1, rc = (i << 1) | 1;

  if(ql <= l && qr >= r){
    st[i].val += x * (r - l + 1);
    if(l != r) {
      st[lc].lazy += x;
      st[rc].lazy += x;
    }
    return;
  }

  if(qr < l || ql > r)
    return;
  else{
    update(ql, qr, x, lc, l, m);
    update(ql, qr, x, rc, m+1, r);
    st[i] = op(st[lc], st[rc]);
  }
}

ans query(int ql,int qr, int i, int l, int r)
{
  propagate(i, l, r);

  if(ql <= l && qr >= r)
    return st[i];

  if(qr < l || ql > r)
    return ans();

  int m = (l + r) >> 1;
  int lc = i << 1, rc = (i << 1) | 1;

  return op(query(ql,qr,lc,l,m), query(ql,qr,rc,m+1,r));
}

void display()
{
  for(int i=0;i<n;i++)
    cerr << query(i, i, 1, 0, n-1).val <<'\n';
}

const int b = 31;

main()
{
  #ifdef CP
    freopen("/home/tarun/Desktop/input.txt", "r", stdin);
    //freopen("/home/tarun/Desktop/output.txt", "w", stdout);
  #endif
  sync;
  clock_t clk = clock();
  cerr << "I will return...\n";

  int t; cin >> t;
  while(t--) {
    cin >> n >> q;
    rep(i, 0, n) cin >> a[i];

    build(1, 0, n - 1);
    /*ft1 = Fenwick();
    ft2 = Fenwick();
    ft1.resize(n), ft2.resize(n);*/

    rep(i, 0, n) rep(j, 0, b) bt[i][j] = n;

    for(int j = 0; j < b; j++) {
      if(a[n-1] & (1 << j)) ;
      else bt[n-1][j] = n-1;
    }

    repi(i, n - 2, -1) {
      for(int j = 0; j < b; j++) {
        if(a[i] & (1 << j)) bt[i][j] = bt[i+1][j];
        else bt[i][j] = i ;
      }
    }

    int cl = n; //current index upto which we have computed the answer

    rep(i, 0, q) {
      cin >> Q[i].l >> Q[i].r;
      Q[i].l--;
      Q[i].r--;
      Q[i].idx = i;
    }

    sort(Q, Q + q);

    rep(i, 0, q) cout<<Q[i].l<<","<<Q[i].r<<"\n"; cout<<"\n";

    rep(i, 0, q) {
      int l, r, idx;
      l = Q[i].l, r = Q[i].r;
      idx = Q[i].idx;

      while(cl > l) {
        cl--; //Compute the answer for subarrays starting at cl
        int st = cl; //Start
        int currand = a[st]; //current AND
        while(st < n) {
          currand &= a[st];
          //db(cl), db(st), db(currand);
          if(currand == 0) {
            //db(cl), db(st), db(n - 1);
            //incrementRange(st, n - 1, 1);
            update(st, n - 1, 1, 1, 0, n - 1);
            /*rep(i, st, n) {
              db(i), db(RSQ(i, i));
            }*/
            break;
          }
          int ed = n;
          for(int j = 0; j < b; j++) {
            if(currand & (1 << j)) {
              ed = min(ed, bt[st][j]);
            }
          }
          int m = sqrt(currand);
          if(m * m == currand) {
            //db(cl), db(st), db(ed - 1);
            //incrementRange(st, ed - 1, 1);
            update(st, ed-1, 1, 1, 0, n - 1);
            /*rep(i, st, ed) {
              db(i), db(RSQ(i, i));
            }*/
          }
          st = ed;
        }
      }
      //ans[idx] = RSQ(l, r);
      ansq[idx] = query(l, r, 1, 0, n - 1).val;
    }
    rep(i, 0, q) cout << ansq[i] << '\n';
  }

  cerr << "...don't you ever hang your head.\n";
  cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << '\n';
}

//Compile using:
//g++ -o filename.exe --std=c++11 filename.cpp
//Use -D CP for defining a macro CP in the local environment
