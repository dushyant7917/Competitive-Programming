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
#define N 101
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
ll a[N][N],rm[N],cm[N];

bool check(ll i,ll j){
  if(a[i][j]<rm[i] || a[i][j]<cm[j]) return false;
  else return true;
}

ll provide(ll i,ll j){
  if(i==0 && j==0) return 1;
  else if(i==0 && j>0) return a[i][j-1];
  else if(i>0 && j==0) return a[i-1][j];
  else return max(a[i-1][j],a[i][j-1]);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  while(t--){
    cin>>n>>m;
    fr(i,0,n) fr(j,0,m) cin>>a[i][j];

    fr(i,0,n) rm[i]=a[i][0];
    fr(j,0,m) cm[j]=a[0][j];

    bool flag=true;
    ll x;
    fr(i,0,n){
      fr(j,0,m){
        if(a[i][j]!=-1){
          rm[i]=max(rm[i],a[i][j]);
          cm[j]=max(cm[j],a[i][j]);

          if(!check(i,j)){
            //cout<<"check failed 1\n";
            //cout<<i<<" "<<j<<" a[i][j]:"<<a[i][j]<<"\n";
            flag=false;
            break;
          }
        }
        else{
          a[i][j]=provide(i,j);
          rm[i]=max(rm[i],a[i][j]);
          cm[j]=max(cm[j],a[i][j]);

          if(!check(i,j)){
            //cout<<"check failed 2\n";
            //cout<<i<<" "<<j<<" a[i][j]:"<<a[i][j]<<"\n";
            flag=false;
            break;
          }
        }
      }
      if(!flag) break;
    }

    if(flag){
      fr(i,0,n){
        fr(j,0,m){
          cout<<a[i][j]<<" ";
        }
        cout<<"\n";
      }
    }
    else cout<<-1<<"\n";
  }

  return 0;
}
