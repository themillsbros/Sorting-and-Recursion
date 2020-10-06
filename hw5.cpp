#include "hw5.h" 
#include <vector>
#include <string>
/*  BubbleSort: set swal marker, set size variable for readabilty, if swal marker is false, it means there are no more possible swaps to be made, allowing for a best case o(n) situation. Otherwise the while loops acts as the first for loop in a standard bublesort. While swap is true cycle thru vector swalling j and j+1 until no more swaps are made.
InsertionHelp helper needed to feed size variable thru recursive lool. Base case is when size is <=1 , the sort starts going back up, asignining the key at size - 1, index at size -2, while the index is 0 or above and the index is great than the key, push the index to the right, compare key to next number to the left. when key is greater than left or is at 0, insert key into index. go up recursion 1.
InsertionSort: use helper

merge: get sizes of l/r vectors, create temp l/r arrays with their own indexes plus a index for orignal array, copy  old arrays onto temps, compare temp l/r arrays  using indexes and modify original vector by copying the smaller of the 2 temp arrays, while cycling up the copied array and orginal vector. if left over elements from eithe array, copy to orignal vector 
mergehelper: find middle., recusively split to the left until one element, then send to merge with its right half.
mergesort: use merghelper

*/
void StringSwap(std::string &a, std::string &b){
  std::string hold = a;
  a = b;
  b = hold;
}

void BubbleSort(std::vector<std::string>&vec) 
{ 
  bool swap = true;
  int size=vec.size();
  while(swap){
    swap = false;
    for (int j=0; j<size-1; j++){ 
      if ((vec[j].compare(vec[j+1]) > 0)){
        swap = true;
        StringSwap( vec[j+1],vec[j]);
      } 
    } 
  } 
} 

void InsertionHelp(std::vector<int> &vec, int size){

if ( size <= 1){
  return;
}
InsertionHelp(vec, size-1);

int key = vec[size-1];
int i = size-2;

while(i >=0 && vec[i] > key){
  vec[i+1] = vec[i];
  i--;
}
vec[i+1] = key; 
}

void InsertionSort(std::vector<int>& boo){
  InsertionHelp(boo, boo.size());
}

void merge(std::vector<std::string>&vec, int l, int m, int r) 
{ 
  int size1 = m-l+1;
  int size2 = r-m;
  std::vector<std::string> L(size1);
  std::vector<std::string> R(size2);

  for(int i = 0; i < size1; i++){
    L[i] = vec[l+i];
  }
  for(int j = 0; j < size2; j++){
    R[j]=vec[m+j+1];
  }

  int i=0,j=0;
  int k;
  for(k = l; k <= r && i < size1 && j < size2; k++) {
    if(L[i] <= R[j]){
      vec[k] = L[i];
      i++;
    }
    else{
      vec[k] = R[j];
      j++;
      }
  }
  for(i = i; i < size1; ++i){
    vec[k] = L[i];
    k++;
  }

  for(j = j; j < size2; j++){
    vec[k] = R[j];
    k++;
  }
} 

void mergeSortHelper(std::vector<std::string>& vec, int l, int r) { 
  if (l < r) { 
    int m = l + (r - l) / 2; 

   mergeSortHelper(vec, l, m); 
   mergeSortHelper(vec, m + 1, r); 

   merge(vec, l, m, r);
                
  } 
} 

void MergeSort(std::vector<std::string> &vec){
    int n=vec.size();
    mergeSortHelper(vec,0,n-1);
}
