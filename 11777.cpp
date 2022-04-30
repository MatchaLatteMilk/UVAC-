#include <iostream>
#include <vector>
using namespace std;

//Finished May 1st, 2022 12:32 AM
//Check n grade
string checkScore(int n){
	if(n >= 90)
		return "A";
	else if(n >= 80 && n < 90)
		return "B";
	else if(n >= 70 && n < 80)
		return "C";
	else if(n >= 60 && n < 70)
		return "D";
	else if(n < 60)
		return "F";
}

int main(){
	int i,T,term1,term2,final,att,ct1,ct2,ct3,tct,total;
	vector<int> data;
	cin >> T;
	for(i=0;i<T;i++){
		cin >> term1 >> term2 >> final >> att >> ct1 >> ct2 >> ct3;
		tct = (max(ct1,max(ct2,ct3)) + min(max(min(ct2,ct3),ct1),max(ct2,ct3)))/2;
		total = term1 + term2 + final + att + tct;
		data.push_back(total);
	}
	i=1;
	for(int& n : data){
		cout << "Case " << i <<": " << checkScore(n) << endl;
		i++;
	}
	return 0;
}
