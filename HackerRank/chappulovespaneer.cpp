#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define K 1000000007

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;

  ll a[n],p[n];

  ll sum=0,min_price=K;
  fr(0,n){
    cin>>a[i]>>p[i];
    if(p[i]<min_price){
      min_price=p[i];
    }
    sum+=a[i]*min_price;
  }

  cout<<sum;

  return 0;
}
