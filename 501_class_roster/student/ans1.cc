#include<iostream>
#include<string>
#include<vector>
using namespace std;
void add(vector<string>& names, vector<char>& attendances){
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
int count(const vector<char>& attendances, char att){ return 0;}
void report(const vector<char>& attendances){}
void clear(vector<string>& names, vector<char>& attendances){}
//int count(const vector<char>& attendances, char att);
//void report(const vector<char>& attendances);
//void clear(vector<string>& names, vector<char>& attendances);
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