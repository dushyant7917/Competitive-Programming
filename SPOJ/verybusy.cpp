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

struct Activity{
  ll s;
  ll e;
};

bool cmp(struct Activity a1,struct Activity a2){
  if(a1.e==a2.e) return a1.s<a2.s;
  else return a1.e<a2.e;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,ans,tim;
  while(t--){
    cin>>n;

    struct Activity a[n];
    fr(i,0,n) cin>>a[i].s>>a[i].e;
    sort(a,a+n,cmp);

    ans=0;
    tim=0;
    fr(i,0,n){
      if(a[i].s>=tim){
        ans++;
        tim=a[i].e;
      }
      else continue;
    }

    cout<<ans<<"\n";
  }

  return 0;
}
