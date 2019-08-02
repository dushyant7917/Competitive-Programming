#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
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

string name(string s){
  ll n=SZ(s);

  if(n>=7 && s[n-1]=='c' && s[n-2]=='i' && s[0]=='h' && s[1]=='y' && s[2]=='d' && s[3]=='r' && s[4]=='o') return "non-metal acid";
  else if(n>=2 && s[n-1]=='c' && s[n-2]=='i') return "polyatomic acid";
  else return "not an acid";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  string s;
  fr(i,0,n){
    cin>>s;
    cout<<name(s)<<"\n";
  }

  return 0;
}
