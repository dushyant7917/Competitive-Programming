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

  string s;
  cin>>s;
  ll a[s.size()+1]={0},b[s.size()+1]={0};
  fr(i,1,s.size()){
    if(s[i-1]==s[i]) a[i]=1;
  }
  fr(i,1,s.size()+1) b[i]=b[i-1]+a[i];

  ll m;
  cin>>m;
  ll l,r;
  fr(i,0,m){
    cin>>l>>r;
    cout<<b[r-1]-b[l-1]<<"\n";
  }

  return 0;
}
