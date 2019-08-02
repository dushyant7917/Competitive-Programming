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
#define N 400001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
pii a[N];

bool check(ll k){
  priority_queue<ll> pq;
  ll sum=0,new_sum,largest;

  fr(i,0,k){
    pq.push(a[i].se);
    sum+=a[i].se;
  }

  if(k*a[k-1].fi>=sum) return true;

  fr(i,k,n){
    largest=pq.top();
    pq.pop();
    sum-=largest;

    new_sum=sum+a[i].se;
    if(k*a[i].fi>=new_sum) return true;

    if(largest<a[i].se){
      pq.push(largest);
      sum+=largest;
    }
    else{
      pq.push(a[i].se);
      sum+=a[i].se;
    }
  }

  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll ans,l,r,m;
  while(t--){
    cin>>n;
    fr(i,0,n) cin>>a[i].fi>>a[i].se;
    sort(a,a+n);
    reverse(a,a+n);

    ans=0;
    l=0;
    r=n;

    while(l<=r){
      m=(l+r)/2;
      if(check(m)){
        ans=m;
        l=m+1;
      }
      else r=m-1;
    }

    cout<<ans<<"\n";
  }

  return 0;
}
