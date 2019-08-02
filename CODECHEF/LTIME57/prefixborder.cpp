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

string s;

bool check(ll l,ll r){
  string a="",b="";
  fr(i,0,l+1) a+=s[i];
  fr(i,r,SZ(s)) b+=s[i];

  if(a==b) return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,q,p,k,l,r,x,y;
  string str;
  while(t--){
    cin>>n>>q;
    cin>>s;

    vector<string> v[n];

    fr(i,0,n){
      l=i;
      r=n-i-1;
      str+=s[i];
      if(check(l,r)){
        fr(j,0,n){
          v[j].PB(str);
        }
      }
    }

    fr(i,0,q){
      cin>>p>>k;
      if(SZ(v[p-1])>=k) cout<<SZ(v[p-1][k-1])<<"\n";
      else cout<<-1<<"\n";
    }
  }

  return 0;
}
