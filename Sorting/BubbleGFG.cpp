// Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.
// The algorithm gets its name because smaller elements "bubble" to the top of the list.

class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        for(int i= 0; i<arr.size(); i++){
            for (int j=0; j<arr.size()-1; j++){
                if(arr[j]> arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]= temp;
                }
            }
        }
    }
};