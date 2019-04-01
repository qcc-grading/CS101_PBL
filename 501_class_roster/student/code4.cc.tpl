#include<iostream>
#include<string>
#include<vector>
using namespace std;
void add(vector<string>& names, vector<char>& attendances){}
int count(const vector<char>& attendances, char att)
{
    int c=0;
    for(size_t i=0;i<attendances.size();++i){
        if(attendances[i]==att) ++c;
    }
    return c;
}
void report(const vector<char>& attendances)
@@report@@
void clear(vector<string>& names, vector<char>& attendances){}
int main(){
    vector<string> names= {"A","B","C","D","E","F"};
    vector<char> attendances= {'A','A','L','E','E','E'};
    string choice="";
    do{
        cout<<"Attendance Roster"<<endl;
        cout<<"a. Add new students."<<endl;
        cout<<"b. Report the attendance."<<endl;
        cout<<"c. Clear the roster."<<endl;
        cout<<"d. Stop."<<endl;
        cout<<"Chooce one of choices(a,b,c,d):";
        cin>>choice;
        if(choice=="a")  add(names, attendances);
        else if(choice=="b") report(attendances);
        else if(choice=="c") clear(names, attendances);
    }while(choice != "d");
    cout<<"Bye."<<endl;
}