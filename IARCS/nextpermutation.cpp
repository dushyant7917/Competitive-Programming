#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define pb push_back
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,k;
  cin>>n>>k;

  ll j;
  ll a[n],index=n-1, swap_index=n-1;
  while(k--){
    fr(i,0,n) cin>>a[i];


    for(j=n-1;j>=1;j--){
      if(a[j-1]<=a[j]){
        index=j-1;
        break;
      }
    }

    for(j=n-1;j>=index+1;j--){
      if(a[j]>=a[index]){
        swap_index=j;
        swap(a[swap_index],a[index]);
        break;
      }
    }

    reverse(a+swap_index,a+n);

    fr(i,0,n){
      cout<<a[i]<<" ";
    }
    cout<<"\n";

  }

  return 0;
}
