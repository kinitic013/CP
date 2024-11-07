#include<bits/stdc++.h>
using namespace std;
class Trie;
class Node {

private:
    char data;
    unordered_map<char,Node*> children;
    bool isTerminal;

public:
    Node(char d)
    {
        data=d;
        isTerminal=false;
    }
    friend class Trie;
};


class Trie {
private : 
    Node* root;
public :
    Trie()
    {
        root= new Node('\0');
    }

    //Insertion

    void insert(string str)
    {
        Node* it=root;
        for(int i=0;i<str.length();i++)
        {
            auto add=it->children.find(str[i]);   
            if(add==it->children.end())//not found
            {
                Node* ele= new Node(str[i]);
                it->children.insert({str[i],ele});
                it=ele;
            }
            else// if element is already present
            {   
                it=add->second;
            }
        }
        it->isTerminal=true;
    }

    // Search

    bool search(string str)
    {
        Node* it=root;
        for(int i=0;i<str.length();i++)
        {
            auto add=it->children.find(str[i]);
            if(add==it->children.end())//not found
            {
                return false;
            }
            else// if element is already present
            {   
                it=add->second;
            }
        }
        return it->isTerminal;
    }

};


int main()
{
    int n,x;cin>>n>>x;
    vector<int> arr(n);
    Trie T;
    for(int i=0;i<n;i++) 
    {
        cin>>arr[i];
        string str;
        int ele=arr[i];
        while(ele)
        {
            if(ele&1)
            str.push_back('1');
            else
            str.push_back('0');

        }
        while(str.size()!=32)
        {
            str.push_back('0');
        }
        reverse(str.begin(),str.end());
        T.insert(str);
    }
    return 0;
}