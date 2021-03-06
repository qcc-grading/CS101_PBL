#include<iostream>
#include<string>
#include<vector>
using namespace std;
void add(vector<string>& names, vector<char>& attendances);
int count(const vector<char>& attendances, char att);
void report(const vector<char>& attendances);
void clear(vector<string>& names, vector<char>& attendances);
int main(){
    vector<string> names;
    vector<char> attendances;
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
void add(vector<string>& names, vector<char>& attendances)
{
    string choice;
    do{
        string name="";
        char att='\0';
        cout<<"Type the name of student:";
        cin>>name;
        cout<<"Type the record of attendances(A,L,E,P):";
        cin>>att;
        names.push_back(name);
        attendances.push_back(att);
        cout<<"Do you want to add more students?(y/n):";
        cin>>choice;
    }while(choice=="y");
}
int count(const vector<char>& attendances, char att)
{
    int c=0;
    for(size_t i=0;i<attendances.size();++i){
        if(attendances[i]==att) ++c;
    }
    return c;
}
void report(const vector<char>& attendances)
{
    static const vector<string> desc={"absent","late","excused","present"};
    static const vector<char> atts={'A','L','E','P'};
    if(attendances.size()==0){
        cout<<"There is no student."<<endl;
        return;
    }
    for(size_t i=0;i<4;++i){
        cout<<"The number of "<<desc[i]<<" students is "<<count(attendances,atts[i])<<"."<<endl;
    }
}
void clear(vector<string>& names, vector<char>& attendances)
{
    names.clear();
    attendances.clear();
    cout<<" All of records were cleared."<<endl;
}