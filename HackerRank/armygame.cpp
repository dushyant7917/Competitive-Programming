#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define mod 1000000007

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m;
  cin>>n>>m;
  //cout<<(n+n%2)*(m+m%2)/4;
  //Above line does same task as below line
  cout<<((n+1)/2)*((m+1)/2);

  return 0;
}
