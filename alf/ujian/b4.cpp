#include<iostream>
#include<math.h>
using namespace std;
#define pi 3.14

double z1 = 1, z2 = 19, y = 4, l12 = 10, l23 = 9, a, Q1, Q2;

class invers{
	public:
    	void sudut(void){
    		Q1 = asin(y/z1)*180/pi;
            a = asin((z2-z1)/l12)*180/pi;
            Q2 = a - Q1;
        }
};

void print(){
    cout<<"Sudut Q1: "<<Q1;
    cout<<"\nSudut Q2: "<<Q2;
};

int main(){
	invers nilai;
	nilai.sudut();
	print();
}