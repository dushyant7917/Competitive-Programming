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
#define N 320001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll n,q;
ll tree[N];
ll prime[1000001];

void sieve(ll n){
  fr(i,0,1000001) prime[i]=1;

  ll i,j;
  for(i=2;i*i<=n;i++){
    if(prime[i]==1){
      for(j=i*2;j<=n;j+=i){
        prime[j]=0;
      }
    }
  }

  prime[0]=prime[1]=0;
}

void build(ll a[]){
  fr(i,n,2*n) tree[i]=(prime[a[i-n]]==1)?1:0;

  for(ll i=n-1;i>=1;i--){
    tree[i]=tree[i*2]+tree[(i*2)+1];
  }
}

void update(ll pos,ll val){
  pos+=n;
  tree[pos]=(prime[val]==1)?1:0;

  while(pos>1){
    pos=pos/2;
    tree[pos]=tree[pos*2]+tree[(pos*2)+1];
  }
}

ll query(ll left,ll right){
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

  sieve(1000001);

  ll t;
  cin>>t;

  char ty;
  ll x,y;

  while(t--){
    cin>>n;

    ll a[n];
    fr(i,0,n) cin>>a[i];

    build(a);

    cin>>q;
    fr(i,0,q){
      cin>>ty;
      if(ty=='C'){
        cin>>x>>y;
        update(x-1,y);
      }
      else{
        cin>>x>>y;
        cout<<query(x-1,y)<<"\n";
      }
    }
  }

  return 0;
}
