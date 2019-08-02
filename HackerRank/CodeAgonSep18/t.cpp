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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll x[5],y[5],r,c;

  while(t--){
    fr(i,0,5) cin>>x[i]>>y[i];

    set<ll> sx,sy;
    map<ll,ll> mpx,mpy;

    fr(i,0,5){
      sx.insert(x[i]);
      sy.insert(y[i]);
      mpx[x[i]]++;
      mpy[y[i]]++;
    }

    if(SZ(sx)!=3 || SZ(sy)!=3){
      cout<<"No\n";
      continue;
    }

    for(auto x:mpx){
      if(x.se==3){
        r=x.fi;
      }
    }

    for(auto y:mpy){
      if(y.se==3){
        c=y.fi;
      }
    }

    vector<ll> vx,vy;

    fr(i,0,5){
      if(x[i]==r){
        vx.PB(y[i]);
      }
      if(y[i]==c){
        vy.PB(x[i]);
      }
    }

    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());

    bool flag=true;

    fr(i,1,3){
      if(vx[i]-vx[i-1]!=1 || vy[i]-vy[i-1]!=1){
        flag=false;
        break;
      }
    }

    if(flag) cout<<"Yes\n";
    else cout<<"No\n";
  }

  return 0;
}
