#include <iostream>
#include <stdlib.h>
#include <vector>
#include <windows.h>
#include <iomanip>

using namespace std;

void Selection(int arr[], int n){
	int min, temp;
	for(int i=0; i<n; i++){
		min = i;
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[min]) min = j;
		}
		swap(arr[i], arr[min]);
	}
}

void Insertion(int arr[], int n){
	int x, j;
	for(int i=1; i<n; i++){
		x = arr[i];
		j = i;
		while(x < arr[j-1]){
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = x;
	}
}

void Bubble(int arr[], int n){
	for(int i=n-1; i>=0; i--){
		for(int j=1; j<=i; j++){
			if(arr[j-1] > arr[j]){
				swap(arr[j-1], arr[j]);
			}
		}
	}
}

void MergeSort(int arr[], int l, int m, int h){
	int n1 = m - l + 1;
	int n2 = h - m;
	
	int L[n1];
	int R[n2];
	
	for(int i=0; i<n1; i++) L[i] = arr[l+i];
	for(int i=0; i<n2; i++) R[i] = arr[i+m+1];
	
	int a = 0, b = 0, c = l;
	while(a<n1 && b<n2){
		arr[c++] = (L[a] <= R[b]) ? L[a++] : R[b++];
	}
	while(a<n1){
		arr[c++] = L[a++];
	}
	while(b<n2){
		arr[c++] = R[b++];
	}
}

void Merge(int arr[], int l, int h){
	if(l < h){
		int m = l + (h-l)/2;
		Merge(arr, l, m);
		Merge(arr, m+1, h);
		MergeSort(arr, l, m, h);
	}
}

int QuickSort(int arr[], int l, int h){
	int x = arr[h];
	
	vector<int> L;
	vector<int> R;
	int a=0, b=0, Pivot;
	for(int i=l; i<h; i++){
		if(arr[i] < x) L.push_back(arr[i]);
		else if(arr[i] > x) R.push_back(arr[i]);
	}
	
	for(int i=l; i<=h; i++){
		if(i - l < L.size()){
			arr[i] = L[a++];
		}else if(i - l == L.size()){
			arr[i] = x;
			Pivot = i;
		}else{
			arr[i] = R[b++];
		}
	}
	return Pivot;
}

void Quick(int arr[], int l, int h){
	if(l < h){
		int Pivot = QuickSort(arr, l, h);
		Quick(arr, l, Pivot-1);
		Quick(arr, Pivot+1, h);
	}
}

void HeapSort(int arr[], int n, int i){
	int l = 2*i + 1;
	int r = 2*i + 2;
	int goc = i;
	
	if(l < n && arr[l] > arr[goc]) goc = l;
	if(r < n && arr[r] > arr[goc]) goc = r;
	
	if(goc != i){
		swap(arr[goc], arr[i]);
		HeapSort(arr, n, goc);
	}
}

void Heap(int arr[], int n){
	for(int i=n/2-1; i>=0; i--){
		HeapSort(arr, n, i);
	}
	
	for(int i=n-1; i>=0; i--){
		swap(arr[i], arr[0]);
		HeapSort(arr, i, 0);
	}
}

int main(){
	int n; cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	for(int i=0; i<n; i++){
		cout<<arr[i];
	}
	return 0;
}