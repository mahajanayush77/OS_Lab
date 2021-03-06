#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

static bool compareArrival(process p1, process p2) 
{ 
    return p1.arrival_time < p2.arrival_time;
}

static bool compareBurstTime(process p1, process p2) 
{ 
    return p1.burst_time < p2.burst_time;
}

int main() {

    int n;
    struct process p[10];
    float avg_turnaround_time;
    float avg_waiting_time;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;

    cout << setprecision(2) << fixed;

    cout<<"Enter the number of processes: ";
    cin>>n;

    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].arrival_time;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].burst_time;
        p[i].pid = i+1;
        cout<<endl;
    }

    sort(p,p+n,compareArrival);
    sort(p,p+n,compareBurstTime);

    for(int i = 0; i < n; i++) {
        p[i].start_time = (i == 0)?p[i].arrival_time:max(p[i-1].completion_time,p[i].arrival_time);
        p[i].completion_time = p[i].start_time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;

        total_turnaround_time += p[i].turnaround_time;
        total_waiting_time += p[i].waiting_time;
    }

    avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n;


   cout<<"Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n"; 

   for(int i=0;i<n;i++){
       cout<<p[i].pid<<"\t\t"<<p[i].arrival_time<<"\t\t"<<p[i].burst_time<<"\t\t"<<p[i].waiting_time<<"\t\t"<<p[i].turnaround_time<<"\n"; 
   }

    cout<<"\nAverage Turnaround Time = "<<avg_turnaround_time<<endl;
    cout<<"Average Waiting Time = "<<avg_waiting_time<<endl;

return 0;
}
