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
#define INF 2e16
#define N 100001
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

  ll n,k,x,rem,ans,mx,sum,low,mid,high,ind;
  while(t--){
    cin>>n>>k;

    rem=n-k;
    map<ll,ll> mp;

    fr(i,0,n){
      cin>>x;
      mp[x]++;
    }

    vector<pii> p;
    p.PB(MP(0,0));

    for(auto x:mp){
      if(x.se>1) p.PB(MP(x.fi,x.se));
    }

    ll ps[SZ(p)];
    ps[0]=0;
    mx=0;
    sum=0;

    fr(i,1,SZ(p)){
      ps[i]=ps[i-1]+p[i].se;
      sum+=p[i].se-1;
      mx=max(mx,p[i].se-1);
    }

    if(sum-min(mx,2ll)<=rem){
      cout<<-1<<"\n";
      continue;
    }

    ans=1ll<<60;

    rf(i,SZ(p)-1,1){
      if(p[i].se>3){
        if(p[i].se-3>rem){
          ans=min(ans,p[i].fi*p[i].fi);
          break;
        }
        rem-=(p[i].se-3);
        p[i].se=3;
      }

      if(p[i].se==3){
        ind=1;
        low=1;
        high=i-1;
        while(low<=high){
          mid=(low+high)/2;
          if(ps[i-1]-ps[mid-1]-(i-mid)>rem){
            ind=mid;
            low=mid+1;
          }
          else high=mid-1;
        }
        ans=min(ans,p[i].first*p[ind].first);
      }

      if(p[i].se>1){
        if(p[i].se-1>rem){
          rf(j,i-1,1){
            if(p[j].se-1>rem){
              ans=min(ans,p[i].fi*p[j].fi);
              break;
            }
            rem-=(p[j].se-1);
          }
          break;
        }
        rem-=(p[i].se-1);
        p[i].se=1;
      }
    }

    cout<<ans<<"\n";
  }

  return 0;
}
