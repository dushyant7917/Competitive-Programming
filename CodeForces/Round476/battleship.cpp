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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,k;
  cin>>n>>k;

  char a[n][n];

  fr(i,0,n) fr(j,0,n) cin>>a[i][j];

  ll l,r,u,d,h,v,mx=0,x,p,q;
  vector<pii> ans;

  fr(i,0,n){
    fr(j,0,n){
      if(a[i][j]=='#') continue;

      l=r=u=d=0;

      p=i;
      q=j;
      while(q-1>=0 && a[p][q-1]=='.' && l<k-1){
        q--;
        l++;
      }

      p=i;
      q=j;
      while(q+1<=n-1 && a[p][q+1]=='.' && r<k-1){
        q++;
        r++;
      }

      p=i;
      q=j;
      while(p-1>=0 && a[p-1][q]=='.' && u<k-1){
        p--;
        u++;
      }

      p=i;
      q=j;
      while(p+1<=n-1 && a[p+1][q]=='.' && d<k-1){
        p++;
        d++;
      }

      h=1+l+r;
      v=1+u+d;
      x=0;

      if(h>=k) x+=1+(h-k);
      if(v>=k) x+=1+(v-k);

      if(x>mx){
        mx=x;
        ans.PB(pii(i+1,j+1));
      }
    }
  }

  if(SZ(ans)==0) cout<<1<<" "<<1;
  else cout<<ans[SZ(ans)-1].first<<" "<<ans[SZ(ans)-1].second;

  return 0;
}
