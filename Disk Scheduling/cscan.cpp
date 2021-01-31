#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std; 

int disk_size = 200; 

void CSCAN(int arr[], int head,int size) 
{ 
	int seek_count = 0; 
	int distance, cur_track; 
	vector<int> left, right; 
	vector<int> seek_sequence; 

	left.push_back(0); 
	right.push_back(disk_size - 1); 

	for (int i = 0; i < size; i++) { 
		if (arr[i] < head) 
			left.push_back(arr[i]); 
		if (arr[i] > head) 
			right.push_back(arr[i]); 
	} 

	// sorting left and right vectors 
	sort(left.begin(), left.end()); 
	sort(right.begin(), right.end()); 

	
	for (int i = 0; i < right.size(); i++) { 
		cur_track = right[i]; 
		seek_sequence.push_back(cur_track); 
		distance = abs(cur_track - head); 
		seek_count += distance; 
		head = cur_track; 
	} 

	head = 0; 

	for (int i = 0; i < left.size(); i++) { 
		cur_track = left[i]; 
		seek_sequence.push_back(cur_track); 
		distance = abs(cur_track - head); 
		seek_count += distance; 
		head = cur_track; 
	} 

	cout << "Total number of seek operations = " 
		<< seek_count << endl; 

	cout << "Seek Sequence is" << endl; 

	for (int i = 0; i < seek_sequence.size(); i++) { 
		cout << seek_sequence[i] << endl; 
	} 
} 

int main(){ 
    int head, q_size;
  cout<<"Enter number of disk locations";
  cin>>q_size;
  int queue[q_size];

  cout<<"\nEnter Head position: ";
  cin>>head;

  cout<<"Enter the request queue :"<<endl;
  for(int i=0; i<q_size; i++){
    cin>>queue[i];
  }
	CSCAN(queue, head,q_size); 

	return 0; 
} 
