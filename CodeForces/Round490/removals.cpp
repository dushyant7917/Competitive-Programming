#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,k;
  string s;
  cin>>n>>k>>s;

  ll mark[n]={0};
  vector<ll> v[26];
  ll cnt[26]={0};
  fr(i,0,SZ(s)) v[s[i]-'a'].PB(i);

  fr(i,0,k){
    fr(j,0,26){
      if(cnt[j]<SZ(v[j])){
        mark[v[j][cnt[j]]]=1;
        cnt[j]++;
        break;
      }
    }
  }

  fr(i,0,n) if(!mark[i]) cout<<s[i];

  return 0;
}
