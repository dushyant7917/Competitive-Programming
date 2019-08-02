#include<bits/stdc++.h>

using namespace std;

typedef int ll;
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
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,k;
string s;
ll fn(char x,char y){
  ll mv=0,ch;
  ll l,r;

  l=r=ch=0;
  fr(i,0,n){
    if(s[i]=='c') mv=max(mv,r-l);
    else if(s[i]==x) r++;
    else{
      if(ch<k){
        ch++;
        r++;
      }
      else{
        mv=max(mv,r-l);
        l++;
        while(s[l-1]!=y) l++;
        ch++;
        r++;
      }
    }
  }

  return mv;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin>>n>>k;
  cin>>s;

  s+='c';
  n++;

  ll m1,m2;
  m1=fn('a','b');
  m2=fn('b','a');
  cout<<max(m1,m2);

  return 0;
}
