#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef float dbl;
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
#define PI 3.14159265

ll num,den,r;

ll mod_inverse(ll a,ll m=mod){
  ll m0=m;
  ll y=0,x=1;

  if(m==1) return 0;

  while(a>1){
    ll q=a/m;
    ll t=m;
    m=a%m,a=t;
    t=y;
    y=x-q*y;
    x=t;
  }

  if(x<0) x+=m0;
  return x;
}

void fraction(dbl f){
  ll s=((f<0)?-1:1);

  if(s==-1) f=abs(f);

  dbl bd=trunc(f);

  //cout<<"f:"<<f<<" trunc(f):"<<bd<<"\n";

  if(f==bd){
    num=f*s;
    den=1;
    return;
  }

  dbl ad=(f>=1.0)?(f-bd):f;

  string dec=to_string(f);
  ll ind;

  fr(i,0,SZ(dec)){
    if(dec[i]=='.'){
      ind=i;
      break;
    }
  }

  ll m=pow(10,SZ(dec)-(ind+1));
  num=bd*m+ad*m;
  den=m;

  ll hcf=__gcd(num,den);
  num=num/hcf;
  if(s==-1) num=num*s;
  den=den/hcf;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll q;
  cin>>q;

  ll l,d;
  dbl y;
  unsigned long long t;
  while(q--){
    cin>>l>>d>>t;
    dbl agl=acos((dbl)d/(dbl)l)*(180.0/PI);
    agl=((dbl)t)*agl;
    y=l*cos((dbl)((ll)agl)*PI/180.0);
    fraction(y);
    //cout<<num<<"/"<<den<<" "<<mod_inverse(3)<<"\n";
    r=mod_inverse(den);
    if(num*r<0) cout<<(mod+num*r)%mod<<"\n";
    else cout<<(num*r)%mod<<"\n";
  }

  return 0;
}
