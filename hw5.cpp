#include "hw5.h" 
#include <vector>
#include <string>

void StringSwap(std::string &a, std::string &b){
  std::string hold = a;
  a = b;
  b = hold;
}

void BubbleSort(std::vector<std::string>&vec) 
{ 
  bool swap = false;
  int n=vec.size();
  for (int j=0; j<n-1; j++){ 
    if(vec[j].compare(vec[j+1]) > 0 || swap == true){
      swap = true;
      for (int i=j+1; i<n; i++){ 
        if (vec[j].compare(vec[i]) > 0) { 
        StringSwap( vec[i],vec[j]);
        } 
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

void merge(std::vector<std::string>&vec, int p, int q, int r) 
{ 
    int size1 = q-p+1;
    int size2 = r-q;
    std::vector<std::string> L(size1);
    std::vector<std::string> R(size2);

    for(int i = 0; i < size1; i++){
        L[i] = vec[p+i];
    }
    for(int j = 0; j < size2; j++){
        R[j]=vec[q+j+1];
    }

    int i=0,j=0;
    int k;
    for(k = p; k <= r && i < size1 && j < size2; k++) {
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
    // Same as (l+r)/2, but avoids overflow for 
    // large l and h 
    int m = l + (r - l) / 2; 

    // Sort first and second halves 
   mergeSortHelper(vec, l, m); 
   mergeSortHelper(vec, m + 1, r); 

   merge(vec, l, m, r); //this function merges the left sorted
                //and the right sorted string
        } 
} 

void MergeSort(std::vector<std::string> &vec){
    int n=vec.size();
    mergeSortHelper(vec,0,n-1);
}
