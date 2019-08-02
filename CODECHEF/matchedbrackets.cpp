#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin>>n;

  int i,b,status=0; // 0 means closed and 1 means open
  int depth=0,max_depth=0,length=0,max_length=0;
  int depth_pos=0,length_pos=0;

  for(i=0;i<n;i++){
    cin>>b;
    if(b==1 && status==0){
      status=1;
      depth++;
      length++;
    }
    else if(b==1 && status==1){
      depth++;
      length++;
    }
    else if(b==2 && depth<=1){
      length++;
      status=0;
      if(depth>max_depth){
        max_depth=depth;
        depth_pos=i;
      }
      if(length>max_length){
        max_length=length;
        length_pos=i-length+2;
      }
      depth=0;
      length=0;
    }
    else if(b==2 && depth>1){
      if(depth>max_depth){
        max_depth=depth;
        depth_pos=i;
      }
      depth--;
      length++;
    }
    else{
      cout<<"\nabc123\n";
    }
  }

  cout<<max_depth<<" "<<depth_pos<<" "<<max_length<<" "<<length_pos;

  return 0;
}
