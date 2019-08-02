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

struct Key{
  string s;
  vector<string> cols;
};

ll k;

bool lexicographic(struct Key k1,struct Key k2){
  return k1.cols[k-1]<=k2.cols[k-1];
}

bool numeric(struct Key k1,struct Key k2){
  if(k1.cols[k-1].size()==k2.cols[k-1].size()) return k1.cols[k-1]<=k2.cols[k-1];
  else return k1.cols[k-1].size()<=k2.cols[k-1].size();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  cin.clear();
  cin.ignore();

  struct Key keys[n];
  fr(i,0,n){
    getline(cin,keys[i].s);
  }

  string rev;
  string cmp;
  cin>>k;
  cin>>rev;
  cin>>cmp;

  fr(i,0,n){
    keys[i].s+=' ';
    string col="";
    fr(j,0,keys[i].s.size()){
      if(keys[i].s[j]!=' ') col+=keys[i].s[j];
      else{
        keys[i].cols.PB(col);
        col="";
      }
    }
  }

  if(cmp=="numeric") sort(keys,keys+n,numeric);
  else sort(keys,keys+n,lexicographic);

  if(rev=="false"){
    fr(i,0,n) cout<<keys[i].s<<"\n";
  }
  else{
    for(ll i=n-1;i>=0;i--) cout<<keys[i].s<<"\n";
  }

  return 0;
}
