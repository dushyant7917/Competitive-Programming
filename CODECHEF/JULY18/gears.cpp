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
#define N 100005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
ll a[N];
ll par[N];
ll dir[N];
bool blocked[N];
vector<ll> cmp[N];

void createSet(){
  fr(i,1,n+1){
    par[i]=i;
    blocked[i]=false;
    dir[i]=0;
    cmp[i].PB(i);
  }
}

ll findSet(ll x){
  if(par[x]!=x) par[x]=findSet(par[x]);
  return par[x];
}

void mergeSet(ll x,ll y){
  ll xx=findSet(x);
  ll yy=findSet(y);

  if(SZ(cmp[xx])>SZ(cmp[yy])){
    par[yy]=xx;
    fr(i,0,SZ(cmp[yy])) cmp[xx].PB(cmp[yy][i]);
    cmp[yy].clear();
  }
  else{
    par[xx]=yy;
    fr(i,0,SZ(cmp[xx])) cmp[yy].PB(cmp[xx][i]);
    cmp[xx].clear();
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  createSet();

  ll t,x,y,v,change,xx,yy;
  ll num,den,hcf;

  fr(i,1,n+1) cin>>a[i];

  fr(i,0,m){
    cin>>t;

    if(t==1){
      cin>>x>>change;
      a[x]=change;
    }

    else if(t==2){
      cin>>x>>y;

      xx=findSet(x);
      yy=findSet(y);

      if(dir[x]==0 && dir[y]==0 && xx!=yy){
        dir[x]=1;
        dir[y]=-1;
        mergeSet(x,y);
      }
      else if(dir[x]==0 && dir[y]!=0 && xx!=yy){
        dir[x]=(dir[y]==1)?(-1):(1);
        mergeSet(x,y);
      }
      else if(dir[y]==0 && dir[x]!=0 && xx!=yy){
        dir[y]=(dir[x]==1)?(-1):(1);
        mergeSet(x,y);
      }
      else if(dir[x]!=0 && dir[y]!=0 && xx==yy && dir[x]==dir[y]){
        blocked[xx]=true;
      }
      else if(dir[x]!=0 && dir[y]!=0 && xx!=yy && dir[x]!=dir[y]){
        if(blocked[xx] || blocked[yy]) blocked[xx]=blocked[yy]=true;
        mergeSet(x,y);
      }
      else if(dir[x]!=0 && dir[y]!=0 && xx!=yy && dir[x]==dir[y]){
        if(blocked[xx] || blocked[yy]) blocked[xx]=blocked[yy]=true;
        if(SZ(cmp[xx])<SZ(cmp[yy])) fr(j,0,SZ(cmp[xx])) dir[cmp[xx][j]]=(dir[cmp[xx][j]]==1)?-1:1;
        else fr(j,0,SZ(cmp[yy])) dir[cmp[yy][j]]=(dir[cmp[yy][j]]==1)?-1:1;
        mergeSet(x,y);
      }
      else {}
    }

    else{
      cin>>x>>y>>v;

      xx=findSet(x);
      yy=findSet(y);

      if(blocked[yy] || blocked[xx]) cout<<0<<"\n";
      else if(xx!=yy) cout<<0<<"\n";
      else{
        num=v*a[x];
        den=a[y];
        hcf=__gcd(num,den);
        num=num/hcf;
        den=den/hcf;

        if(dir[x]==dir[y]) cout<<num<<"/"<<den<<"\n";
        else cout<<(-num)<<"/"<<den<<"\n";
      }
    }
  }

  return 0;
}
