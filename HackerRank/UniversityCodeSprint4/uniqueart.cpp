#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 1000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll n;
map<ll,ll> cnt;
ll tree[2*N];

struct Query{
  ll id;
  ll left;
  ll right;
  ll ans;
};

bool cmp1(struct Query q1,struct Query q2){
  if(q1.right!=q2.right) return q1.right<q2.right;
  else return q1.left<q2.left;
}

bool cmp2(struct Query q1,struct Query q2){
  return q1.id<q2.id;
}

void build(ll a[]){
  fr(i,1,2*n) tree[i]=0;
}

ll update(ll pos,ll val){
  pos+=n;
  tree[pos]=val;

  while(pos>1){
    pos=pos/2;
    tree[pos]=tree[pos*2]+tree[pos*2+1];
  }
}

ll fn(ll left,ll right){
  ll cnt=0;
  left+=n;
  right+=n;

  while(left<right){
    if(left%2==1){
      cnt+=tree[left];
      left++;
    }
    if(right%2==1){
      right--;
      cnt+=tree[right];
    }
    left=left/2;
    right=right/2;
  }

  return cnt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  ll a[n];
  fr(i,0,n) cin>>a[i];

  build(a);

  ll q;
  cin>>q;
  struct Query query[q];

  ll l,r;
  fr(i,0,q){
    cin>>l>>r;
    query[i].id=i;
    query[i].left=l-1;
    query[i].right=r-1;
  }

  sort(query,query+q,cmp1);

  fr(i,0,n) lv[a[i]]=-1;

  ll ind=0;
  fr(i,0,q){
    while(ind<=query[i].right && ind<n){
      cnt[]
      if(cnt[a[ind]]==1){
        update(ind,1);
        lv[a[ind]]=ind;
      }
      else{
        update(lv[a[ind]],0);
        update(ind,1);
        lv[a[ind]]=ind;
      }
      ind++;
    }
    query[i].ans=fn(0,query[i].right+1)-fn(0,query[i].left);
  }

  sort(query,query+q,cmp2);
  fr(i,0,q) cout<<query[i].ans<<"\n";

  return 0;
}
