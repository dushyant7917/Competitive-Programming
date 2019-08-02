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
#define N 500005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

bool valley(ll a[],ll i){
  if(a[i]<a[i-1] && a[i]<a[i+1]) return true;
  else return false;
}

bool check(ll a[],ll i){
  if(a[i]+a[i+2]>=a[i+1]) return true;
  else return false;
}

ll ans[N],mn;

void F(ll a[],ll n,ll i,ll sum){
  if(i==n+1){
    bool flag=true;

    fr(j,1,n+1){
      if(j+2<=n && valley(a,j) && !valley(a,j+1) && valley(a,j+2) && a[j]+a[j+1]+a[j+2]<=0){
        flag=false;
        break;
      }
    }

    if(flag && sum<mn){
      mn=sum;
      fr(j,1,n+1) ans[j]=a[j];
    }
  }

  else{
    F(a,n,i+1,sum+a[i]);

    if(valley(a,i)){
      a[i]=-a[i];
      F(a,n,i+1,sum+a[i]);
    }
  }
}

struct MAP{
  ll val,ind;
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  t=100;
  //cin>>t;

  srand((unsigned)time(0));

  ll n,ind,cur,left,right,cnt,sum,prv;
  while(t--){
    //cin>>n;
    n=(rand()%50)+2;

    ll a[n+2],b[n+2];
    a[0]=a[n+1]=b[0]=b[n+1]=INF;

    fr(i,1,n+1){
      //cin>>a[i];
      a[i]=(rand()%1000)+1;
      b[i]=a[i];
    }

    // BRUTE-FORCE
    mn=N*INF;
    F(a,n,1,0);
    //fr(i,1,n+1) cout<<ans[i]<<" "; cout<<"\n";

    // EFFICIENT
    fr(i,1,n+1) a[i]=b[i];
    ind=1;
    while(ind<=n){
      cur=left=ind;

      vector<ll> v;
      v.PB(0);
      cnt=1;

      if(valley(a,cur)) v.PB(cur);

      while(cur<=n-2 && valley(a,cur) && valley(a,cur+2) && check(a,cur)){
        cur+=2;
        cnt++;
        v.PB(cur);
      }

      right=cur;

      if(left==right && valley(a,left)) b[left]=-b[left];
      else if(left!=right){
        ll x=SZ(v);
        stack<ll> st;
        ll dp[x];
        dp[0]=0;
        dp[1]=a[v[1]];
        st.push(v[1]);
        prv=v[1]+3;

        fr(i,2,x){
          if(dp[i-2]+a[v[i]]>dp[i-1]){
            dp[i]=dp[i-2]+a[v[i]];
            st.push(v[i]);
            prv=v[i]+3;
          }
          else dp[i]=dp[i-1];
        }

        while(SZ(st)){
          if(prv-st.top()>=3){
            b[st.top()]=-b[st.top()];
            prv=st.top();
          }
          st.pop();
        }
      }
      else {}

      //cout<<"\n";
      //cout<<sum1<<" "<<sum2<<"\n";
      //cout<<left<<" - "<<right<<"\n";

      ind=right+1;
    }

    //fr(i,1,n+1) cout<<b[i]<<" "; cout<<"\n";

    bool flag=true;
    fr(i,1,n+1){
      if(b[i]!=ans[i]){
        flag=false;
        break;
      }
    }

    ll s1,s2;
    s1=s2=0;
    fr(i,1,n+1){
      s1+=ans[i];
      s2+=b[i];
    }

    if(!flag && s1!=s2){
      cout<<n<<"\n";
      fr(i,1,n+1) cout<<a[i]<<" "; cout<<"\n";
      fr(i,1,n+1) cout<<ans[i]<<" "; cout<<"\n";
      fr(i,1,n+1) cout<<b[i]<<" "; cout<<"\n\n";
      break;
    }
    else{
      cout<<"RIGHT\n";
    }
  }

  return 0;
}
