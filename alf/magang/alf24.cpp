#include <iostream>
#include<math.h>
using namespace std;
#define pi 3.1415

int main()
{
    double l1, l2, l3, l4, l5, l6, l7, Q1, cosQ2, Q2, Q3;
    l1 = 35.141;
    l2 = 95.008;
    l3 = 65;
    l4 = 12;
    l5 = 7;
    l6 = 57;
    l7 = 20;
    
    Q1 = asin(l5/l2);
    cosQ2 = ((l3*l3) + (l6*l6) - (l7*l7)) / (2*l3*l6);
    //cout<<Q2;
    Q2 = acos(cosQ2/pi)*180;
    Q3 = asin(l5/l4);
    
    cout<<"Sudut Q1: "<<Q1;
    cout<<"\nSudut Q2: "<<Q2;
    cout<<"\nSudut Q3: "<<Q3;
    
    return 0;
}