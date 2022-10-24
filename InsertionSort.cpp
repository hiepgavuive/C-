void InsertionSort(int arr[], int n){
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