#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	node *next[26]={NULL};
	long count=0;
};
void traverse(string s,node *head);
void insert(string s,int pos,node *head);
vector<pair<long,string> >list;
int main()
{
	fstream x;
	string s;
	node *head=new node;
	x.open("AI.txt",ios::in);
	while(x>>s)
		insert(s,0,head);
	traverse("",head);
	sort(list.begin(),list.end(),greater<pair<long,string> >());
	vector<pair<long,string> >::iterator it;
	for(it=list.begin();it!=list.end();it++)
		cout<<(*it).second<<" "<<(*it).first<<endl;
	return 0;
}
void insert(string s,int pos,node *head)
{
	if(pos==s.length())
		head->count++;
	else if(s[pos]>=65 && s[pos]<=92)
	{
		if(head->next[s[pos]-65]==NULL)
			head->next[s[pos]-65]=new node;
		insert(s,pos+1,head->next[s[pos]-65]);
	}
	else if(s[pos]>=97 && s[pos]<=122)
	{
		if(head->next[s[pos]-97]==NULL)
			head->next[s[pos]-97]=new node;
		insert(s,pos+1,head->next[s[pos]-97]);
	}
}
void traverse(string s,node *head)
{
	if(head->count>0)
		list.push_back(make_pair(head->count,s));
	for(int i=0;i<26;i++)
		if(head->next[i])
			traverse(s+char(97+i),head->next[i]);
}
