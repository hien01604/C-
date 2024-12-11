#include<iostream>
using namespace std;
int interpolationSearch(int arr[], int n, int x){
	int i = 1;
	int lo = 0, hi = (n - 1);
	while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
		if (lo == hi){
			if (arr[lo] == x) return lo;
			return -1;
	}
	int pos = lo + (((hi-lo)*(x-arr[lo]))/(arr[hi]-arr[lo]));
		cout<<"Attempt "<<i<<": "<<endl;
		i++;
		cout << "low: " << lo<< ", high: " << hi << ", pos: " << pos << ", arr[pos]: " << arr[pos] << endl;
		if (arr[pos] == x) return pos;
		if (arr[pos] < x)
			lo = pos + 1;
		else
			hi = pos - 1;
	}
	return -1;
}

int main (){
	int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    	for(int i = 0 ; i < size ; i ++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int target =50;
	cout<<"Searching number: "<<target<<endl;
	
	int result=	interpolationSearch(arr,size,target);

	return 0;
}