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

  ll t;
  cin>>t;

  ll n,m;
  bool flag;
  string s;

  while(t--){
    cin>>n>>m;

    ll a[n][m],row[n]={0},col[m]={0};
    flag=false;

    fr(i,0,n){
      cin>>s;
      fr(j,0,m){
        a[i][j]=s[j]-'0';
        if(a[i][j]==1){
          flag=true;
          row[i]=1;
          col[j]=1;
        }
      }
    }

    if(!flag){
      fr(i,0,n){
        fr(j,0,m){
          cout<<-1<<" ";
        }
        cout<<"\n";
      }
    }
    else{
      fr(i,0,n){
        fr(j,0,m){
          if(a[i][j]==1) cout<<0;
          else if(row[i]==1 || col[j]==1) cout<<1;
          else cout<<2;
          cout<<" ";
        }
        cout<<"\n";
      }
    }
  }

  return 0;
}
