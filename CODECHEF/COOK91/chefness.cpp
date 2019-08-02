#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<=b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 257
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,k;
string s;
ll dp[N][33][33][33][33];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll ans;
  while(t--){
    cin>>n>>k;
    cin>>s;

    fr(c,0,k+1) fr(ch,0,k+1) fr(che,0,k+1) fr(chef,0,k+1) dp[n][c][ch][che][chef]=((chef==k)?0:INF);

    ll tmp;

    rf(i,n-1,0){

      fr(c,0,k+1){
        fr(ch,0,k+1){
          fr(che,0,k+1){
            fr(chef,0,k+1){

              if(chef>k) dp[i][c][ch][che][chef]=INF;

              else{
                if(s[i]=='c') tmp=dp[i+1][min(c+1,k+1)][ch][che][chef];
                else if(s[i]=='h') tmp=dp[i+1][c][min(ch+c,k+1)][che][chef];
                else if(s[i]=='e') tmp=dp[i+1][c][ch][min(che+ch,k+1)][chef];
                else tmp=dp[i+1][c][ch][che][min(chef+che,k+1)];

                dp[i][c][ch][che][chef]=min(tmp,1+dp[i+1][c][ch][che][chef]);
              }

            }
          }
        }
      }

    }

    ll ans=dp[0][0][0][0][0];

    if(ans!=INF) cout<<ans<<"\n";
    else cout<<-1<<"\n";
  }

  return 0;
}
