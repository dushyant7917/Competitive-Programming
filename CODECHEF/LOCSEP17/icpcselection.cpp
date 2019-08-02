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

struct Teams{
  string name;
  string college;
  ll rank;
  bool selected;
};

bool cmp(struct Teams t1,struct Teams t2){
  return t1.rank<t2.rank;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  ll n,m,k;
  while(t--){
    cin>>n>>m>>k;

    struct Teams t[n];

    map<string,ll> mp;

    fr(i,0,n){
      cin>>t[i].name>>t[i].college;
      t[i].rank=i+1;
      t[i].selected=false;
    }

    vector<struct Teams> st;

    bool flag=false;
    ll ts=0,co=1;
    while(ts<m && co<=k){
      fr(i,0,n){
        if(t[i].selected==false){
          if(mp[t[i].college]<co){
            st.PB(t[i]);
            t[i].selected=true;
            mp[t[i].college]++;
            ts++;
            if(ts==m){
              flag=true;
              break;
            }
          }
        }
      }
      if(flag==true) break;
      co++;
    }

    if(ts==m){
      sort(st.begin(),st.end(),cmp);
      fr(i,0,st.size()){
        cout<<st[i].name<<"\n";
      }
    }
    else cout<<"Impossible\n";
    cout<<"\n";
  }

  return 0;
}
