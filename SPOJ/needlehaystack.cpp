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

  ll n;
  string needle,haystack,s;
  ll ns,hs,len;
  while(cin>>n){
    cin>>needle>>haystack;

    ns=needle.size();
    hs=haystack.size();

    vector<ll> p;

    ll lps[ns],i,j;
    len=0;
    lps[0]=0;
    i=1;
    while(i<ns){
      if(needle[i]==needle[len]) lps[i++]=++len;
      else{
        if(len!=0) len=lps[len-1];
        else lps[i++]=0;
      }
    }

    i=j=0;
    while(i<hs){
      if(haystack[i]==needle[j]) i++,j++;
      else if(haystack[i]!=needle[j] && j>0) j=lps[j-1];
      else if(haystack[i]!=needle[j] && j==0) i++;
      else {}

      if(j==ns){
        j=lps[j-1];
        p.PB(i-ns);
      }
    }

    if(p.size()>0){
      fr(i,0,p.size()) cout<<p[i]<<"\n";
      cout<<"\n";
    }
    else cout<<"\n";
  }

  return 0;
}
