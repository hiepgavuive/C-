void SelectionSort(int arr[], int n){
	int min, temp;
	for(int i=0; i<n; i++){
		min = i;
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[min]) min = j;
		}
		swap(arr[i], arr[min]);
	}
}