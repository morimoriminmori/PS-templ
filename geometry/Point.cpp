#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl "\n"
void __main();
const long long INF = 1e18;
int main(){
  fastio;
  __main();
  return 0;
}
#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x));x.erase(unique(all(x)), x.end())
#define F first
#define S second
#define mp make_pair
#define MAX 1000002
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884L
#define EPS 1e-9
#define loop while(1)
#define vi vector<ll>
#define i128 __int128
#define vpi vector<pii>
#define vvi vector<vector<ll>>
#define ld long double
bool is_zero(ld x) {return abs(x)<EPS;}
int is_sign(ld x){return x<-EPS?-1:x>EPS;}

struct Point {
  ld x,y;
  Point(ld x = 0, ld y = 0) : x(x), y(y){}
  Point operator + (const Point& o) const {return Point(x+o.x, y+o.y);}
  Point operator - (const Point& o) const {return Point(x-o.x, y-o.y);}
  Point operator * (const ld& o) const {return Point(x*o, y*o);}
  Point operator / (const ld& o) const {return Point(x/o, y/o);}
  ld operator * (const Point& o) const {return x * o.x + y * o.y;}
  ld operator / (const Point& o) const {return x * o.x - y * o.y;}
  Point operator - () const {return Point(-x, -y);}
  Point operator ~ () const {return Point(-y, x);}
  Point operator ! () const {return Point(y,x);}
  Point operator ^ (const Point& o) const {return Point(x*o.x,y*o.y);}
  bool operator == (const Point& o) const { return is_zero(x - o.x) && is_zero(y - o.y); }
  bool operator != (const Point& o) const { return !(*this == o); }
  bool operator < (const Point& o) const { return x < o.x || (is_zero(x - o.x) && y < o.y); }
  ld norm() const { return x * x + y * y; }
  ld abs() const { return sqrtl(norm()); }
  Point normalize() const {return is_zero(abs()) ? Point(0, 0) : *this / abs();}
  Point rotate(ld theta) const {return Point(x * cosl(theta) - y * sinl(theta), x * sinl(theta) + y * cosl(theta));}
  Point perp() const { return Point(-y, x); }
  ld angle() const { return atan2l(y, x); }
  ld dist(const Point& o) const { return (*this - o).abs(); }
  ld xy() const { return x * y; }
	Point rot(ld x) { return { x * cos(x) - y * sin(x), x * sin(x) + y * cos(x) }; }
  ld mag() const { return sqrt(mag2()); }
  ld mag2() const { return x * x + y * y; }
  ld dot(const Point&o) const { return x * o.x + y * o.y; }
	Point unit() const { return *this / mag(); }
	ld rad() const { return atan2(y, x); }
	friend ld rad(const Point& p1, const Point& p2) { return atan2l(p1 / p2, p1 * p2); }
  friend istream& operator >> (istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
  }
  friend ostream& operator << (ostream& os, Point& p ){
    os << p.x << " " << p.y;
    return os;
  }
};
