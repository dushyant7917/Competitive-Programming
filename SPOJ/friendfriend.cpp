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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;
  cin>>n;

  string fid,ffid;
  set<string> s;
  vector<string> f;
  fr(i,0,n){
    cin>>fid;
    f.PB(fid);
    cin>>m;
    fr(j,0,m){
      cin>>ffid;
      s.insert(ffid);
    }
  }

  fr(i,0,f.size()) s.erase(f[i]);

  cout<<s.size();

  return 0;
}
