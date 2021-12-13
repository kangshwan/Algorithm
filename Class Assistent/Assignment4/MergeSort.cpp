#include<iostream>
#include<algorithm>
using namespace std;
vector<int> Merge(vector<int> a, vector<int> b){
	int k=0;
	int maxLength = a.size() + b.size();
	vector<int> result(maxLength);
	int i = 0;
	int j = 0;
	while(k<maxLength){
		if(i<a.size() && j<b.size()){
			if(a[i]<b[j])
				result[k++]=a[i++];
			else
				result[k++] = b[j++];
		}
		else if(i==a.size())
			result[k++]=b[j++];
		else
			result[k++]=a[i++];
	}
	return result;
}
vector<int> MergeSort(vector<int> list){
	if(list.size() == 1){
		return list;
	}
	int firstLength = list.size()/2;
	vector<int> one(firstLength);
	for(int i = 0 ; i < firstLength ; i++){
		one[i] = list[i];
	}
	int secondLength = list.size() - firstLength;
	vector<int> two(secondLength);
	for(int i = firstLength ; i < list.size() ; i++){
		two[i-firstLength] = list[i];
	}
	one = MergeSort(one);
	two = MergeSort(two);
	list = Merge(one,two);
	return list;
}
int main(){
	vector<int> unSortedList = {38,27,43,3,9,82,10};
	vector<int> SortedList = MergeSort(unSortedList);
	for(int i = 0 ; i < SortedList.size() ; i++){
		printf("%d ",SortedList[i]);
	}
	return 0;
}
/*
Example 1
{12,9,7,2,3,8,15,7};

Example 2
{38,27,43,3,9,82,10};
*/
