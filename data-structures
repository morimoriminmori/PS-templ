#include <bits/stdc++.h>
using namespace std;

int parent[1010101];

int Find(int x) {
  if (parent[x]==x)return x;
  return parent[x]=Find(parent[x]);
}

void Union(int x, int y){
  x = Find(x);
  y = Find(y);
  if (x>y){
    parent[x]=y;
  } else {
    parent[y]=x;
  }
}
