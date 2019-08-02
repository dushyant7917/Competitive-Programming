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

  ll n,k,left,rem;
  cin>>n>>k;

  char a[4][n];
  fr(i,0,4) fr(j,0,n) a[i][j]='.';

  cout<<"YES\n";

  if(k&1){
    a[1][n/2]='#';
    rem=left=k-1;
    fr(i,1,min(1+left/2,n/2)){
      a[1][i]='#';
      rem--;
    }
    rf(i,n-2,max(n/2+1,(n-2)-(left/2)+1)){
      a[1][i]='#';
      rem--;
    }
    left=rem;
    if(rem){
      fr(i,1,min(1+left/2,n/2)){
        a[2][i]='#';
        rem--;
      }
      rf(i,n-2,max(n/2+1,(n-2)-(left/2)+1)){
        a[2][i]='#';
        rem--;
      }
    }
  }
  else{
    fr(i,0,k/2){
      a[1][i+1]='#';
      a[2][i+1]='#';
    }
  }

  fr(i,0,4){
    fr(j,0,n){
      cout<<a[i][j];
    }
    cout<<"\n";
  }

  return 0;
}
