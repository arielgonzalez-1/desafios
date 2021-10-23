#include <iostream>
using namespace std;
struct Fraccion{
	int num;
	int den;
};

int mcd(int a, int b){
	if(a>b){
		return (mcd(a-b,b));
	}
	if(a<b){
		return (mcd(a,b-a));
	}
	if(a==b){
		return a;
	}
	return 1;
}

Fraccion suma(Fraccion a, Fraccion b){
	Fraccion resSuma;
	int x=a.den*b.den;
	int y=(b.den*a.num)+(a.den*b.num);
	resSuma.num=y/mcd(x, y);
	resSuma.den=x/mcd(x, y);
	return resSuma;
}
	
int main(int argc, char *argv[]) {
	Fraccion f1;
	f1.num=3;
	f1.den=2;
	Fraccion f2;
	f2.num=10;
	f2.den=5;
	Fraccion fs=suma(f1,f2);
	cout<<fs.num<<endl;
	cout<<"-"<<endl;
	cout<<fs.den<<endl;
	return 0;
}

