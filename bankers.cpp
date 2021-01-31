#include<iostream>
using namespace std;
int main()
{
	int proc;
    cout<<"Enter the number of processes "<<endl;
	cin>>proc;
    cout<<"Enter the number of resources :"<<endl;
	int res;
	cin>>res;
	int allocation[proc][res];
	int max[proc][res];
	int need[proc][res];
	int available[res];
	int finish[proc];
    for(int j=0;j<proc;j++)
	finish[j]=0;
	int deadlock=0; // 0 means safe state else 1 is for unsafe state

    cout<<"Enter the Allocation matrix "<<endl;
	for(int i=0;i<proc;i++)
	{   cout<<"P"<<i<<" :  ";
		for(int j=0;j<res;j++)
		{
			cin>>allocation[i][j];		
		}
	}

     cout<<"Enter the Maximum matrix "<<endl;
	for(int i=0;i<proc;i++)
	{
        cout<<"P"<<i<<" :  ";
		for(int j=0;j<res;j++)
		{
			cin>>max[i][j];		
			need[i][j] = max[i][j]- allocation[i][j];
		}
	}

    cout<<"Enter the available instances"<<endl;
	for(int j=0;j<res;j++){
        cout<<"R"<<j+1<<" : ";
	cin>>available[j];
    }

    cout<<"The need matrix is : "<<endl;
    for(int i=0;i<proc;i++){
        cout<<"P"<<i<<" : ";
        for(int j=0;j<res;j++){
            cout<<need[i][j]<<" ";
        }
        cout<<endl;
    }

	int t=0;
    int ans[proc],ind=0;
	while(t<proc)
	{
		for(int i=0;i<proc;i++)
		{
            if(finish[i]==0){
                int checker=0;
			for(int j=0;j<res;j++)
			{
				if(available[j]<need[i][j]){
				checker=1;
				break;
                }
			}
			if(checker==0)
			{
                ans[ind++] = i;
				
				for(int k=0;k<res;k++)
				  available[k] = available[k] + allocation[i][k];
                finish[i] = 1;
			}
            }
		}
		t++;
	}
	int i=0;
	for(i=0;i<proc;i++)
	{
		if(finish[i]==0)deadlock=1;
	}
	if(deadlock==1)
	{
		cout<<"Not deadlock free. Unsafe state!";
	}
	else
	{
        cout << "Following is the SAFE Sequence" << endl; 
         for (i = 0; i < proc-1; i++) 
           cout << " P" << ans[i] << " ->"; 
        cout << " P" << ans[proc - 1] <<endl;

		// cout<<"Deadlock free. Safe state!";
	}
	return 0;
}