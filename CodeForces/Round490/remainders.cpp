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

struct S{
  ll n,i,r;
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m,k;
  cin>>n>>m;
  k=n/m;

  ll a[n];
  vector<pii> r[m];

  fr(i,0,n){
    cin>>a[i];
    r[a[i]%m].PB(pii(a[i],i));
  }

  ll cnt=0;
  fr(i,0,m) if(SZ(r[i])<k) cnt++;

  ll ind=0,add,ans=0;
  stack<S> st;

  while(cnt){
    if(SZ(r[ind])==k){
    }

    else if(SZ(r[ind])>k){
      while(SZ(r[ind])>k){
        st.push({r[ind][SZ(r[ind])-1].fi,r[ind][SZ(r[ind])-1].se,ind});
        r[ind].pop_back();
      }
    }

    else{
      while(SZ(st) && SZ(r[ind])<k){
        add=(ind>st.top().r)?(ind-st.top().r):(m-(st.top().r-ind));
        ans+=add;
        r[ind].PB(pii(st.top().n+add,st.top().i));
        st.pop();
      }
      if(SZ(r[ind])==k) cnt--;
    }

    ind++;
    if(ind==m) ind=0;
  }

  fr(i,0,m){
    fr(j,0,SZ(r[i])){
      a[r[i][j].se]=r[i][j].fi;
    }
  }

  cout<<ans<<"\n";
  fr(i,0,n) cout<<a[i]<<" ";

  return 0;
}
