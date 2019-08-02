#include<bits/stdc++.h>

using namespace std;

typedef long int li;
#define loop(a,b) for(li i=a;i<b;i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  li m;
  cin>>m;
  vector<li> min_b;
  loop(0,m){
    li b1,b2;
    cin>>b1>>b2;
    min_b.push_back(min(b1,b2));
  }
  sort(min_b.begin(),min_b.end());
  li h=0;
  loop(0,m){
    if(min_b[i]==h){
      //do nothing
    }
    else{
      h++;
    }
  }
  cout<<h;

  return 0;
}
