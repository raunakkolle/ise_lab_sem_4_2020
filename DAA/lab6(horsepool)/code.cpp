//Hello, this is a snippet.

#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int main()
{
    string text = "abcdefcoronaghijklmnopqrstuvwcoronapqrsxyprrzabcdefghijklmnopqrstuvwpqrsxyprrzabcdefghijklmnopqrstuvwpqrsxyprrzabcdefghijklmnopqrstuvwpqrsxyprrzabcdefghijklmnopqcoronarstuvwpqrsxyprrzabcdefghijcoronaklmnopqrstuvwpqrsxycoronaprrz";
    string pattern = "corona";
    vector<int> v(26,pattern.length());
    cout<<"String : "<<text<<endl<<"Pattern : "<<pattern<<endl;

    map<int, int> m; 

    int index  = 0;
    for (int i = 0; i < 256; ++i)
    {
        v.push_back(pattern.size());
    }
for (int i = 0; i < pattern.size()-2; ++i)
    {
        v[pattern[i]] = pattern.size() - i - 1;
        m[pattern[i]] = pattern.size() - i - 1;
    }


    while(index + pattern.size() < text.size()){
        for (int i = pattern.size()-1; i >= 0; i--)
        {   //cout<<pattern[i]<<":"<<text[index+i];
            if(pattern[i] != text[index+i]){
               // cout<<"   X  "<<v[text[index+i]]<<endl;
                index+=v[text[index+i]];
                break;
            }
            else{
               // cout<<"   V  "<<v[text[index+i]]<<endl;
                if(i==0){
                    printf("______FOUND_____%d\n",index );
                    index++;
                    break;
                }
            }
        }
    }




    

    // for (int i = 0; i < v.size(); ++i)
    // {
    //     cout<<v[i]<<",";
    // }



    return 0;
    
};
