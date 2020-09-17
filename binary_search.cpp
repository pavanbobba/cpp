//binary search only can be performed on sorted array
#include<iostream>

using namespace std;

int main()
{
	int a[] = {3, 5, 11, 45, 46, 51}, key, low, high, mid;

	low = 0;
	high = (sizeof(a)/4) - 1;
	
	cout<<"enter key"<<endl;
	cin>>key;

	while(low <= high)
	{
		mid = (low + high)/2;
		if(key == a[mid])
		{
			cout<<"found at index "<<mid<<endl;
			break;
		}
		else
		{
			if(a[mid] > key)
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	if(low > high)
		cout<<"element not found"<<endl;
	
	return 0;
}
