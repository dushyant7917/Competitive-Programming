#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
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

ll n,sum;
ll arr[N];

ll FP(ll i,ll a,ll b,ll c){
  if(i==n){
    if(a==sum && b==sum && c==sum) return 1;
    else return 0;
  }

  return FP(i+1,a+arr[i],b,c)+FP(i+1,a,b+arr[i],c)+FP(i+1,a,b,c+arr[i]);
}

ll FZ(ll i,ll a,ll b,ll c,ll s1,ll s2,ll s3){
  if(i==n){
    if(a==sum && b==sum && c==sum && s1 && s2 && s3) return 1;
    else return 0;
  }

  return FZ(i+1,a+arr[i],b,c,s1+1,s2,s3)+FZ(i+1,a,b+arr[i],c,s1,s2+1,s3)+FZ(i+1,a,b,c+arr[i],s1,s2,s3+1);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  fr(i,0,n) cin>>arr[i];

  sum=0;
  fr(i,0,n) sum+=arr[i];

  if(sum%3==0){
    sum=sum/3;
    if(sum==0) cout<<FZ(0,0,0,0,0,0,0);
    else cout<<FP(0,0,0,0);
  }
  else cout<<0;

  return 0;
}
