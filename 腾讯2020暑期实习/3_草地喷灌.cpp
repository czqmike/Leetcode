/*** 
 * @Author: czqmike
 * @Date: 2021-04-18 20:25:54
 * @LastEditTime: 2021-04-18 22:07:13
 * @LastEditors: czqmike
 * @Description: 
 * Input:
 * 1 1 0 1.6 0
   Output:
   0.8 0 0.8
 * Result:
 * @FilePath: /腾讯2020暑期实习/3_草地喷灌.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <math.h>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

pair<double, double> mid(double x1, double y1, double x2, double y2) {
    return pair<double, double> ((x1 + x2) / 2, (y1 + y2) / 2);
}

int main() {
    double x1, y1, x3, y3, r1;
    cin >> r1 >> x1 >> y1 >> x3 >> y3;
    double x2 = 0, y2 = 0, r2 = 0;
    r2 = r1 + sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

    double x4 = x1 - fabs(x3 - x1);
    double y4 = y1 - fabs(y3 - y1);

    double eps = 10e-6;
    auto p = mid(x3, y3, x4, y4);
    x2 = p.first;
    y2 = p.second;
    while (distance(x2, y2, x3, y3) > r2 + eps) {
        pair<double, double> p1 = mid(x2, y2, x3, y3);
        pair<double, double> p2 = mid(x2, y2, x4, y4);
        if (distance(p1.first, p1.second, x4, y4) < distance(p2.first, p2.second, x4, y4)) {
            x2 = p1.first;
            y2 = p1.second;
        } else {
            x2 = p2.first;
            y2 = p2.second;
        }
    }
    printf("%.1f %.1f %.1f\n", x2, y2, r2);
    return 0;
}
