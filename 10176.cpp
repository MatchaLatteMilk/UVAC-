#include <iostream>
#include <string>
using namespace std;

//Finished May 1st, 2022 4:08 AM
int main(){
	char n;
	int number;
	//get first number as char
	while(cin >> n){
		number = n - '0';
		//every number after first will be change to decimal immediately
		while(cin >> n){
			if(n == '#')
				break;
			number = number * 2 + (n - '0');
			//number module 131071 to the intermediate result
			number %= 131071;
			cout << number;
		}
		//check if number divisable by 131071
		if(number%131071 == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
