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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  string s,tmp;
  ll n,m,ans,cnt,ind;

  while(t--){
    cin>>s>>n;

    m=0;
    tmp=s;
    ll f[2]={0};
    fr(i,0,SZ(s)) f[s[i]-'a']++;

    ans=0;

    if(f[0]==f[1]){
      f[0]=f[1]=0;
      fr(i,0,SZ(s)){
        f[s[i]-'a']++;
        if(f[0]>f[1]) ans++;
      }
      ans*=n;
    }

    else if(f[0]>f[1]){
      f[0]=f[1]=ind=0;

      do{
        cnt=0;
        fr(i,ind,SZ(s)){
          f[s[i]-'a']++;
          if(f[0]>f[1]) cnt++;
        }
        ans+=cnt;
        //cout<<cnt<<"\n";
        s+=tmp;
        ind+=SZ(tmp);
        m++;
      }while(m<n && cnt<SZ(tmp));

      if(m<n) ans+=SZ(tmp)*(n-m);
    }

    else{
      f[0]=f[1]=ind=0;

      do{
        cnt=0;
        fr(i,ind,SZ(s)){
          f[s[i]-'a']++;
          if(f[0]>f[1]) cnt++;
        }
        ans+=cnt;
        //cout<<cnt<<"\n";
        s+=tmp;
        ind+=SZ(tmp);
        m++;
      }while(m<n && cnt>0);
    }

    cout<<ans<<"\n";
  }

  return 0;
}
