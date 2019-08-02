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
#define INF 2e10
#define N 100000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll bs_rhs(ll a[],ll n,ll x){
  ll res=-1,m,l=0,h=n-1;

  while(l<=h){
    m=(l+h)/2;
    if(a[m]>=x){
      res=a[m];
      h=m-1;
    }
    else l=m+1;
  }

  return res;
}

ll bs_lhs(ll a[],ll n,ll x){
  ll res=-1,m,l=0,h=n-1;

  while(l<=h){
    m=(l+h)/2;
    if(a[m]<=x){
      res=a[m];
      l=m+1;
    }
    else h=m-1;
  }

  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m,ns,ne,v;
  cin>>n>>m>>ns>>ne>>v;

  ll s[ns],e[ne];
  fr(i,0,ns) cin>>s[i];
  fr(i,0,ne) cin>>e[i];

  ll q,x1,y1,x2,y2,ind;
  cin>>q;

  fr(i,0,q){
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2) cout<<abs(y1-y2)<<"\n";
    else{
      vector<ll> ans;

      if(y1<m){
        ind=bs_rhs(s,ns,y1+1);
        if(ind!=-1) ans.PB(abs(ind-y1)+abs(x1-x2)+abs(ind-y2));

        ind=bs_rhs(e,ne,y1+1);
        if(ind!=-1) ans.PB(abs(ind-y1)+((ll)ceil((dbl)abs(x1-x2)/(dbl)v))+abs(ind-y2));
      }
      if(y1>1){
        ind=bs_lhs(s,ns,y1-1);
        if(ind!=-1) ans.PB(abs(ind-y1)+abs(x1-x2)+abs(ind-y2));

        ind=bs_lhs(e,ne,y1-1);
        if(ind!=-1) ans.PB(abs(ind-y1)+((ll)ceil((dbl)abs(x1-x2)/(dbl)v))+abs(ind-y2));
      }

      ll mn=INF;
      fr(i,0,SZ(ans)) mn=min(mn,ans[i]);
      cout<<mn<<"\n";
    }
  }

  return 0;
}
