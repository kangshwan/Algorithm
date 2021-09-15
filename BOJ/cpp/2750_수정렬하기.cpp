#include <iostream>

using namespace std;

int arr[1000];
bool all_of(int *arr_start, int *arr_end){
    while(arr_start != arr_end){
        if(*arr_start != 1001){
            return false;
        }
        ++arr_start;
    }
    return true;
}
int main(){
    
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    
    /* Simple Sort */
//    int answer[n];
//    int answer_idx = 0;
//    while(!all_of(arr, arr+n)){
//        int min = 1001;
//        int min_idx = 1001;
//        for(int i = 0 ; i < n ; i++){
//            if(arr[i] < min){
//                min = arr[i];
//                min_idx = i;
//            }
//        }
//        answer[answer_idx++] = min;
//        arr[min_idx] = 1001;
//    }
//    for(int i = 0 ; i < n ; i++){
//        cout << answer[i] << endl;
//    }
    
    /* Selection Sort */
//    int select_idx = 0;
//    while(select_idx < n){
//    	int min = 1001;
//        int min_idx = 1001;
//        for(int i = select_idx ; i < n ; i++){
//            if(arr[i] < min){
//                min = arr[i];
//                min_idx = i;
//            }
//        }
//        /* swap min with select_idx */
//        int temp = arr[select_idx];
//        arr[select_idx] = min;
//        arr[min_idx] = temp;
//    	select_idx++;
//	  }
//    for(int i = 0 ; i < n ; i++){
//        cout << arr[i] << endl;
//    }
    
    /* Insertion Sort */
//    for(int j = 1 ; j < n ; j++){
//        int key = arr[j];
//        int i = j-1;
//        while(i >= 0 && arr[i] > key){
//            arr[i+1] = arr[i];
//            i=i-1;
//        }
//        arr[i+1] = key;
//    }
//    for(int i = 0 ; i < n ; i++){
//        cout << arr[i]<<endl;
//    }
    
	/* Bubble Sort */
    /* type 1 */
//    bool swaped = true;
//    do{
//        swaped = false;
//        for(int i = 1 ; i < n ; i++){
//            if(arr[i-1] > arr[i]){
//                int temp = arr[i];
//                arr[i] = arr[i-1];
//                arr[i-1] = temp;
//                swaped = true;
//            }
//        }
//    }
//    while(swaped);
//    for(int i = 0 ; i < n ; i++){
//        cout << arr[i] << endl;
//    }
    /* type 2 */
    for(int iter = 0 ; iter < n ; iter++){
        for(int i = 1 ; i < n ; i++){
            if(arr[i-1] > arr[i]){
                int temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << endl;
    }
}
