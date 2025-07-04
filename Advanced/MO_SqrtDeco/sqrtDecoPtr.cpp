#include <iostream>
#include <cmath>

using namespace std;

int* sqrtdecompose(int *arr, int n)
{
	int block_size = ceil(n/sqrt(n));
	int *blocks = new int[block_size];
	for(int i = 0; i < n; i++)
	{
		blocks[i/block_size] += arr[i];
	}
	return blocks;
}

void update(int *arr, int *blocks, int n, int index, int key)
{
	int changeValue = key - arr[index];
	arr[index] = key;
	int block_size = ceil(n/sqrt(n));
	blocks[index/block_size] += changeValue;
}

int calculateSum(int *arr, int *blocks, int n, int l, int r)
{
	int block_size = ceil(n/sqrt(n));
	int sum = 0;
	int start_block = l/block_size, end_block = r/block_size;
	for(int i = start_block+1; i < end_block; i++)
	{
		sum += blocks[i];
	}
	int i = l;
	while(i/block_size == start_block)
	{
		sum += arr[i++];
	}
	i = r;
	while(i/block_size == end_block)
	{
		sum += arr[i--];
	}
	return sum;

}

int main()
{
	int n, *arr, Q, type, index, key, l, r;
   cout<<"Enter Array size: -> Array elements -> No. of Ops -> Type: (1).Update{idx,key} (2). RangeSum: {l,r}"<<endl;
	cin>>n;
	arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int *blocks = sqrtdecompose(arr, n);
	cin>>Q;
	while(Q--)
	{
		cin>>type;
		switch(type)
		{
			case 1: cin>>index>>key;
					update(arr, blocks, n, index, key);
				break;
			
			case 2: cin>>l>>r;
					cout<<"Sum = "<<calculateSum(arr, blocks, n, l, r)<<endl;
				break;
		}
	}

}