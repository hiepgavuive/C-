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