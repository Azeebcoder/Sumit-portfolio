#include<iostream>
#include<fstream>
#include<string>
using namespace std;



bool check(int sudku[9][9],int val,int row,int col){
    if(sudku[row][col]!=0){
        return false;
    }
    for(int i=0;i<9;i++){
        if(val==sudku[row][i]){
            return false;
        }
        if(val==sudku[i][col]){
            return false;
        }
    }
    int a=((row/3)+1)*3;
    int b=((col/3)+1)*3;
    for(int i=a-3;i<a;i++){
        for(int j=b-3;j<b;j++){
            if(val==sudku[i][j]){
                return false;
            }
        }
    }
    return true;
}

bool sudkusolver(int sudku[9][9],int row,int col){
    if(row==8&&col==9){
        return true;
    }
    
    if(col==9){
        row=row + 1;
        col=0;
    }

    if(sudku[row][col]!=0){
        return sudkusolver(sudku,row,col+1);
    }

    for(int i=1;i<=9;i++){
        if(check(sudku,i,row,col)){
            sudku[row][col]=i;
            if(sudkusolver(sudku,row,col+1)){
                return true;
            }
        }
        sudku[row][col]=0;
    }

    return false;
}

string print(int sudku[9][9]){
    string ans="";
    ans = ans+"-------------------------------------\n";
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            char t=char(sudku[i][j])+48;
            if(sudku[i][j]==0) t=' ';
            ans = ans+"| " + t +" ";
        }
        ans = ans +"|\n";
        ans = ans+"-------------------------------------\n";
    }
    return ans;
}



int main(){
    int sudku[9][9];
    cout<<"For empty space enter '0' \nEnter sudku Elements\n";
    cout<<"-----------------"<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>sudku[i][j];
        }
        cout<<"-----------------"<<endl;

    }
    ofstream file("Solved_Sudku's.txt");
    file<<"Given Sudku \n\n"<<print(sudku);
    if(sudkusolver(sudku,0,0)){
        cout<<print(sudku);
        file<<"\n\nSolved sudku  \n\n"<<print(sudku);
    }
    else{
        cout<<"No solution avialable! ";
        file<<"No solution avialable! ";
    }
    return 0;
}