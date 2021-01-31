#include <iostream>
#include <algorithm>
#define LOW 0
#define HIGH 199
using namespace std;

int main(){
  int head, max, q_size, temp, sum;
  int dloc; //location of disk (head) arr
  cout<<"Enter number of disk locations";
  cin>>q_size;
  int queue[q_size];

  cout<<"\nEnter Head position: ";
  cin>>head;

  cout<<"Enter the request queue :"<<endl;
  for(int i=0; i<q_size; i++){
    cin>>queue[i];
  }

  queue[q_size] = head; //add RW head into queue
  q_size++;

  //sort the array
  sort(queue,queue+q_size);
  max = queue[q_size-1];

  //locate head in the queue
  for(int i=0; i<q_size; i++){
    if(head == queue[i]){
      dloc = i;
      break;
    }
  }

  if(abs(head-LOW) <= abs(head-HIGH)){

      for(int j=dloc; j>=0; j--){
        cout<<queue[j]<<"->";
      }
      for(int j=dloc+1; j<q_size; j++){
        cout<<queue[j]<<"->";
      }

      } else {

      for(int j=dloc+1; j<q_size; j++){
          cout<<queue[j]<<"->";
      }
      for(int j=dloc; j>=0; j--){
          cout<<queue[j]<<"->";
      }

  }

  sum  = head + max;
  cout<<"\ntotal seek is"<<sum;

  return 0;
}
// 98,183,37,122,14,124,65,67