#include<bits/stdc++.h>

using namespace std;

typedef long int li;
#define loop(a,b) for(li i=a;i<b;i++)

struct Time{
  li a;
  li b;
};

bool cmp(struct Time i,struct Time j){
  return i.b>j.b;
}

int main(){
  li n;
  cin>>n;
  li x,y,z;
  struct Time t[n];
  loop(0,n){
    cin>>x>>y>>z;
    t[i].a=x;
    t[i].b=y+z;
  }

  sort(t,t+n,cmp);
  li c[n];
  loop(0,n){
    c[i]=t[i].a;
  }

  li sum=0,prv=0,mx=0;
  loop(0,n){
    //cout<<t[i].a<<" "<<t[i].b<<" "<<prv<<" ";
    sum=t[i].a+t[i].b+prv;
    prv+=t[i].a;
    //cout<<sum<<"\n";
    mx=max(mx,sum);
  }
  cout<<mx;
  return 0;
}
