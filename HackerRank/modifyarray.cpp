#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define mod 1000000007

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  ll a[n],b[n];
  fr(0,n)cin>>a[i];

  ll right_max_index=n-1,right_max=0;
  for(ll j=n-2;j>=0;j--){
    if(a[j+1]>right_max){
      right_max=a[j+1];
      right_max_index=j+1;
      b[j]=a[right_max_index];
    }
    else{
      b[j]=a[right_max_index];
    }
  }
  b[n-1]=0;

  fr(0,n){
    cout<<b[i]<<" ";
  }

  return 0;
}
