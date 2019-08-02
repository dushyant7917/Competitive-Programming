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

  string s1,s2,ans="";
  while(cin>>s1>>s2){
    ll f1[26]={0};
    ll f2[26]={0};

    fr(i,0,s1.size()){
      f1[s1[i]-'a']++;
    }
    fr(i,0,s2.size()){
      f2[s2[i]-'a']++;
    }

    ans="";
    fr(i,0,26){
      fr(j,0,min(f2[i],f1[i])) ans+=(i+'a');
    }

    cout<<ans<<"\n";
  }

  return 0;
}
