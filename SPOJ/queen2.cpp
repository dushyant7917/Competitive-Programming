#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

struct point
{
 int x,y;
};

int X[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int Y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n,m;
char str[1005][1005];
int dist[1000][1000];

bool check(point t)
{
 if(t.x >=0 && t.x <n && t.y >=0 && t.y <m  && str[t.x][t.y] != 'X')
  return true;
 return false;
}

int main()
{
 int t;
 scanf("%d", &t);
 while(t--)
 {
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++)
   scanf("%s", str[i]);
  queue<point> q;
  point start, final;
  for(int i=0; i<n; i++)
  {
   for(int j=0; j<m; j++)
   {
    dist[i][j] = 0;
    if(str[i][j] == 'S')
    {
     start.x = i;
     start.y = j;
     dist[i][j] = 1;
    }
    else if(str[i][j] == 'F')
    {
     final.x = i;
     final.y = j;
    }
   }
  }
  q.push(start);
  while(!q.empty())
  {
   point temp = q.front();
   q.pop();
   cout<<"x:"<<temp.x<<" y:"<<temp.y<<"\n";
   for(int i=0; i<8; i++)
   {
    point copy = temp;
    copy.x += X[i];
    copy.y += Y[i];

    while(check(copy)){
      cout<<"nx:"<<copy.x<<" ny:"<<copy.y<<"\n";

     if(dist[copy.x][copy.y] == 0) {
      dist[copy.x][copy.y] = dist[temp.x][temp.y] + 1;
      q.push(copy);
     }

     else if(dist[copy.x][copy.y] != dist[temp.x][temp.y]+1){
       cout<<"Break\n";
       break;
     }

     cout<<"dist:"<<dist[copy.x][copy.y]<<"\n";

     copy.x += X[i];
     copy.y += Y[i];

    }

   }
   cout<<"\n";
  }
  cout << dist[final.x][final.y]-1 << endl;

 }
 return 0;
}
