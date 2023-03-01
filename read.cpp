#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

vector<string> read_data() {
	vector<string>V1;
	ifstream file("TestData1.txt");
    string str;
    getline(file,str);
	
	string s="";
	for(int i=0;i<str.size();i++){
		  if(str[i]=='	' ||str[i]==' ')
		  {
			V1.push_back(s);
			s="";     
			
		  }
		  else{
			s+=str[i];
		  }
	}
	return V1;
}	