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