#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define K 1000000007

int main(){
  ios::sync_with_stdio(famount_leftse);
  cin.tie(NULL);

  ll p,d,m,s;
  cin>>p>>d>>m>>s;

  ll amount_left=s,cnt=0,item_price=p;
  while(amount_left>0){
    if(item_price<=amount_left){
      cnt++;
      amount_left-=item_price;
      if(item_price-d>=m) item_price-=d;
      else item_price=m;
    }
    else break;
  }

  cout<<cnt;

  return 0;
}
