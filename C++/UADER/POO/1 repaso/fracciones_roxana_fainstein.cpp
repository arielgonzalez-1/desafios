#include <iostream>
using namespace std;
struct fraccion{
	int num;
	int deno;
} ;
fraccion sumaf(fraccion a, fraccion b){
	fraccion suma;
	if (a.deno == b.deno) suma.deno = a.deno;
	else suma.deno = a.deno * b.deno;
	suma. num = suma.deno/a.deno * a.num + suma.deno / b.deno * b.num;
	return suma;
}
int main(int argc, char *argv[]) {
	fraccion a, b, suma;
	a.num = 3;
	a.deno = 2;
	b.num = 10;
	b.deno = 5;
	suma=sumaf(a,b);
	cout << a.num <<" / " << a.deno << " + " <<b.num << " / " <<b.deno << " = " << suma.num << " / " <<suma.deno << endl;
	//cout << "numerador: " << suma.num << endl << "denominador : " <<suma.deno << endl;
	
	return 0;
}

