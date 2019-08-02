#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef int ll;
#define fr(x,a,b) for(ll x=a;x<b;x++)

string a_mod_b(string a,string b){
  ll num_b=0;
  vector<ll> num_a;
  string r="";

  fr(i,0,b.size()) num_b=(b[i]-'0')+(num_b*10);

  ll d=0;
  fr(i,0,a.size()){
    d=(a[i]-'0')+(d*10);
    if(d>=num_b){
      d=d%num_b;
    }
  }

  return to_string(d);
}

string gcd(string a,string b){
  if(b=="0") return a;
  else return gcd(b,a_mod_b(a,b));
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  string a,b;
  while(t--){
    cin>>a>>b;
    cout<<gcd(a,b)<<"\n";
  }

  return 0;
}
