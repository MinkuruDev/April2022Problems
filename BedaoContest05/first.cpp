#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 100000000 + 9;

struct Point{
    ll x, y;
    Point(ll x = 0, ll y = 0): x(x), y(y){}
    Point(vector<ll> v){
        x = v[0];
        y = v[1];
    }
    Point operator + (const Point &p) const{
        return Point(x + p.x, y + p.y);
    }
    Point operator - (const Point &p) const{
        return Point(x - p.x, y - p.y);
    }
    Point operator * (const ll &k) const{
        return Point(x * k, y * k);
    }
    Point operator / (const ll &k) const{
        return Point(x / k, y / k);
    }
    bool operator < (const Point &p) const{
        return x < p.x || (x == p.x && y < p.y);
    }
    bool operator == (const Point &p) const{
        return x == p.x && y == p.y;
    }
    bool operator != (const Point &p) const{
        return x != p.x || y != p.y;
    }
};

struct Line{
    Point p1, p2;
    Line(Point p1 = Point(), Point p2 = Point()): p1(p1), p2(p2){}
    Line(vector<Point> v){
        p1 = v[0];
        p2 = v[1];
    }
};

int orenitation(Point p1, Point p2, Point p3){
    ll x1 = p1.x - p2.x, y1 = p1.y - p2.y;
    ll x2 = p3.x - p2.x, y2 = p3.y - p2.y;
    ll r = (x1 * y2 - x2 * y1);
    if(r > 0) return 1;
    if(r < 0) return -1;
    return 0;
}

bool onSegment(Point p, Line l){
    return min(l.p1.x, l.p2.x) <= p.x && p.x <= max(l.p1.x, l.p2.x) &&
           min(l.p1.y, l.p2.y) <= p.y && p.y <= max(l.p1.y, l.p2.y);
}

bool isIntersect(Line l1, Line l2){
    int o1 = orenitation(l1.p1, l1.p2, l2.p1);
    int o2 = orenitation(l1.p1, l1.p2, l2.p2);
    int o3 = orenitation(l2.p1, l2.p2, l1.p1);
    int o4 = orenitation(l2.p1, l2.p2, l1.p2);
    if(o1 != o2 && o3 != o4) return true;
    if(o1 == 0 && onSegment(l1.p1, l2)) return true;
    if(o2 == 0 && onSegment(l1.p2, l2)) return true;
    if(o3 == 0 && onSegment(l2.p1, l1)) return true;
    if(o4 == 0 && onSegment(l2.p2, l1)) return true;
    return false;
}

bool isInside(Point p, vector<Line>& polygon){
    int n = polygon.size();
    int cnt = 0;
    Line l = Line(p, {INF, p.y});
    for(int i = 0; i < n; i++){
        if(orenitation(polygon[i].p1, polygon[i].p2, p) == 0)
            if(onSegment(p, polygon[i])) return true;
        if(isIntersect(l, polygon[i])) cnt++;
    }
    return cnt % 2 == 1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // set random seed
    srand(time(NULL));

    Point first, prev, cur;
    ll x, y;
    ll n, m;
    cin >> n >> m;

    vector<Line> lines(n);
    cin >> x >> y;
    first = Point(x, y);
    prev = first;
    for(int i = 1; i < n; i++){
        cin >> x >> y;
        cur = Point(x, y);
        lines[i] = Line(prev, cur);
        prev = cur;
    }
    lines[0] = Line(prev, first);

    for(int i = 0; i < m; i++){
        cin >> x >> y;
        cur = Point(x, y);
        if(isInside(cur, lines)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
