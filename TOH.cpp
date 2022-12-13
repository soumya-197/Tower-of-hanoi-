#include <iostream>
using namespace std;
void TOH(int n,char source,char helper,char destination){
    if(n==1){
        cout<<"Put the plate from "<<source<<" to "<<destination<<endl;
    }
    else{
        TOH(n-1,source,destination,helper);
        cout<<"Put the plate from "<<source<<" to "<<destination<<endl;
        TOH(n-1,helper,source,destination);
    }
}
int main(){
    int plates;
    cout<<"Enter number of plates : ";
    cin>>plates;
    TOH(plates,'A','B','C');
    return 0;
}

