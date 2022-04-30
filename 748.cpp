#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;

#define MAX 100000

string removeZero(string str){
	int i;
	for(i=str.size()-1;i>=0;--i){
		if(str[i] != '0'){
			str.erase(i+1,str.size()-1);
			break;
		}
	}
	return str;
}

int findNegative(string str){
	int res;
	res = str.size() - str.find('.') - 1;
	return res;
}

string removeDecimal(string str){
	str.erase(std::remove(str.begin(), str.end(), '.'), str.end());
	return str;
}

int multiply(int x,int res[],int res_size){
	int carry = 0;
	for (int i = 0; i < res_size; i++) {
	    int prod = res[i] * x + carry;
	 
	    // Store last digit of
	    // 'prod' in res[]
	    res[i] = prod % 10;
	 
	    // Put rest in carry
	    carry = prod / 10;
	}
	while (carry) {
	    res[res_size] = carry % 10;
	    carry = carry / 10;
	    res_size++;
	}
	return res_size;
}

string powerof(int x,int n){
	int res[MAX];
	int res_size = 0;
	int temp = x;
	string result;
 
	// Initialize result
	while (temp != 0) {
	    res[res_size++] = temp % 10;
	    temp = temp / 10;
	}
	 
	// Multiply x n times
	// (x^n = x*x*x....n times)
	for (int i = 2; i <= n; i++)
	    res_size = multiply(x, res, res_size);
	
	for (int i = res_size - 1; i >= 0; i--)
//	    cout << res[i];
		result += to_string(res[i]);
	return result;
}

int main(){
	string str,line,total_str,multi_str,num;
	int n,power,index,i;
	
	int total,total2;
	double multi;
	
	string arr[100][2];
	
	while(true){
		cin >> line >> num;
		if (line == "0" && num == "0")
			break;
		else {
			arr[index][0] = line;
			arr[index][1] = num;
			index += 1;
		}
	}
	
	for(i=0;i<index;i++){
		num = arr[i][1];
		n = stoi(num);
//		remove zero, change to fake integer 1.01 into 101, find 10^n
		str = arr[i][0];
		multi = stoi(str);
		multi = pow(multi,n);
		multi_str = to_string(multi);
		total2 = multi_str.find('.');
		
		str = removeZero(str);
		power = findNegative(str);
		str = removeDecimal(str);
		
		//calculate the power of int
		total = stoi(str);
		total_str = powerof(total,n);
	//	powerof(total,n);
	//	multi = stoi(powerof(power,n));
		
		total_str.insert(total2,".");
		cout << total_str << endl;
	}
	
	
//		n = stoi(num);
//		//remove zero, change to fake integer 1.01 into 101, find 10^n
//		multi = stoi(str);
//		multi = pow(multi,n);
//		multi_str = to_string(multi);
//		total2 = multi_str.find('.');
//		
//		str = removeZero(str);
//		power = findNegative(str);
//		str = removeDecimal(str);
//		
//		//calculate the power of int
//		total = stoi(str);
//		total_str = powerof(total,n);
//	//	powerof(total,n);
//	//	multi = stoi(powerof(power,n));
//		
//		total_str.insert(total2,".");
//		cout << total_str;
		
	return 0;	
}

