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

bool cmp(pii p1,pii p2){
  return p1.se<p2.se;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,k;
  cin>>n>>k;
  ll a[n];
  fr(i,0,n) cin>>a[i];

  priority_queue<pii> pq;
  fr(i,0,n) pq.push(pii(a[i],i));

  ll cnt=0,sum=0;
  pii v[k];
  while(cnt<k){
    v[cnt++]=pq.top();
    sum+=pq.top().fi;
    pq.pop();
  }

  sort(v,v+k,cmp);

  cout<<sum<<"\n";

  ll ind=0;
  fr(i,0,k){
    cnt=0;
    while(a[ind]!=v[i].fi){
      //cout<<a[ind]<<" ";
      ind++;
      cnt++;
    }
    if(a[ind]==v[i].fi){
      //cout<<a[ind]<<" :";
      ind++;
      cnt++;
    }
    if(i==k-1 && ind<n){
      cnt+=n-ind;
    }
    cout<<cnt<<" ";
  }

  return 0;
}
