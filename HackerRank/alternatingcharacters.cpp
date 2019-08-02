#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  string s;
  char prv;
  ll cnt;
  while(t--){
    cin>>s;
    prv=s[0];
    cnt=0;
    fr(1,s.size()){
      if(s[i]==prv) cnt++;
      else prv=s[i];
    }
    cout<<cnt<<"\n";
  }

  return 0;
}
