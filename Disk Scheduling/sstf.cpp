#include <iostream>
using namespace std;

int main(){
    
    int n,seek=0;
    cout<<"Enter size of queue request : ";
    cin>>n;

    int queue[n+1],done[n+1];
    cout<<"Enter the request queue : ";
    for(int i=1;i<=n;i++){
       cin>>queue[i];
       done[i] = 0;
    }
    cout<<"Enter the head : ";
    cin>>queue[0];

    int head=queue[0];
    int count=0,j,sum=0;
    cout<<head<<"->";

    // all requests serviced
    while(count!=n){
    int temp=100000;
    int k=-1;
    for(j=1;j<=n;j++){
        if(head!=queue[j] && done[j]==0){
        if(temp>abs(head-queue[j])){
           temp = abs(head-queue[j]);
           k = j;
           }
        }
    }
    sum+=temp;
    cout<<queue[k]<<"->";
    count++;
    head=queue[k];
    done[k]=1; // request serviced
    }

    cout<<endl;
    cout<<"total seek count is="<<sum<<endl;

    return 0;
}
// 98,183,37,122,14,124,65,67