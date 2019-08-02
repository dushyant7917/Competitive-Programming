#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
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
  ll t;
  cin>>t;

  ll n,m,x,k;
  string s;
  ll no,ne,month,patents;

  while(t--){
    cin>>n>>m>>x>>k;
    cin>>s;

    no=ne=0;
    fr(i,0,SZ(s)){
      if(s[i]=='E') ne++;
      else no++;
    }

    month=1;
    patents=0;
    while(month<=m && patents<n){
      if(month&1){
        if(no>=x){
          patents+=x;
          no-=x;
        }
        else{
          patents+=no;
          no=0;
        }
      }
      else{
        if(ne>=x){
          patents+=x;
          ne-=x;
        }
        else{
          patents+=ne;
          ne=0;
        }
      }
      month++;
    }

    if(patents>=n) cout<<"yes\n";
    else cout<<"no\n";
  }

  return 0;
}
