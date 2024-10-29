#include<iostream>
#include<string>
using namespace std;
string dualnum(long long int);
string last(long long int n) {
    string arr[]= {"Hundred ","Thousand ","Lakh ","Crore "};
    int nums[]= {100,1000,100000,10000000};
    int f;
    string ans;
    while(n>=100) {
        for(int i=3; i>=0; i--) {
            if(n>=nums[i]) {
                f=i;
                break;
            }
        }
        int number=n/nums[f];
        n=n%nums[f];
        string first=dualnum(number);
        ans=ans+first+arr[f];
    }
    if(n>0) {
        ans=ans+dualnum(n);
    }
    return ans;
}
string dualnum(long long int n) {
    string arr[]= {"Zero ","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ","Ten ","Eleven ","Twelve ","Thirten ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};
    string arr2[]= {"Twenty ","Thirty ","Fourty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninty "};
    int num[]= {20,30,40,50,60,70,80,90};
    string ans;
    if(n==0) return arr[0];
    int flag=-1,f=0;
    while(n>0) {
        if(n>=100) {
            return last(n);
        }
        if(n<=19) {
            f=n;
            n=0;
        }
        else {
            for(int i=7; i>=0; i--) {
                if(n>=num[i]) {
                    flag=i;
                    n=n-num[i];
                    if(n==0) {
                        return arr2[flag];
                    }
                    break;
                }
            }
        }

    }
    if(flag==-1) {
        return arr[f];
    }
    ans=arr2[flag]+arr[f];

    return ans;
}

int main() {
    long long int n;
    cout<<"Enter number : ";
    cin>>n;
    cout<<"\n\n"<<last(n)<<"\n\n";
    return 0;
}