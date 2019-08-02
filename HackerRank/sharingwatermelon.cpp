#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define mod 1000000007

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;


  if(t==2)cout<<"NO";
  else if(t%2==0){
    cout<<"YES";
  }
  else{
    cout<<"NO";
  }

  return 0;
}
