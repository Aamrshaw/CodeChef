
#include <bits/stdc++.h>
using namespace std;

vector<string> subs;
int freq[26];
char scs[26];
vector<pair<int,int> >be;
vector<int> spv;
set<int> sp;
set<int>::iterator it;
vector<int>:: iterator it1,it2;

int isPalin(string& str)
{
	string s1,s2;
  s1=s2=str;
  reverse(s2.begin(), s2.end());
  if(s1==s2)
  {
    //cout<<str<<" palin ";
    return 1;
  }
  else
    return 0;
}
void CharWithFreq(string str)
{
    int n = str.size();
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++)
        freq[str[i] - 'a']++;
    int j=0;
    for(int i=0;i<26;i++)
    {
        if(freq[i]==1)
        scs[j++]=(i+'a');
    }
}
void subString(string s, int n)
{
    string str;
    int flag,slen;
    for (int i = 0; i < n; i++)
        for (int len = 1; len <= n - i; len++)
        {
            //cout << s.substr(i, len) << endl;
            flag=2;
            str=s.substr(i, len);
            slen=str.length();
            if(slen==n)
            flag=0;
            else
            {
                for(int i=0;i<strlen(scs);i++)
                {
                    size_t found = str.find(scs[i]);
                    if (found != string::npos)
                    {
                        flag--;
                        //cout<<scs<<"-\n";
                        if(slen==1)
                            flag=0;
                    }
                    if(flag==0)break;
                }
            }
            if(flag)
            {
                subs.push_back(str);
                be.push_back(make_pair(i,(i+len-1)));
                sp.insert(i);
                spv.push_back(i);
            }
        }
}
int main()
{
	string s,s1,s2,cmbs,str="abcdba",sfc;
	cin>>s;
	//isPalin(str) ;
	CharWithFreq(s);
	//cout<<sfc<<"\n";
	int i,j,len,c=0;
	len=s.length();
	subString(s,s.length());
	//for(int i=0;i<subs.size();i++)
	//cout<<be[i].first<<":"<<be[i].second<<"-"<<subs[i]<<endl;
	for(it=sp.begin();it!=sp.end();it++)
        cout<<*it<<", ";
    cout<<endl;
	it1=spv.begin();
	for(int i=0;i<subs.size();i++)
	{
	    cout<<i<<". "<<be[i].first<<":"<<be[i].second<<"-"<<subs[i]<<" ";
	    int k=be[i].second;
	    do{
                k++;
	    it=sp.find(k);
	    }while(sp.count(k)!=1 || it!=sp.end());
	    //it++;
	    cout<< *it<<" ";
	    it2=find(spv.begin(),spv.end(),*it);
	    cout<<it2-it1<<endl;
	    for(int j=it2-it1;j<subs.size();j++)
	    {
	        if(be[j].first>be[i].second)
            {
                cmbs=subs[i]+subs[j];
                if(isPalin(cmbs)){
                    cout<<subs[i]<<" "<<subs[j]<<"\n";
                    c++;
                }
	        }
	    }
	}
	cout<<c<<"\n";
	return 0;
}
