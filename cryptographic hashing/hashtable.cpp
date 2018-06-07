#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int hashingDivisor= 23;

int hash(string s)
{
    int sum=0;
    for(int i=0;i<s.length();i++)
    {
        sum+=s[i];
    }
    //cout<<p<<endl;
	return sum%hashingDivisor;
}

typedef struct node
{
    string data;
    node *next;
} node;

int main() {

    node* head[hashingDivisor];
    for (int i = 0; i < hashingDivisor; ++i)
    {
    	head[i]=NULL;
    }
    node* temp;

    int t;
    cout<<"Enter number of words: ";
    cin>>t;
    cout<<"Enter "<<t<<" words: ";
    for (int i = 0; i < t; ++i)
    {

		string s;
		cin>>s;

		//cout<<s<<endl;
		//cout<<hash(s);
		int hashValue=hash(s);
		node* a=new node();
	    a->data=s;
	    a->next=NULL;
	    if(head[hashValue]==NULL)
	    {
	    	head[hashValue]=a;
	    }
	    else
	    {
	    	temp=head[hashValue];
	    	while(temp->next!=NULL)
	    		temp=temp->next;

	    	temp->next=a;
	    }

	}
    cout<<endl;
	for (int i = 0; i < hashingDivisor; ++i)
	{
		temp=head[i];
		cout<<i<<": ";;
		while(temp!=NULL)
        {
			cout<<temp->data<<", ";
            temp=temp->next;
        }
        cout<<endl;
	}
    return 0;
}

