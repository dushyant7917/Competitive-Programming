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

bool V(char c){
  if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  cin>>s;

  fr(i,0,SZ(s)){
    if(!V(s[i]) && s[i]!='n'){
      if(i==SZ(s)-1 || (i<SZ(s)-1 && !V(s[i+1]))){
        cout<<"NO";
        return 0;
      }
    }
  }

  cout<<"YES";

  return 0;
}
