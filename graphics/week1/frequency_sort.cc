#include<bits/stdc++.h>
using namespace std;
void sort(int index[], int count[]);
void frequencySort(int arr[], int n);
int main(int argc, char const *argv[]){
  int input[] = {0,8,5,3,3,8,7,5,3,2,1};
  int n = sizeof(input)/sizeof(input[0]);
  frequencySort(input, n);
  return 0;
}
void frequencySort(int arr[], int n){
  int count[10] = {0};
  int index[10];
  for (int i = 0; i < 10; i++) {
    index[i] = i;
  }

  for (int i = 0; i < n; i++) {
    count[arr[i]]++;
  }
  sort(index, count);
  // cout<<"index: "; for(int i = 0; i < 10 ; i++){ cout<<index[i]<<' ';}cout<<endl;
  int output[n];
  int i = 0, j = 0;
  while(j < n){
    while(count[index[i]] == 0)
      i++;

    output[j++] = index[i];
    count[index[i]]--;

  }
  cout<<"output: "; for(int i = 0; i < n ; i++){ cout<<output[i]<<' ';}cout<<endl;

}
void sort(int index[], int count[]){
  bool incl[10] = {0};
  int min = INT_MAX, minIndex = 0;
  for (int k = 0; k < 10; k++) {
    min = INT_MAX;
    for (int i = 0; i < 10; i++) {
      if(count[i] < min && incl[i] == 0)
        min = count[i],  minIndex = i;
    }
    incl[minIndex] = 1;
    index[k] = minIndex;
  }
}
