#include<bits/stdc++.h>
using namespace std;

/*

lets say AB is the line segment and C is given point find shortest length between line AB to C


    C .           C .            C .
                    
                
         A ----------------- B



if(AB.BC > 0)  point C is close to B , then min len = distance(BC)

if(AB.AC < 0) (2nd quad)  point C close to A , then min = distance(AC)

else point is in between the line segment

    AB cross AC = AB*AC.sin 0
    AC.sin 0 = AB cross AC / AB = which is perpendicular distance of point C from AB segment


*/



class Point{
public:
    int x;
    int y;
};

double dot(Point p1 , Point p2){
    return (p1.x*p2.x) + (p1.y * p2.y);
}

int minDistance(Point a,Point b,Point c){

    //vector AB
    Point AB;
    AB.x = b.x - a.x;
    AB.y = b.y - a.y;

    //vector AC
    Point AC;
    AC.x = c.x - a.x;
    AC.y = c.y - a.y;

    //vector BC
    Point BC;
    BC.x = c.x - b.x;
    BC.y = c.y - b.y;

    //calculating dot products of the vectors
    double AB_AC = dot(AB , AC);
    double AB_BC = dot(AB , BC);

    double ans = 0;

    if(AB_AC < 0){ //second quad (cos -ve)
        ans = sqrt( (c.x - a.x)*(c.x - a.x) + (c.y - a.y)*(c.y - a.y) );
    }else if(AB_BC > 0){ //first quad (cos +ve)
        ans = sqrt( (c.x - b.x)*(c.x - b.x) + (c.y - b.y)*(c.y - b.y) );
    }else{
        double mod_AB = sqrt( (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y) );
        double cross_AB_AC = abs( (AB.x * AC.y) - (AC.x * AB.y) );
        ans = cross_AB_AC / mod_AB;
    }

    return ans;
}

int main()
{
    Point p1,p2,p3;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;
    cout << minDistance(p1,p2,p3) << endl;
    return 0;
}
