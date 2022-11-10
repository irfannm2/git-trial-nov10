#include<iostream>
#include<math.h>
using namespace std;
#define pi 3.14159265

int main()
{
    double l1, l2, l3;
    l1 = 15;
    l2 = 25;
    l3 = 35;
    
    double x1, x2, x3;
    x1 = 7;
    x2 = 18;
    x3 = 27;
    
    double y1, y2, y3;
    y1 = 9;
    y2 = 29;
    y3 = 32;
    
    double a, b, Q1, Q2, Q3;
    Q1 = asin(y1/l1)*180/pi;
    a = asin((y2-y1)/l2)*180/pi;
    b = acos((x3-x2)/l3)*180/pi;
    Q2 = a - Q1;
    Q3 = b - a;
    
    cout<<"Sudut Q1: "<<Q1;
    cout<<"\nSudut Q2: "<<Q2;
    cout<<"\nSudut Q3: "<<Q3;
    
    /*
    note: perbedaan hasil Q dibelakang koma karena define pi pada code ini 
    lengkap 3,14159265. 
    Sedangkan pada jawaban yang ditulis di kertas hanya 3,14 saja.
    */
    
    return 0;
}