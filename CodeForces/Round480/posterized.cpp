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

  ll n,k,x,ind,visited[256],grp[256];
  cin>>n>>k;

  fr(i,0,256){
    visited[i]=0;
    grp[i]=i;
  }

  fr(i,0,n){
    cin>>x;

    if(!visited[x]){
      ind=x;
      while(ind>=0 && x-grp[ind]<k) ind--;
      ind++;
      fr(j,ind,x+1){
        grp[j]=ind;
        visited[j]=1;
      }
    }

    cout<<grp[x]<<" ";
  }

  return 0;
}
