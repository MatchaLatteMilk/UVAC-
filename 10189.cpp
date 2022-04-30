#include <iostream>
#include <string>
using namespace std;


//Finished April 30, 2022 11:19PM
int main(){
	string arr[1000];
	int line,column,field = 0;
	string text;
	int i,j,k,index,num = 1;
	
	// take in inputs
	while(true){
		string res = "";
		
		cin >> line >> column;
		if(line == 0 && column == 0)
			break;
		
		for(i=0;i<line;i++){
			cin >> text;
			for(j=0;j<text.length();j++){
				if(text[j] == '.')
					text[j] = '0';
			}
			res += text;
		}
		arr[field] = to_string(line) + ",";
		field += 1;
		arr[field] = to_string(column) + ",";
		field += 1;
		arr[field] = res;
		field += 1;
	}
	
	//calculate and printout result put into temp
	for(index=0;index<field;index+=3){
		char temp[100][101];
		line = stoi(arr[index]);
		column = stoi(arr[index+1]);
		k = 0;
		//put into array
		for(i=0;i<line;i++){
			for(j=0;j<column;j++){
				temp[i][j] = arr[index+2][k];
				k++;
			}
		}
		//calculate *
		for(i=0;i<line;i++){
			for(j=0;j<column;j++){
				if(temp[i][j] == '*')
					for(int m=i-1;m<=i+1;m++)
						for(int n=j-1;n<=j+1;n++)
							if(temp[m][n] != '*')
								temp[m][n] += 1;
			}
		}
		//printout
		cout << "Field #" << num << ":" << endl;
		for(i=0;i<line;i++){
			for(j=0;j<column;j++){
				cout << temp[i][j];
			}
			cout << endl;
		}
		cout << endl;
		num++;
	}
	
	return 0;
}