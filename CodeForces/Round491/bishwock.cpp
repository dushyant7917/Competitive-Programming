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

  string a,b;
  cin>>a;
  cin>>b;

  ll ans=0;
  fr(i,0,SZ(a)-1){
    if(a[i]=='0' && b[i]=='0' && a[i+1]=='0'){
      a[i]=b[i]=a[i+1]='X';
      ans++;
    }

    if(a[i]=='0' && a[i+1]=='0' && b[i+1]=='0'){
      a[i]=a[i+1]=b[i+1]='X';
      ans++;
    }

    if(b[i]=='0' && a[i+1]=='0' && b[i+1]=='0'){
      b[i]=a[i+1]=b[i+1]='X';
      ans++;
    }

    if(a[i]=='0' && b[i]=='0' && b[i+1]=='0'){
      a[i]=b[i]=b[i+1]='X';
      ans++;
    }
  }

  cout<<ans;

  return 0;
}
