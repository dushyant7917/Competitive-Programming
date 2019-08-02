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

bool vowel(char c){
  if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y') return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  string s,r="";
  cin>>n>>s;

  ll m[n]={1};
  ll ind=0;
  fr(i,1,n){
    //cout<<ind<<" "<<s[ind]<<" "<<s[i]<<" ";
    if(vowel(s[i]) && vowel(s[ind])){
      m[i]=0;
      //cout<<0<<"\n";
    }
    else{
      ind=i;
      m[i]=1;
      //cout<<1<<"\n";
    }
  }

  fr(i,0,n) if(m[i]==1) r+=s[i];
  cout<<r;

  return 0;
}
