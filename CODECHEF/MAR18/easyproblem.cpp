#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
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

string dec_to_binary(ll n){
  stack<char> st;
  string ans="";

  while(n>0){
    st.push(n%2);
    n/=2;
  }

  fr(i,0,31-SZ(st)) ans+='0';

  while(SZ(st)){
    ans+=(st.top()+'0');
    st.pop();
  }

  return ans;
}

ll binary_to_dec(string bit){
  ll ans=0;
  ll n=SZ(bit);

  fr(i,0,SZ(bit)){
    ans+=(bit[i]-'0')*(pow(2,n-i-1));
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,q;
  cin>>n>>q;

  ll a[n+1],f[n+1][31],b[31];
  string bit[n+1];

  fr(j,0,31) f[0][j]=0;

  fr(i,1,n+1){
    cin>>a[i];
    bit[i]=dec_to_binary(a[i]);
    fr(j,0,31){
      if(bit[i][j]=='1') f[i][j]=f[i-1][j]+1;
      else f[i][j]=f[i-1][j];
    }
  }

  ll l,r;
  string s;
  ll mv;

  fr(i,0,q){
    cin>>l>>r;

    s="";
    fr(j,0,31) b[j]=f[r][j]-f[l-1][j];
    mv=(r-l+1)/2;
    if((r-l+1)&1) mv+=1;
    fr(j,0,31){
      if(b[j]>=mv) s+='0';
      else s+='1';
    }
    cout<<binary_to_dec(s)<<"\n";
  }

  return 0;
}
