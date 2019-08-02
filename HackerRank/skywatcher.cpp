#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;

  ll cnt=0,x,y;
  fr(0,n){
    cin>>x>>y;
    if(x>0 && y>0) cnt++;
  }

  printf("%4f",((db)(cnt)/(db)(n)));

  return 0;
}
