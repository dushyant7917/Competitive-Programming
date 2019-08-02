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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll bs(pair<ll,ll> p[],ll s,ll e,ll x){
  ll m,ind=-1;
  while(s<=e){
    //cout<<"s:"<<s<<" e:"<<e;
    m=(s+e)/2;
    //cout<<" m:"<<m<<"\n";
    if(x>=p[m].first){
      ind=max(ind,p[m].second);
      s=m+1;
    }
    else{
      e=m-1;
    }
  }
  return ind;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,d,sum,ans,ind,s,e;
  while(t--){
    cin>>n>>d;
    ll a[n];
    fr(i,1,n+1) cin>>a[i];

    ans=INF;
    s=e=sum=0;
    pair<ll,ll> p[n+1];
    p[0]=MP(0,0);
    fr(i,1,n+1){
      sum+=a[i];
      ind=bs(p,s,e,sum-d);
      if(ind!=-1){
        ans=min(ans,i-ind);
      }
      while(e>=0 && p[e].first>=sum) e--;
      //cout<<"sum:"<<sum<<" ind:"<<ind<<" ans:"<<ans;
      p[++e]=MP(sum,i);
      //cout<<" e:"<<e<<"\n";
    }

    if(ans==INF) cout<<-1<<"\n";
    else cout<<ans<<"\n";
  }

  return 0;
}
