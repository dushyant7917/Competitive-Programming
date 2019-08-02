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
#define MAX(a,b,c,d,e) max(a,max(b,max(c,max(d,e))))
#define MIN(a,b,c,d) min(a,min(b,min(c,d)))
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

struct Child{
  dbl x,v;
};

bool cmp(Child c1,Child c2){
  return c1.x<c2.x;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;

    Child c[n];

    fr(i,0,n) cin>>c[i].x>>c[i].v;

    sort(c,c+n,cmp);

    dbl leftLeft,leftRight,rightLeft,rightRight;

    dbl dp[2]={INF,INF};
    // dp[0] : state if previous child moves left
    // dp[1] : state if previous child moves right

    fr(i,1,n){
      if(c[i-1].v>=c[i].v) leftLeft=min(dp[0],INF);
      else leftLeft=min(dp[0],(c[i].x-c[i-1].x)/(c[i].v-c[i-1].v));

      leftRight=min(dp[0],INF);

      rightLeft=min(dp[1],(c[i].x-c[i-1].x)/(c[i].v+c[i-1].v));

      if(c[i].v>=c[i-1].v) rightRight=min(dp[1],INF);
      else rightRight=min(dp[1],(c[i].x-c[i-1].x)/(c[i-1].v-c[i].v));

      dp[0]=max(leftLeft,rightLeft);
      dp[1]=max(leftRight,rightRight);
    }

    if(max(dp[0],dp[1])==INF) cout<<-1<<"\n";
    else cout<<fixed<<setprecision(6)<<max(dp[0],dp[1])<<"\n";
  }

  return 0;
}
