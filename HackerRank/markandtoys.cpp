#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define loop(a,b) for(ll i=a;i<b;i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,k;
  cin>>n>>k;

  ll a[n];
  loop(0,n){
    cin>>a[i];
  }
  sort(a,a+n);
  ll sum=0,cnt=0;
  loop(0,n){
    sum+=a[i];
    if(sum<=k){
      cnt++;
    }
    else{
      break;
    }
  }
  cout<<cnt;
  return 0;
}
