#include<bits/stdc++.h>

using namespace std;

typedef int ll;
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
#define N 100002
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll n,ans;
  bool flag;

  while(t--){
    cin>>n;
    ll a[n],b[n];
    fr(i,0,n) cin>>a[i];
    fr(i,0,n) cin>>b[i];

    flag=false;

    fr(i,0,n){
      if(a[i]<b[i]){
        flag=true;
        break;
      }
    }

    if(flag){
      cout<<-1<<"\n";
      continue;
    }

    ans=0;
    deque<ll> dq;

    fr(i,0,n){
      while(SZ(dq) && b[i]>dq.back()) dq.pop_back();
      while(SZ(dq) && a[i]<dq.front()) dq.pop_front();
      if(a[i]!=b[i] && (!SZ(dq) || b[i]!=dq.back())){
        ans++;
        dq.push_back(b[i]);
      }
    }

    cout<<ans<<"\n";
  }

  return 0;
}
