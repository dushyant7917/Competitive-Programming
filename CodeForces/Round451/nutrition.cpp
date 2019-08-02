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

  ll n,a,b,x,y,hcf;
  cin>>n>>a>>b;

  fr(i,0,MAX(a,b,n)){
    if((n-(a*i))>=0 && (n-(a*i))%b==0){
      cout<<"YES\n";
      cout<<i<<" "<<(n-(a*i))/b;
      break;
    }
    if(n-a*i<0){
      cout<<"NO";
      break;
    }
  }

  return 0;
}
