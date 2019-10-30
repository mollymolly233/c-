#include<iostream>

using namespace std;
void printArr(int arr[], int len);
void swap(int arr[], int i, int j);

void bubbleSort(int arr[], int len);
void simpleSelectionSort(int arr[], int len);

int main(){
	int arr[] = {2,1,4,6,2,-1,0,-10};
	int len = (sizeof(arr)/sizeof(int));
	printArr(arr,len);
	simpleSelectionSort(arr,len);
	printArr(arr,len);
}

//直接插入排序 升序 O(n^2)
void InsertSort(int arr[], int len){
	//两个子序列，前有序，后无序。把无序序列中第一个元素插入有序序列中
	for(int i = 1; i < len){
		for(int j = i-1; j >0; j--){
			int tmp = arr[i];
			if(arr[i]<arr[j]){

			}

		}
	}
}

//冒泡 升序
void bubbleSort(int arr[], int len){
	int switchFlag = 1;
	for(int sorted = len; sorted> 1 && switchFlag == 1; sorted--){
		switchFlag = 0;
		for(int i = 1; i<sorted; i++){
			if(arr[i]<arr[i-1]){
				swap(arr,i,i-1);
				switchFlag = 1;
			}
		}
	}
}

//简单选择排序 升序
void simpleSelectionSort(int arr[], int len){
	//前后两个子序列，前有序，后无序，从无序中找下一个有序元素
	for(int i = 0; i< len; i++){
		int minLoc = i;
		for(int j = i; j<len; j++){
			if(arr[j]<arr[minLoc]){
				minLoc = j;
			}
		}
		if(i != minLoc)
			swap(arr,i,minLoc);
	}
}


//交换数组中的两个元素
void swap(int arr[], int i, int j){
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

//打印一个数组
void printArr(int arr[], int len){
	cout << "arr:";
	for(int i = 0; i < len; i++){
		cout << arr[i] << ",";
	}
	cout << endl;
}