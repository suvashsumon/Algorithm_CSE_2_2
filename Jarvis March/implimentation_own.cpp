#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

vector<Point>points;
vector<int>flags;

int orientation(Point a, Point b, Point c)
{
    int val = (b.y-a.y)*(c.x-b.x)-(c.y-b.y)*(b.x-a.x);

    if(val == 0) return 0; // colinear
    else if(val > 0) return 1; // clockwise
    else return 2; // counterclockwise
}

bool convexHull(int n)
{
    if(n<3) return false;// there must be 3 points

    // initialy push all the value of flags -1
    for(int i=0; i<n; i++) flags.push_back(-1);

    // finding the leftmost result
    int left = 0;
    for(int i=1; i<n; i++)
    {
        if(points[i].x < points[left].x) left = i;
    }

    // travarse counterclockwise starting from left and ending at left
    int a, b;
    a = left;
    do
    {
        // search a point b such that the orientaion(a, i, b) is counterclockwise for all i
        b = (a+1)%n;
        for(int i=0; i<n; i++)
        {
            if(orientation(points[a], points[i], points[b])==2) b = i;
        }

        flags[a] = b;
        a = b;
    } while (a != left);
    return true;
}

int main()
{
    int n;
    Point point;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> point.x >> point.y;
        points.push_back(point);
    }
    bool result = convexHull(n);
    if(!result)
    {
        cout << "No convex hull exist for 2 points" << endl;
        return 0;
    }
    for(int i=0; i<n; i++)
    {
        if(flags[i] != -1)
        {
            cout << "(" << points[i].x << "," << points[i].y << ")" << endl;;
        }
    }
    return 0;
}