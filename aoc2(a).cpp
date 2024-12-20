#include<bits/stdc++.h>
using namespace std;
int main(){

    int count=0;
    int i=0;
    while(i<1000){
        vector<int> list;
        int num=0;
        char c;
        while ((c = getchar()) != '\n' && c != EOF) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } 
            else if (c == ' ') {
                list.push_back(num);
                num = 0;
            }
        }
        list.push_back(num);
        int len=list.size();
        bool inc=1;
        if(list[1]<list[0]){
            inc=0;
        }
        bool flag=1;
        for(int i=0;i<len-1;i++){
            if(inc==1){
                if(list[i+1]-list[i]<1||list[i+1]-list[i]>3){
                    flag=0;
                    break;
                }
            }
            else{
                if(list[i]-list[i+1]<1||list[i]-list[i+1]>3){
                    flag=0;
                    break;
                }
            }
        }
        if(flag==0){
            i++;
            continue;
        }
        else{
            count++;
            i++;
        }
    }
    cout<<count<<endl;

    return 0;
}