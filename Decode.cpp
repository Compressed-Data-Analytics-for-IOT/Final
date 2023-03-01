#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "output.h"
using namespace std;

vector<string> read_data();
string decoder(string flag1, string flag2 ,string rem1, string rem2 , string lcs);

int main(){
    vector<string> V= read_data();
    ofstream outdata("decoded.txt");

    fstream innfile;

	innfile.open("encoded.txt");
    string str="";
    string lcs="",flag1="",flag2="",remainingPart1="",remainingPart2="";
	while(str!="11111")
    {
        
        getline(innfile,str);
        string s="";
        int counter=0;
        for(int i=0;i<str.size();i++){
            if(str[0]=='0'){
                if(str[i]==' '){
                    counter++;  
                    if(counter==2){
                        lcs=s;
                    }
                    if(counter==3){
                        flag1=s;
                    }
                    if(counter==4){
                        flag2=s;
                    }
                    if(counter==5){
                        remainingPart1=s;
                    }
                    if(counter==6){
                        remainingPart2=s;
                    }
                    s="";
                }
                else{
                    s+=str[i];
                }
            }
            
            else{
                if(str[i]==' '){
                    counter++;  
                    if(counter==2){
                        lcs=s;
                    }
                    if(counter==3){
                        flag1=s;
                    }
                    if(counter==4){
                        flag2=s;
                    }
                    if(counter==5){
                        remainingPart1=s;
                    }
                    if(counter==6){
                        remainingPart2=s;
                    }
                    s="";
                }
                else{
                    s+=str[i];
                }
            }
        
        }

        outdata << decoder(flag1,flag2,remainingPart1,remainingPart2,lcs)<<endl;

        flag1="";
        flag2="";  
        remainingPart1="";  
        remainingPart2="";  
        lcs="";  
        counter=0;
    }
    innfile.close();
    outdata.close();
}