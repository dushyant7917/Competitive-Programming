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

bool check(ll m,ll s){
  if((s==0 && m>1) || s>(9*m)) return false;
  else return true;
}

string min_num(ll m,ll s){
  string res="";
  ll d;

  d=max(0LL,s-(9LL*(m-1)));
  if(d==0 && s>0) d=1;
  res+=char('0'+d);
  s-=d;

  string str="";
  fr(i,1,m){
    d=min(9LL,s);
    str+=char('0'+d);
    s-=d;
  }
  reverse(str.begin(),str.end());
  res+=str;

  return res;
}

string max_num(ll m,ll s){
  string res="";
  ll d;

  fr(i,0,m){
    d=min(9LL,s);
    res+=char('0'+d);
    s-=d;
  }

  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll m,s;
  cin>>m>>s;

  if(!check(m,s)) cout<<"-1 -1";
  else{
    cout<<min_num(m,s)<<" "<<max_num(m,s);
  }

  return 0;
}
