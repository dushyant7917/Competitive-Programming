#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007

// Returns '0' for '1' and '1' for '0'
char flip(char c){
  return (c=='0')?'1':'0';
}

string ones_complement(string s)
{
    string ones="";

    //  for ones complement flip every bit
    fr(0,s.size())
        ones+=flip(s[i]);

    return ones;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;

  ll m=0;
  ll a[n];
  fr(0,n){
    cin>>a[i];
    m=max(a[i],m);
  }

  string s="0";
  while(s.size()<m+1){
    s+=ones_complement(s);;
  }

  fr(0,n) cout<<s[a[i]]<<"\n";

  return 0;
}
