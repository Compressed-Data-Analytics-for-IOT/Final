#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<string> read_data();
void encoder(string &s1,string &s2, int n,int m);

int main()
{   
    vector<string> V = read_data();
    string s1="",s2="";   
    int counter1=0,counter2=16;
    V.push_back("0");
    for(int i=0;i<V.size();i++){
        if(counter2!=32 && counter1==16)
        {
            s2+=V[i];
            counter2++;
        }
        if(counter1!=16){
            s1+=V[i];
            counter1++;
        }
        
        if(counter2==32 && counter1==16){
            counter1=0;
            counter2=16;
            encoder(s1,s2,s1.size(),s2.size());
            cout<<s1<<"  "<<s2<<endl;
            s1="";
            s2="";
        }
    }
    return 0;
}
