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

  ll pref[s.size()];
  fr(i,0,s.size()){
    if(s[i]=='Q' && i>0) pref[i]=pref[i-1]+1;
    else if(s[i]=='Q' && i==0) pref[i]=1;
    else if(s[i]!='Q' && i==0) pref[i]=0;
    else pref[i]=pref[i-1];
  }

  ll cnt=0;
  fr(i,1,s.size()-1){
    if(s[i]=='A'){
      if(pref[i-1]>=1 && pref[s.size()-1]-pref[i]>=1)
        cnt+=pref[i-1]*(pref[s.size()-1]-pref[i]);
    }
  }
  cout<<cnt;

  return 0;
}
