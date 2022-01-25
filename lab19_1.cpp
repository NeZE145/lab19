#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void test(string a ,vector<string> & b,vector<int> & c,vector<char> & D){
    ifstream fin(a);
    string textline;
    int i=0,erase;
    int k,l,m,grade;
    vector<string> e;
    vector<string> d;
    while(getline(fin,textline)){
        grade =0;
        e.push_back(textline);
        erase = e[i].find(":");
        d.push_back(e[i].substr(erase+2,e[i].size()));
        b.push_back(e[i].erase(erase));             
        sscanf(d[i].c_str(),"%d %d %d",&k,&l,&m);
        c.push_back(k+l+m);
        D[i].pish_back(score2grade(c[i]));
        i++; 
    }
}
void getCommand(string a,string b){
    string A;
    cout << "Please input your command: ";
    cin >> A;
    if(A=="EXIT"||A=="exit") a="exit";

}

void searchName(){

}

void searchGrade(){

}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
