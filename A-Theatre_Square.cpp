#include<iostream>
using namespace std;
int  main()
{
    long long Length,Width;
    cin>>Length>>Width;
    long long Edge;
    cin>>Edge;
    long long Length_Counter=0;
    long long Width_Counter=0;
    if(Length%Edge==0)
    {
        Length_Counter=Length/Edge;
    }
    else
    {
        Length_Counter=Length/Edge+1;
    }
    if(Width%Edge==0)
    {
        Width_Counter=Width/Edge;
    }
    else
    {
        Width_Counter=Width/Edge+1;
    }
    cout<<Length_Counter*Width_Counter<<endl;
    return 0;
}
