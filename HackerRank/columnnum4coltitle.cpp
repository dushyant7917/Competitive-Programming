#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define mod 1000000007

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin>>s;

  ll n=s.size();
  ll i,sum=0;
  for(i=n-1;i>=0;i--){
    sum+=(s[i]-'A'+1)*(pow(26,n-i-1));
  }

  cout<<sum;
  return 0;
}
