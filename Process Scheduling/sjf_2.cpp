#include<iostream>
#include<algorithm>
#include<iomanip>
#include<climits>
using namespace std;

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int remaining_time;
};

static bool compareArrival(process p1, process p2) 
{ 
    return p1.arrival_time < p2.arrival_time;
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
        p[i].remaining_time =p[i].burst_time;
    }

    sort(p,p+n,compareArrival);

int complete = 0, timeLapsed = 0, minm = INT_MAX; 
    int shortest = 0, finish_time; 
    bool check = false; 
  
    while (complete != n) { 
  
        for (int j = 0; j < n; j++) { 
            if ((p[j].arrival_time <= timeLapsed) && 
            (p[j].remaining_time < minm) && p[j].remaining_time > 0) { 
                minm = p[j].remaining_time; 
                shortest = j; 
                check = true; 
            } 
        } 

        if (check == false) { 
            timeLapsed++; 
            continue; 
        } 
  
        p[shortest].remaining_time--; 
  
        // Update minimum 
        minm = p[shortest].remaining_time; 
        if (minm == 0) 
            minm = INT_MAX; 
  
        //process completed execution
        if (p[shortest].remaining_time == 0) { 
            complete++; 
            check = false; 
            finish_time = timeLapsed + 1; 
  
            // Calculate waiting time 
            p[shortest].waiting_time = finish_time - p[shortest].burst_time - p[shortest].arrival_time; 
            p[shortest].waiting_time < 0 ? p[shortest].waiting_time = 0 : p[shortest].waiting_time;
        } 
        timeLapsed++; 
    } 

    for(int i = 0; i < n; i++) {
        
        p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
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
