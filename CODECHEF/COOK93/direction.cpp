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
#define INF 1e10
#define N 101
#define MAX(a,b,c,d) max(a,max(b,max(c,d)))
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

struct Child{
  dbl x,v;
};

bool cmp(Child c1,Child c2){
  return c1.x<c2.x;
}

ll n;
Child c[N];

dbl getTime(ll j,ll i,ll dj,ll di){
  if(dj==-1 && di==1) return INF;
  else if(di==-1 && dj==-1 && c[j].v>=c[i].v) return INF;
  else if(di==1 && dj==1 && c[j].v<=c[i].v) return INF;
  else return abs((c[i].x-c[j].x)/(di*c[i].v-dj*c[j].v));
}

bool possible(dbl t){
  ll dir[n];
  dir[0]=-1;
  bool flag;

  fr(i,1,n){
    dir[i]=-1;
    flag=true;

    if(getTime(i-1,i,dir[i-1],dir[i])<=t) flag=false;

    if(flag) continue;

    dir[i]=1;
    flag=true;

    if(getTime(i-1,i,dir[i-1],dir[i])<=t) flag=false;

    if(!flag) return false;
  }

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  while(t--){
    cin>>n;

    fr(i,0,n) cin>>c[i].x>>c[i].v;

    sort(c,c+n,cmp);

    dbl left=0,right=1e10,mid;

    fr(i,0,100){
      mid=(left+right)*0.5;
      if(possible(mid)) left=mid;
      else right=mid;
    }

    if(mid>1e9) cout<<-1<<"\n";
    else cout<<fixed<<setprecision(6)<<mid<<"\n";
  }

  return 0;
}
