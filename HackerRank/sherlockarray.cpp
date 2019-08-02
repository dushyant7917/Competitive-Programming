#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define loop(a,b) for(ll i=a;i<b;i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t,n;
  cin>>t;

  while(t--){
    cin>>n;

    ll a[n],b[n]={};
    loop(0,n){
      cin>>a[i];
      if(i==0){
        b[i]=a[i];
      }
      else{
        b[i]=a[i]+b[i-1];
      }
    }

    if(n==1){
      cout<<"YES\n";
      continue;
    }

    if(n==2){
      cout<<"NO\n";
      continue;
    }

    ll ans=0;
    loop(1,n-1){
      if(b[i-1]==b[n-1]-b[i]){
        cout<<"YES\n";
        ans=1;
        break;
      }
    }

    if(ans==0){
      cout<<"NO\n";
    }
  }

  return 0;
}
