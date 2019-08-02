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

  string s;
  cin>>s;

  ll f1=0,f2=0,ind=-1;
  for(ll i=0;i<s.size()-2+1;i++){
    if(s[i]=='A' && s[i+1]=='B'){
      ind=i+1;
      break;
    }
  }
  if(ind!=-1){
    for(ll i=ind+1;i<s.size()-2+1;i++){
      if(s[i]=='B' && s[i+1]=='A'){
        f1=1;
        break;
      }
    }
  }

  ind=-1;
  for(ll i=0;i<s.size()-2+1;i++){
    if(s[i]=='B' && s[i+1]=='A'){
      ind=i+1;
      break;
    }
  }
  if(ind!=-1){
    for(ll i=ind+1;i<s.size()-2+1;i++){
      if(s[i]=='A' && s[i+1]=='B'){
        f2=1;
        break;
      }
    }
  }

  if(f1 || f2) cout<<"YES";
  else cout<<"NO";

  return 0;
}
