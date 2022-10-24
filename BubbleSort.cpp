void BubbleSort(int arr[], int n){
	for(int i=n-1; i>=0; i--){
		for(int j=1; j<=i; j++){
			if(arr[j-1] > arr[j]){
				swap(arr[j-1], arr[j]);
			}
		}
	}
}