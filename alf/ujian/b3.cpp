#include<iostream>
#include<math.h>
using namespace std;
#define pi 3.14

double z1 = 1, z2 = 21, z3 = 3, y = 8, l12 = 10, l23 = 9, l34 = 2, a, b, Q1, Q2, Q3;

class invers{
	public:
    	void sudut(void){
    		Q1 = asin(y/z1)*180/pi;
            a = asin((z2-z1)/l12)*180/pi;
            b = acos((z3-z2)/l23)*180/pi;
            Q2 = a - Q1;
            Q3 = b - a;
        }
};

void print(){
    cout<<"Sudut Q1: "<<Q1;
    cout<<"\nSudut Q2: "<<Q2;
    cout<<"\nSudut Q3: "<<Q3;
};

int main(){
	invers nilai;
	nilai.sudut();
	print();
}