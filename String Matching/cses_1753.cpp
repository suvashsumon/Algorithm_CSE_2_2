#include<bits/stdc++.h>
using namespace std;
#define MX 1000000
string text;
string pattern;
int lps[MX];
int counter = 0;

void lps_array()
{
    int pattern_size = pattern.size();
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while(i<pattern_size)
    {
        if(pattern[i]==pattern[len])
        {
            lps[i] = len+1;
            len++;
            i++;
        }
        else
        {
            if(len!=0) len = lps[len-1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp()
{
    int m = pattern.size();
    int n = text.size();

    lps_array();

    int i=0, j=0; // i -> text   || j -> pattern
    while(i<n)
    {
        if(pattern[j]==text[i])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            counter++; // got a match
            j = lps[j-1]; // for continue the search, we can stop at here by break;
        }
        else if(i<n && pattern[j]!=text[i])
        {
            if(j!=0) j = lps[j-1];
            else i++;
        }
    }
}

int main()
{
    getline(cin, text);
    getline(cin, pattern);
    kmp();
    //for(int i=0; i<pattern.size(); i++) cout << lps[i] << " ";
    cout << counter;
    return 0;
}