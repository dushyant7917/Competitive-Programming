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
#define N 101
#define MAX(a,b,c,d) max(a,max(b,max(c,d)))
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

struct Child{
  ll x,v;
};

bool cmp(Child c1,Child c2){
  return c1.x<c2.x;
}

ll n;
Child c[N];

bool possible(dbl t){
  ll dir=0;

  fr(i,1,n){
    // direction of (i-1) is RHS
    if(dir){
      if((dbl)(c[i].x-c[i-1].x)/(dbl)(c[i].v+c[i-1].v)>t) dir=0; // assigning LHS direction to (i)
      else if((dbl)(c[i].x-c[i-1].x)/(dbl)abs((c[i].v-c[i-1].v))>t) dir=1; // assigning RHS direction to (i)
      else if(c[i-1].v<=c[i].v) dir=1; // assigning RHS direction to (i)
      else return false; // no direction assignment possible to (i)
    }

    // direction of (i-1) is LHS
    else{
      if((dbl)(c[i].x-c[i-1].x)/(dbl)(c[i].v-c[i-1].v)>t) dir=0; // assigning LHS direction to (i)
      else if(c[i].v<=c[i-1].v) dir=0; // assigning LHS direction to (i)
      else dir=1; // assigning RHS direction to (i)
    }
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

    dbl left=0,right=1e20,mid;

    fr(i,0,100){
      mid=(left+right)*0.5;
      if(possible(mid)) left=mid;
      else right=mid;
    }

    if(mid>1e15) cout<<-1<<"\n";
    else cout<<fixed<<setprecision(6)<<mid<<"\n";
  }

  return 0;
}
