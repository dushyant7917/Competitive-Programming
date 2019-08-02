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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  string s;
  while(cin>>n && n!=0){
    cin>>s;
    char r[s.size()/n][n];

    ll k=0;
    fr(i,0,s.size()/n){
      if(i%2==0){
        fr(j,0,n){
          r[i][j]=s[k++];
        }
      }
      else{
        for(ll j=n-1;j>=0;j--){
          r[i][j]=s[k++];
        }
      }
    }

    fr(j,0,n) fr(i,0,s.size()/n) cout<<r[i][j];
    cout<<"\n";
  }

  return 0;
}
