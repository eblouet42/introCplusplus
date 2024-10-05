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
int fibo(int n){
    int truc[2]={0,1};
    for (int i = 1; i <= n; i++) {
        int google_stock=truc[1];
        truc[1]=truc[0]+truc[1];
        truc[0]=google_stock;
    }
    return truc[0];
}

 int main(){
   int arr[] = {1,2,3,4,5,6,7,8,9,10};
   printf("La moyenne vaut %f\n",average(arr, 10));
    for(int i=0;i<20;i++){
        printf( "Le %deme nombre de Fibonacci vaut %d\n",i+1,fibo(i));
    }
   return 0;
 }