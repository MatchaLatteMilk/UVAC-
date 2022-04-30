#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Finished May 1st, 2022 12:12 AM
//Check if palindome
string checkPalindrome(string line){
	int i;
	int size = line.size();
	for(i=0;i<size;i++)
		if(line[i] != line[size-i-1])
			return "Uh oh..";
	return "You won't be eaten!";
}

int main(){
	vector<string> data;
	string line,temp;
	int i;
	while(true){
		temp = "";
		getline(cin,line);
		if(line == "DONE")
			break;
		//remove symbols
		for(i=0;i<line.size();i++)
			if(line[i] >= 'a' && line[i] <= 'z' || line[i] >= 'A' && line[i] <= 'Z')
				temp += tolower(line[i]);
		data.push_back(temp);
	}
	//insert to func checkPalindrome
	for(string& n : data){
		cout << checkPalindrome(n) << endl;
	}
	
	return 0;
}
