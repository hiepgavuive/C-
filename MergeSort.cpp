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