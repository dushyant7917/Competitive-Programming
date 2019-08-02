#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  ll v[n],t[n];
  fr(i,0,n) cin>>v[i];
  fr(i,0,n) cin>>t[i];

  priority_queue<ll,vector<ll>,greater<ll> > pq;

  ll sum=0,ans;

  fr(i,0,n){
    ans=0;
    pq.push(v[i]+sum);

    while(SZ(pq) && pq.top()<=t[i]+sum){
      ans+=pq.top()-sum;
      pq.pop();
    }

    sum+=t[i];
    ans+=t[i]*SZ(pq);

    cout<<ans<<" ";
  }

  return 0;
}
