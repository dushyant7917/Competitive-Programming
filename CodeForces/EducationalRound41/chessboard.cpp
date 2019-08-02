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

  ll n;
  cin>>n;

  char b[4][n][n];
  fr(k,0,4) fr(i,0,n) fr(j,0,n) cin>>b[k][i][j];

  ll p[4]={0,1,2,3};

  ll ans=INF,cnt;

  ll m=2*n;
  ll board[m][m],cmp[m][m];

  do{
    fr(i,0,n) fr(j,0,n) board[i][j]=b[p[0]][i][j];
    fr(i,0,n) fr(j,n,m) board[i][j]=b[p[1]][i][j-n];
    fr(i,n,m) fr(j,0,n) board[i][j]=b[p[2]][i-n][j];
    fr(i,n,m) fr(j,n,m) board[i][j]=b[p[3]][i-n][j-n];

    cnt=0;

    fr(i,0,m) fr(j,0,m){
      if((i+j)&1) cmp[i][j]='1';
      else cmp[i][j]='0';

      if(board[i][j]!=cmp[i][j]) cnt++;
    }

    ans=min(ans,cnt);

    cnt=0;

    fr(i,0,m) fr(j,0,m){
      if((i+j)&1) cmp[i][j]='0';
      else cmp[i][j]='1';

      if(board[i][j]!=cmp[i][j]) cnt++;
    }

    ans=min(ans,cnt);

  }while(next_permutation(p,p+4));

  cout<<ans;

  return 0;
}
