#include<bits/stdc++.h>
using namespace std;

int lps[1000];

void lpsarray(string ptrn)
{
    lps[0] = 0;
    int k=1, len=0, len_p=ptrn.length();

    while(k < len_p)
    {
        if(ptrn[k]==ptrn[len]) lps[k++] = ++len;
        else{
            if(len>0) len = lps[len-1];
            else lps[k++] = 0;
        }
    }
}

void kmp(string text, string ptrn)
{
    int i=0, j=0;
    while(i<text.length())
    {
        if(text[i]==ptrn[j])
        {
            i++, j++;
        }
        else
        {
            if(j!=0) j = lps[j-1];
            else i++;
        }

        if(j==ptrn.length())
        {
            cout << "found at " << i-ptrn.length() << endl;
        }
    }
}

int main()
{
    string ptrn, text;
    int n;
    cin >> n;
    cin >> text >> ptrn;
    lpsarray(ptrn);
    kmp(text, ptrn);
    return 0;
}