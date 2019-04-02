#include<iostream>
#include<string>
#include<vector>
using namespace std;
void add(vector<string>& names, vector<char>& attendances){}
int count(const vector<char>& attendances, char att)
@@count@@
void report(const vector<char>& attendances){}
void clear(vector<string>& names, vector<char>& attendances){}
int main(){
    vector<string> names= {"A","B","C","D","E","F"};
    vector<char> attendances= {'A','A','L','E','E','E'};
    if(count(attendances,'A')==2 && count(attendances,'L')== 1 && count(attendances,'E')==3 && count(attendances,'P')==0 ) cout<<"Success";
    else cout<<"Failure";
    return 0;
}