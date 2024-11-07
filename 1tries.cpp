#include<bits/stdc++.h>
using namespace std;
class Trie;
class Node {

private:
    char data;
    unordered_map<char,Node*> children;
    bool isTerminal;
    int complete=0;
    int prefix=0;

public:
    Node(char d)
    {
        data=d;
        isTerminal=false;
        prefix=1;
        complete=0;
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
                it->prefix++;
                it=add->second;
            }
        }
        it->isTerminal=true;
        it->complete++;
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

    //  complete exact string
    int numberOfString(string str)
    {
        Node* it=root;
        for(int i=0;i<str.length();i++)
        {
            auto add=it->children.find(str[i]);
            if(add==it->children.end())//not found
            {
                return 0;
            }
            else// if element is already present
            {   
                it=add->second;
            }
        }
        return it->complete;
    }

};


int main()
{
    string str1="abcde";
    string str2="abde";
    Trie arr;
    arr.insert(str1);
    arr.insert(str2);
    arr.insert(str2);
    cout<<arr.numberOfString(str2);
    cout<<"DOEN";
    return 0;
}