#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007

bool prime_num(int n){
  // corner cases
  if(n<=1) return false;
  if(n<=3) return true;

  // Below code is checked so that we can skip middle 5 numbers in the later while loop
  if(n%2==0 || n%3==0) return false;

  int i=5;
  while(i*i<=n){
    if(n%i==0 || n%(i+2)==0)return false;
    i+=6;
  }

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  ll m,n;
  while(t--){
    cin>>m>>n;
    fr(m,n+1){
      if(prime_num(i))cout<<i<<"\n";
    }
    cout<<"\n";
  }

  return 0;
}
