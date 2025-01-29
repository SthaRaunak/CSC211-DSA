// Program to find nth fibonacci

#include<iostream>

using namespace std;

int fib(int n);

int main() {
	int n;
	cout << "Enter the value of n" << endl;
	cin >> n;
	cout << "nth fibonacci : " << fib(n) << endl;
	
	//for(int i  = 1 ; i <= 20; i++){
	//	cout << fib(i) << endl;
	//}

	return 0;
}


int fib(int n){
	if(n == 1) 
		return 0;
	if(n == 2)
		return 1;

	return fib(n-1) + fib(n-2);
}





