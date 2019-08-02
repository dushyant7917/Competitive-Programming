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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  float m,len;
  ll n;
  while(cin>>m && m!=0.00){
    len=0.00;
    n=0;
    while(len<m){
      n++;
      len+=1.00/(1.00+n);
    }
    cout<<n<<" card(s)\n";
  }

  return 0;
}
