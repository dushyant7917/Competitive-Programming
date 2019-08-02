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

  ll n;
  while(cin>>n && n!=-1){
    bool flag=false;
    if(n%6==1){
      fr(i,0,n/6+1){
        if(3*i*(i+1)+1==n){
          flag=true;
          break;
        }
      }
    }
    if(flag) cout<<"Y\n";
    else cout<<"N\n";
  }

  return 0;
}
