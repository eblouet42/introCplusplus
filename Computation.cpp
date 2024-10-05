#include <iostream>

float average(int arr[],int size){
  int sum = 0;
  for (int i = 0; i < size; i++){
    sum += arr[i];
  }
  std::cout << sum << std::endl;
  float average= static_cast<float>(sum)/size;
  return average;
 }

 int main(){
   int arr[] = {1,2,3,4,5,6,7,8,9,10};
   printf("La moyenne vaut %f",average(arr, 10));
   return 0;
 }