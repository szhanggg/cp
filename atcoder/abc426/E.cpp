#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif
 
template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}
 template<typename T>
struct Point {
    T x, y;
    Point(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    template<typename S> Point(const Point<S> &p) : x((T) p.x), y((T) p.y) {}
    Point operator + (const Point &other) const {return Point(x + other.x, y + other.y);}
    Point operator - (const Point &other) const {return Point(x - other.x, y - other.y);}
    Point operator * (T c) const {return Point(x * c, y * c);}
    Point operator / (T c) const {return Point(x / c, y / c);}
    Point& operator += (const Point &other) {return *this = *this + other;}
    Point& operator -= (const Point &other) {return *this = *this - other;}
    Point& operator *= (T c) {return *this = *this * c;}
    Point& operator /= (T c) {return *this = *this / c;}
    bool operator < (const Point &other) const {return tie(x, y) < tie(other.x, other.y);}
    bool operator <= (const Point &other) const {return tie(x, y) <= tie(other.x, other.y);}
    bool operator > (const Point &other) const {return tie(x, y) > tie(other.x, other.y);}
    bool operator >= (const Point &other) const {return tie(x, y) >= tie(other.x, other.y);}
    bool operator == (const Point &other) const {return tie(x, y) == tie(other.x, other.y);}
    bool operator != (const Point &other) const {return tie(x, y) != tie(other.x, other.y);}
    T mag2() const {return x * x + y * y;}
    double mag() const {return sqrt(mag2());}
    Point unit() const {return *this / mag();}
    Point perp() const {return Point(-y, x);}
    Point normal() const {return perp().unit();}
    double angle() const {return atan2(y, x);}
    Point rot(double ang) const {return Point(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang));}
    friend T dot(const Point &a, const Point &b) {return a.x * b.x + a.y * b.y;}
    friend T cross(const Point<T> &a, const Point<T> &b) {return a.x * b.y - a.y * b.x;}
    friend T dist2(const Point<T> &a, const Point<T> &b) {return (a - b).mag2();}
    friend double dist(const Point<T> &a, const Point<T> &b) {return (a - b).mag();}
    friend T ccw(const Point<T> &a, const Point<T> &b, const Point<T> &o) {return cross(a - o, b - o);}
    friend double angle(const Point<T> &a, const Point<T> &b) {return abs(atan2(cross(a, b), dot(a, b)));}
    friend Point<T> rot(const Point<T> &p, const Point<T> &o, double ang) {return o + (p - o).rot(ang);}
    friend ostream& operator << (ostream &os, const Point &p) {return os << "(" << p.x << ", " << p.y << ")";}
};

template<typename T>
struct Line {
    Point<T> a, b, ab;

    Line() {}

    Line(const Point<T> &_a, const Point<T> &_b) : a(_a), b(_b), ab(b - a) {}

    // ax + by = c
    Line(T _a, T _b, T _c) : ab(_b, -_a) {
        if (_a != 0) a = b = Point<T>(_c / _a, 0);
        else if (_b != 0) a = b = Point<T>(0, _c / _b);
        else if (_c == 0) a = b = Point<T>();
        else a = b = Point<T>(numeric_limits<T>::max(), numeric_limits<T>::max());
    }

    friend bool onLine(const Point<T> &p, const Line &l) {
        if (l.a == l.b) return p == l.a;
        return cross((p - l.a), l.ab) == 0;
    }

    friend bool onSegment(const Point<T> &p, const Line &s) {
        if (s.a == s.b) return p == s.a;
        Point<T> va = s.a - p, vb = s.b - p;
        return cross(va, vb) == 0 && dot(va, vb) <= 0;
    }

    friend bool intersectLine(const Line &s, const Line &t, Point<double> &p) {
        T w = cross(s.ab, t.ab);
        if (w == 0) {
            p = Point<double>(numeric_limits<double>::max(), numeric_limits<double>::max());
            return onLine(s.a, t);
        }
        p = Point<double>(s.ab * (cross(t.a, t.ab) + cross(t.ab, s.a))) / (double) w + s.a;
        return true;
    }

    friend bool intersectSegment(const Line &s, const Line &t, Point<double> &p) {
        T w = cross(s.a - s.b, t.a - s.b), x = cross(s.a - s.b, t.b - s.b), y = cross(t.a - t.b, s.a - t.b), z = cross(t.a - t.b, s.b - t.b);
        if ((w > 0) != (x > 0) && (y > 0) != (z > 0))
            return intersectLine(s, t, p);
        if (w == 0 && onSegment(t.a, s)) {
            p = t.a;
            return true;
        }
        if (x == 0 && onSegment(t.b, s)) {
            p = t.b;
            return true;
        }
        if (y == 0 && onSegment(s.a, t)) {
            p = s.a;
            return true;
        }
        if (z == 0 && onSegment(s.b, t)) {
            p = s.b;
            return true;
        }
        return false;
    }

    friend double distLine(const Point<T> &p, const Line &l) {
        if (l.a == l.b) return dist(p, l.a);
        return abs(cross(p - l.a, l.ab)) / l.ab.mag();
    }

    friend double distSegment(const Point<T> &p, const Line &s) {
        if (dot(p - s.a, s.ab) <= 0) return dist(p, s.a);
        if (dot(p - s.b, s.ab) >= 0) return dist(p, s.b);
        return distLine(p, s);
    }

    friend Point<T> proj(const Point<T> &p, const Line &l) {
        Point<T> ret = l.a;
        if (l.a != l.b) ret += l.ab * dot(p - l.a, l.ab) / l.ab.mag2();
        return ret;
    }

    friend Point<T> reflect(const Point<T> &p, const Line &l) {
        return proj(p, l) * 2 - p;
    }

    friend ostream& operator << (ostream &os, const Line &l) {
        return os << "<" << l.a.x << ", " << l.a.y << "> + t<" << l.ab.x << ", " << l.ab.y << ">";
    }
};

double solve() {
    
    double tsx, tsy, tgx, tgy, asx, asy, agx, agy;

    cin >> tsx >> tsy >> tgx >> tgy >> asx >> asy >> agx >> agy;

    double tlen = sqrt(pow(tgx-tsx, 2) + pow(tgy-tsy, 2));
    double alen = sqrt(pow(agx-asx, 2) + pow(agy-asy, 2));
    if(alen < tlen) {
        swap(asx, tsx);
        swap(asy, tsy);
        swap(agx, tgx);
        swap(agy, tgy);
        swap(alen, tlen);
    }

    // t is the shorter segment

    // figure out what a is when t stops moving

    double tux = (tgx-tsx)/tlen;
    double tuy = (tgy-tsy)/tlen;
    double aux = (agx-asx)/alen;
    double auy = (agy-asy)/alen;

    int bsx = tsx-asx;
    int bsy = tsy-asy;

    Line<double> l1 = Line<double>(Point<double>(bsx, bsy), Point<double>(bsx+(tux-aux)*tlen, bsy+(tuy-auy)*tlen));

    double ans = distSegment(Point<double>(0, 0), l1);

    // now just the segment with a fixed

    double asxnew = asx + aux*tlen;
    double asynew = asy + auy*tlen;

    Line<double> l2 = Line<double>(Point<double>(asxnew-tgx, asynew-tgy), Point<double>(agx-tgx, agy-tgy));

    ans = min(ans, distSegment(Point<double>(0, 0), l2));

    return ans;

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    cout << fixed << setprecision(9);
    while(t--) {
        cout << solve() << "\n";
    }
}
