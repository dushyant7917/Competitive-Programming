#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 100000000
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001

ll n;

struct Activity{
  ll s; // start time
  ll e; // end time
};

bool cmp(struct Activity a1,struct Activity a2){
  if(a1.s==a2.s) return a1.e<a2.e;
  return a1.s<a2.s;
}

ll bs(struct Activity a[],ll e){
  ll l,r,m,pos=-1;
  l=0;
  r=n-1;
  
  while(l<=r){
    m=(l+r)/2;
    if(a[m].s>=e) pos=m,r=m-1;
    else if(e<a[m].s) r=m-1;
    else l=m+1;
  }
  return pos;
}

ll solve(struct Activity a[]){
  ll dp[n];
  dp[n-1]=1;

  for(ll i=n-2;i>=0;i--){
    dp[i]=(1%mod+dp[i+1]%mod)%mod;

    if(bs(a,a[i].e)!=-1){
      dp[i]=(dp[i]%mod+dp[bs(a,a[i].e)]%mod)%mod;
    }
  }

  return dp[0]%mod;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(cin>>n && n!=-1){
    struct Activity a[n]; // stores activity start and end time
    fr(i,0,n){
      cin>>a[i].s>>a[i].e;
    }

    sort(a,a+n,cmp);

    cout<<setfill('0')<<setw(8)<<solve(a)<<"\n";
  }

  return 0;
}
