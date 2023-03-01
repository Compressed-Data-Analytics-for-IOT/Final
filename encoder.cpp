#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include"output.h"

using namespace std;

void print_Flags(vector<int>& v);
string Lcs(string& s1, string& s2, vector<int>& a, vector<int>& b);
void remaining_Data(string& s, vector<int>& flag);

ofstream outdata("encoded.txt");
set<string> dict;

void encoder(string &s1,string &s2, int n,int m)
{    
        string part1=s1;
        string part2=s2;
        
        vector<int> a(n, 0), b(m, 0);
       
        string lcs= Lcs(part1,part2,a,b);

        if (lcs == "")
        {
            return;
        }
        
       
        if (dict.find(lcs) == dict.end())
        {
            dict.insert(lcs);
            outdata << '0' << " ";
            outdata << lcs << " ";
           
            print_Flags(a);
           
            outdata << " ";
            print_Flags(b);
            outdata << " ";
            
            remaining_Data(part1, a);
            outdata<<" ";
           
            remaining_Data(part2, b);
            outdata<<" ";
            outdata<<endl;
        }
        else
        {
            outdata << '1' << " ";
            int index = 0;
            for (auto &e : dict)
            {
                if (e == lcs)
                {
                    break;
                }
                index++;
            }
            outdata << index << " ";
            print_Flags(a);
            outdata << " ";
            print_Flags(b);
            outdata << " ";
            remaining_Data(part1, a);
            outdata<<" ";
            remaining_Data(part2, b);
            outdata<<endl;
        }
}