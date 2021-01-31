#include<iostream>
#include<queue> 
#include<vector>
#include<algorithm>
using namespace std;

class Process{
    public: 
   int pid;
   int arr;
   int burst;
   int comp;

   Process(int i, int b, int a){
       this->pid = i;
       this->burst = b;
       this->arr = a;
       this->comp = b;
   }
};

static bool compareArrival(Process p1, Process p2) 
{  
    return p1.arr < p2.arr;
}

static bool compareID(Process p1, Process p2) 
{  
    return p1.pid < p2.pid;
}

static void updateQueue(vector<Process> v, queue<Process> q, int t){
       for(int i = 0; i < v.size(); i++){

           queue<Process> tmp_q = q; //copy the original queue to the temporary queue
          bool found = false; 
          Process temp = v[i];
while (!tmp_q.empty()|| found == true )
{
    Process q_element = tmp_q.front();
    if(q_element.pid == temp.pid)
       found = true;
    tmp_q.pop();
} 
           if(!found && v[i].arr<=t && v[i].comp > 0){
               q.push(v[i]);
           }
       }
   }

   static void calculate(vector<Process> v, int ct[], int tat[], int wt[], int t){

       int n = v.size();

      int time = v[0].arr;
       queue<Process> q;
       q.push(v[0]);
       while (!q.empty()){
           Process current  = q.front();
           int temp = min(t, current.comp);
           time+=temp;
           current.comp-=temp;
           updateQueue(v, q, time);
           q.pop();
           if(current.comp > 0)
               q.push(current);
           else
               ct[current.pid] = time;

       }

       float sTat = 0;
       float sWt = 0;

       sort(v.begin(),v.end(),compareID);

       
       cout<<"\nPNo." << "\t"<<"AT" <<"\t"<<"BT" << "\t"<<"CT" <<"\t"<<"TAT" << "\t"<<"WT" << "\t";
       for (int i = 0; i < n; i++) {
           tat[i] = ct[i] - v[i].arr;
           wt[i] = tat[i] - v[i].burst;
           sTat += tat[i];
           sWt += wt[i];
          cout<<(i+1)<< "\t\t"<<v[i].arr << "\t"<< v[i].burst << "\t"<<ct[i] << "\t"<<tat[i] << "\t"<< wt[i] << "\t"<<endl;
       }
       cout<<"Average waiting time is: " <<sWt / n<<endl;
       cout<<"Average turn around time is: " << sTat / n<<endl;
       cout<<"-----------------------------------------------------------------------------------------------";
   }

int main(){
    int n;
    cout<<" Enter number of processes : ";
    cin>>n;
    int t;
    cout<< " Enter time quantum : ";
    cin>>t;
    int ct[n];
    int tat[n];
    int wt[n];

    vector<Process> proc;

    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time and burst time of process "<<i+1<<": ";
        int arr,burst;
        cin>>arr>>burst;
        Process process = Process(i+1,burst,arr);
        cout<<endl;
        proc[i] = process;
    }

    sort(proc.begin(),proc.end(),compareArrival);

    calculate(proc, ct, tat, wt, t);

}
