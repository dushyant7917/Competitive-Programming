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

struct Date{
    string n;
    ll ind;
    ll diff;
};

bool cmp(struct Date d1,struct Date d2){
    if(d1.diff==d2.diff) return d1.ind>d2.ind;
    else return d1.diff<d2.diff;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

    ll n;
    cin>>n;
    struct Date a[n];
    ll d,j;

    fr(i,0,n){
      cin>>a[i].n>>d>>j;
      a[i].ind=i;
      a[i].diff=j-d;
    }

    sort(a,a+n,cmp);

    cout<<a[n-1].n<<" "<<a[n-1].diff;

  return 0;
}
