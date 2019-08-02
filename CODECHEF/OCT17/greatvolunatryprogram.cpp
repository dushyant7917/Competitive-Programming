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

ll ka,kb;
ll na,nb;

void happy_arrangement(string s,char more,char less,ll n_more,ll n_less,ll k_more,ll k_less){
  string ans="";

  ll cc=0;
  while(n_more>n_less){
    if(cc==k_more && n_more!=0){
      if(n_less>0){
        ans+=less;
        n_less--;
      }
      else{
        ans+='*';
      }
      cc=0;
    }
    else{
      ans+=more;
      n_more--;
      cc++;
    }
  }

  // In the below code n_more and n_less can be interchanged(doesn't matter)
  if(n_more==n_less){
    while(n_more>0){
      ans+=less;
      ans+=more;
      n_more--;
    }
  }

  cout<<ans;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  string s;
  while(t--){
    cin>>s;
    cin>>ka>>kb;

    na=0;
    nb=0;
    fr(i,0,s.size()){
      if(s[i]=='a') na++;
      else nb++;
    }

    if(na>nb) happy_arrangement(s,'a','b',na,nb,ka,kb);
    else if(na<nb) happy_arrangement(s,'b','a',nb,na,kb,ka);
    else{
      fr(i,0,na){
        cout<<"ab";
      }
    }

    cout<<"\n";
  }

  return 0;
}
