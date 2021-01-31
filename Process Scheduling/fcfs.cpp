// here we assume that the arrival time of all the processes is 0
// fcfs or first come first serve process scheduling uses a queue for allocating resources to a process

#include <iostream>
using namespace std;

static void calculateAvg(int burstTime[]){
    int waitTime[3]={0},tat[3]={0};
    waitTime[0]=0;
    for(int i=1;i<3;i++){
        waitTime[i]+=burstTime[i-1]+waitTime[i-1];
    }

    for(int i=0;i<3;i++){
        tat[i]=waitTime[i]+burstTime[i];
    }
    float avg_wt=0,avg_tat =0;

    for(int i=0;i<3;i++){
        avg_wt+=waitTime[i];
        avg_tat+=tat[i];
    }

    cout<<"Average waiting time = "<< avg_wt/3<<endl;
    cout<<"Average turn around time = "<< avg_tat/3<<endl;
}

int main(){
    int burstTime[3];
    cout<<"Enter burst times:"<<endl;

    for(int i=0;i<3;i++){
        cout<<"P["<<i+1<<"]: ";
        cin>>burstTime[i];
    }

    cout<<"\n For execution in P[1], P[2], P[3]"<<endl;
    calculateAvg(burstTime);

    cout<<"\n For execution in P[3], P[2], P[1]"<<endl;
    swap(burstTime[0],burstTime[2]);
     calculateAvg(burstTime);

    cout<<"\n For execution in P[3], P[1], P[2]"<<endl;
    swap(burstTime[1],burstTime[2]);
    calculateAvg(burstTime);

    return 0;
}
