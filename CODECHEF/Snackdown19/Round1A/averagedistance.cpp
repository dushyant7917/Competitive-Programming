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
#define N 305
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
bool house[N][N];
ll ltr[N][N],rtl[N][N];

bool valid(ll r,ll c){
  if(r<0 || r>n-1 || c<0 || c>m-1) return false;
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  while(t--){
    cin>>n>>m;
    string s[n];
    fr(i,0,n) cin>>s[i];

    fr(i,0,n) fr(j,0,m) house[i][j]=(s[i][j]=='1')?true:false;

    rf(i,n-1,0){
      rf(j,m-1,0){
        ltr[i][j]=rtl[i][j]=(s[i][j]=='1')?1:0;
        if(valid(i+1,j-1)) ltr[i][j]+=ltr[i+1][j-1];
        if(valid(i+1,j+1)) rtl[i][j]+=rtl[i+1][j+1];
      }
    }

    ll f[n+m-2+1]={0};

    fr(i,0,n){
      fr(j,0,m){
        if(!house[i][j]) continue;

        fr(k,1,n+m-2+1){

          /*

                  *
                *   *
              4(ltr)  1(rtl)
            *           *
          *               *
            *           *
              3(rtl)  2(ltr)
                *   *
                  *

          */ //The above figure helps in understanding the below logic

          // calculated using diagonal - 1(rtl)
          if(valid(i-k,j)) f[k]+=rtl[i-k][j]-((valid(i+1,j+k+1))?rtl[i+1][j+k+1]:0);
          else if(valid(0,j+k-i)) f[k]+=rtl[0][j+k-i]-((valid(i+1,j+k+1))?rtl[i+1][j+k+1]:0);
          else {}

          // calculated using diagonal - 2(ltr)
          if(valid(i,j+k)) f[k]+=ltr[i][j+k]-((valid(i+k+1,j-1))?ltr[i+k+1][j-1]:0);
          else if(valid(i+k-(m-1-j),m-1)) f[k]+=ltr[i+k-(m-1-j)][m-1]-((valid(i+k+1,j-1))?ltr[i+k+1][j-1]:0);
          else {}

          // calculated using diagonal - 3(rtl)
          if(valid(i,j-k)) f[k]+=rtl[i][j-k]-((valid(i+k+1,j+1))?rtl[i+k+1][j+1]:0);
          else if(valid(i+k-j,0)) f[k]+=rtl[i+k-j][0]-((valid(i+k+1,j+1))?rtl[i+k+1][j+1]:0);
          else {}

          // calculated using diagonal - 4(ltr)
          if(valid(i-k,j)) f[k]+=ltr[i-k][j]-((valid(i+1,j-k-1))?ltr[i+1][j-k-1]:0);
          else if(valid(0,j-(k-i))) f[k]+=ltr[0][j-(k-i)]-((valid(i+1,j-k-1))?ltr[i+1][j-k-1]:0);
          else {}

          // removing the duplicate count resulted from the four corners
          if(valid(i-k,j) && house[i-k][j]) f[k]--;
          if(valid(i,j+k) && house[i][j+k]) f[k]--;
          if(valid(i+k,j) && house[i+k][j]) f[k]--;
          if(valid(i,j-k) && house[i][j-k]) f[k]--;
        }
      }
    }

    fr(i,1,n+m-2+1) cout<<(f[i]/2)<<" "; cout<<"\n";
  }

  return 0;
}
