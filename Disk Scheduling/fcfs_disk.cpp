#include <iostream>
using namespace std;

int main(){
    
    int n,seek=0;
    cout<<"Enter size of queue request : ";
    cin>>n;

    int queue[n+1];
    cout<<"Enter the request queue : ";
    for(int i=1;i<=n;i++)
       cin>>queue[i];
    
    cout<<"Enter the head : ";
    cin>>queue[0];

    for(int j=0;j<n;j++){
        seek += abs(queue[j+1]-queue[j]);
        cout<<"Serviced request from "<<queue[j]<<" to "<<queue[j+1]<<" seek is "<<abs(queue[j]-queue[j+1])<<endl;
    }

    float avg_seek = seek/n;

    cout<<"Average seek time is "<<avg_seek<<endl;

    return 0;
}
// 98,183,37,122,14,124,65,67