#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 1000001
#define MAX 1000001

ll factor[MAX] = { 0 };
ll D[MAX];

void generatePrimeFactors()
{
    factor[1] = 1;

    for (ll i = 2; i < MAX; i++)
        factor[i] = i;

    for (ll i = 4; i < MAX; i += 2)
        factor[i] = 2;

    for (ll i = 3; i * i < MAX; i++)
    {
        if (factor[i] == i)
        {
            for (ll j = i * i; j < MAX; j += i)
            {
                if (factor[j] == j)
                    factor[j] = i;
            }
        }
    }
}

ll calculateNoOFactors(ll n)
{
    if (n == 1)
        return 1;

    ll ans = 1;

    ll dup = factor[n];

    ll c = 1;

    ll j = n / factor[n];

    while (j != 1)
    {
        if (factor[j] == dup)
            c += 1;

        else
        {
            dup = factor[j];
            ans = ans * (c + 1);
            c = 1;
        }

        j = j / factor[j];
    }

    ans = ans * (c + 1);

    return ans;
}

ll a[N];
ll tree[4*N];
ll lazy[4*N]={0};

void build(ll node,ll start,ll end){
  if(start==end){ // leaf node
    tree[node]=a[start]; // or tree[node]=a[end] is also correct
  }
  else{
    ll mid=(start+end)/2;
    build(node*2,start,mid); // recursion on left child
    build(node*2+1,mid+1,end); // recursion on right child
    tree[node]=tree[node*2]+tree[node*2+1]; // llernal(parent) node values are calculated
  }
}

void range_update(ll node,ll start,ll end,ll left,ll right,ll val){
  if(lazy[node]!=0){ // node needs to be updated
    tree[node]+=(end-start+1)*lazy[node];
    if(start!=end){ // not leaf node
      lazy[node*2]+=lazy[node]; // making left child as lazy
      lazy[node*2+1]+=lazy[node]; // making right child as lazy
    }
    lazy[node]=0; // node is no longer lazy
  }

  if(end<start || start>right || end<left){ // node range is completely outside the update range
    return;
  }

  if(left<=start && end<=right){ // node range is completely within update range
    tree[node]+=(end-start+1)*val;
    if(start!=end){ // not leaf node
      lazy[node*2]+=val; // updating left child
      lazy[node*2+1]+=val; // updating right child
    }
    return;
  }

  ll mid=(start+end)/2;
  range_update(node*2,start,mid,left,right,val);
  range_update(node*2+1,mid+1,end,left,right,val);
  tree[node]=tree[node*2]+tree[node*2+1]; // updating parent node
}

ll range_query(ll node,ll start,ll end,ll left,ll right){
  if(start>end || start>right || end<left){ // node range is completely outside the query range
    return 0;
  }

  if(lazy[node]!=0){ // node needs to be updated
    tree[node]+=(end-start+1)*lazy[node];
    if(start!=end){ // not a leaf node
      lazy[node*2]+=lazy[node]; // making left child as lazy
      lazy[node*2+1]+=lazy[node]; // making right child as lazy
    }
    lazy[node]=0; // node is no longer lazy
  }

  if(left<=start && end<=right){ // node range is completely within update range
    return tree[node];
  }

  ll mid=(start+end)/2;
  ll s1=range_query(node*2,start,mid,left,right);
  ll s2=range_query(node*2+1,mid+1,end,left,right);
  return (s1+s2);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  generatePrimeFactors();
  fr(i,1,MAX) D[i]=calculateNoOFactors(i);

  /*
  ll len,m;
  cin>>len;

  fr(i,0,len) cin>>a[i];

  build(1,0,len-1); // constructing the segment tree

  fr(i,0,m){
    cin>>t>>l>>r;
    if(t==1) range_update(1,0,len-1,0,3,10);
  }

  cout<<range_query(1,0,len-1,0,0)<<"\n"; // a[0...0]
  cout<<range_query(1,0,len-1,0,1)<<"\n"; // a[0...1]
  cout<<range_query(1,0,len-1,0,2)<<"\n"; // a[0...2]
  cout<<range_query(1,0,len-1,0,3)<<"\n"; // a[0...3]
  cout<<range_query(1,0,len-1,2,2)<<"\n"; // a[2...2]
  cout<<range_query(1,0,len-1,1,3)<<"\n"; // a[1...3]

  range_update(1,0,len-1,0,3,10); // a[0]=10

  cout<<range_query(1,0,len-1,0,0)<<"\n"; // a[0...0]
  cout<<range_query(1,0,len-1,0,1)<<"\n"; // a[0...1]
  cout<<range_query(1,0,len-1,0,2)<<"\n"; // a[0...2]
  cout<<range_query(1,0,len-1,0,3)<<"\n"; // a[0...3]
  cout<<range_query(1,0,len-1,2,2)<<"\n"; // a[2...2]
  cout<<range_query(1,0,len-1,1,3)<<"\n"; // a[1...3]

  range_update(1,0,len-1,2,2,-10); // a[0]=-10

  cout<<range_query(1,0,len-1,2,3)<<"\n"; // a[2...3]
  */

  return 0;
}
