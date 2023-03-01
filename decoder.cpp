#include<iostream>
#include<string>

using namespace std;
string decoder(string flag1,string flag2,string rem1,string rem2,string lcs){

        for(int i=0;i<flag1.size();i++)
        {
           if(flag1[i]=='1')
            {
                flag1[i]='A';
            }
        }

        int i=0, j =0;
        while(i<rem1.size() && j<flag1.size())
        {
            if(flag1[j]=='0')
            {
                flag1[j] = rem1[i];
                j++;
                i++;
            }
            else if(flag1[j]=='A')
            {
                j++;
            }
        }
        j=0;
        for(int i=0;i<flag1.size();i++)
        {
            if(flag1[i]!='A')
            {
                continue;
            }
            else
            {
                flag1[i] = lcs[j];
                j++;
            }
        }        

         for(int i=0;i<flag2.size();i++)
        {
           if(flag2[i]=='1')
            {
                flag2[i]='A';
            }
        }
        int a=0, b =0;
        while(a<rem2.size() && b<flag2.size())
        {
            if(flag2[b]=='0')
            {
                flag2[b] = rem2[a];
                b++;
                a++;
            }
            else if(flag2[b]=='A')
            {
                b++;
            }
        }
        b=0;
        for(int a=0;a<flag2.size();a++)
        {
            if(flag2[a]!='A')
            {
                continue;
            }
            else
            {
                flag2[a] = lcs[b];
                b++;
            }
        }    
        
        return flag1+flag2;
    }
