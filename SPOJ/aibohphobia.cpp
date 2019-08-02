#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  string s,r;
  ll m,n;
  while(t--){
    cin>>s;

    r=s;
    reverse(r.begin(),r.end());
    m=s.size();
    n=r.size();
    ll LC_suffix[m+1][n+1]; // Least Common Suffix

    fr(i,0,m+1){
      fr(j,0,n+1){
        if(i==0 || j==0) LC_suffix[i][j]=0;
        else if(s[i-1]==r[j-1]) LC_suffix[i][j]=LC_suffix[i-1][j-1]+1;
        else LC_suffix[i][j]=max(LC_suffix[i-1][j],LC_suffix[i][j-1]);
      }
    }

    cout<<m-LC_suffix[m][n]<<"\n";
  }

  return 0;
}
