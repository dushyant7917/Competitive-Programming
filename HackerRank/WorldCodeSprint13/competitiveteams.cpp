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
#define N 200001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll par[N],rnk[N],sz[N],f[N];
set<ll> s;
set<ll>::iterator ptr1,ptr2;

void createSet(ll n){
  fr(i,1,n+1){
    par[i]=i;
    rnk[i]=0;
    sz[i]=1;
    f[i]=0;
  }
}

ll findSet(ll x){
  if(par[x]!=x) par[x]=findSet(par[x]);
  return par[x];
}

void mergeSet(ll x,ll y){
  ll xx=findSet(x);
  ll yy=findSet(y);

  f[sz[yy]]--;
  if(!f[sz[yy]]) s.erase(sz[yy]);
  f[sz[xx]]--;
  if(!f[sz[xx]]) s.erase(sz[xx]);

  if(rnk[xx]>rnk[yy]){
    par[yy]=xx;
    sz[xx]+=sz[yy];
    f[sz[xx]]++;
    if(f[sz[xx]]) s.insert(sz[xx]);
  }
  else{
    par[xx]=yy;
    sz[yy]+=sz[xx];
    f[sz[yy]]++;
    if(f[sz[yy]]) s.insert(sz[yy]);
  }

  if(rnk[xx]==rnk[yy]) rnk[yy]++;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,q,t,x,y,c;
  cin>>n>>q;

  createSet(n);
  s.insert(1);
  f[1]=n;

  ll xx,yy,tot=n,sum,ans;

  while(q--){
    cin>>t;

    if(t==1){
      cin>>x>>y;

      xx=findSet(x);
      yy=findSet(y);
      if(xx==yy) continue;
      tot--;
      mergeSet(xx,yy);
    }

    else{
      cin>>c;

      if(c==0) ans=(tot*(tot-1))/2;
      else{
        sum=ans=0;
        ptr1=s.begin();
        for(ptr2=s.begin();ptr2!=s.end();ptr2++){
          while((*ptr2)-(*ptr1)>=c){
            sum+=f[*ptr1];
            ptr1++;
          }
          ans+=f[*ptr2]*sum;
        }
      }

      cout<<ans<<"\n";
    }
  }

  return 0;
}
