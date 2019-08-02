#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin>>s;
  if(s[1]=='+') cout<<(s[0]-'0')+(s[2]-'0');
  else cout<<(s[0]-'0')-(s[2]-'0');

  return 0;
}
