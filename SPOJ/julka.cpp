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

string get_k(string t,string m){
  string ans="";
  ll res[101];

  ll n1[101]; // stores total(t)
  ll n2[101]; // stores more(m)

  for(ll i=m.size()-1;i>=0;i--){
    n2[m.size()-i-1]=m[i]-'0';
    cout<<m[i]-'0';
  }
  for(ll i=t.size()-1;i>=0;i--){
    n1[t.size()-i-1]=t[i]-'0';
  }

  ll carry=0,cal,ind;
  fr(i,0,m.size()){
    ind=i;
    cal=(n1[i]+n2[i]+carry);
    res[i]=cal%10;
    carry=cal/10;
  }
  fr(j,ind+1,t.size()){
    ind=j;
    cal=(n1[j]+carry);
    res[j]=cal%10;
    carry=cal/10;
  }
  ind++;
  while(carry>0){
    res[ind++]=carry%10;
    carry=carry/10;
  }

  for(ll i=ind;i>=0;i--){
    ans+=res[i];
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string t,m;
  string k,n;

  fr(i,0,2){
    cin>>t;
    cin>>m;
    cout<<get_k(t,m)<<"\n";
    //cout<<get_n(t,m)<<"\n";
  }

  return 0;
}
