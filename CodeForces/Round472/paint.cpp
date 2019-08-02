#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

string check(string s){
  if(SZ(s)==1 && s[0]=='?') return "Yes";
  if(SZ(s)==1) return "No";

  fr(i,0,SZ(s)-1){
    if(s[i]==s[i+1] && s[i]!='?') return "No";
  }

  if(s[0]=='?' || s[SZ(s)-1]=='?') return "Yes";

  fr(i,0,SZ(s)-1){
    if(s[i]=='?' && s[i+1]=='?') return "Yes";
  }

  fr(i,0,SZ(s)-2){
    if(s[i]!='?' && s[i+1]=='?' && s[i+2]!='?' && s[i]==s[i+2]) return "Yes";
  }

  return "No";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  string s;
  cin>>s;

  cout<<check(s);
  return 0;
}
