#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

struct K{
  ll p,c,ind,ans;
};

bool cmpPow(K k1,K k2){
  return k1.p<k2.p;
}

bool cmpInd(K k1,K k2){
  return k1.ind<k2.ind;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,k;
  cin>>n>>k;

  K a[n];
  fr(i,0,n) a[i].ind=i;
  fr(i,0,n) cin>>a[i].p;
  fr(i,0,n) cin>>a[i].c;
  sort(a,a+n,cmpPow);

  priority_queue<ll> pq;
  a[0].ans=a[0].c;
  pq.push(a[0].c);

  fr(i,1,n){
    vector<ll> v;
    ll cnt=0,sum=0;
    while(SZ(pq) && cnt<k){
      cnt++;
      v.PB(pq.top());
      sum+=pq.top();
      pq.pop();
    }
    a[i].ans=a[i].c+sum;
    fr(j,0,SZ(v)) pq.push(v[j]);
    pq.push(a[i].c);
  }

  sort(a,a+n,cmpInd);
  fr(i,0,n) cout<<a[i].ans<<" ";

  return 0;
}
