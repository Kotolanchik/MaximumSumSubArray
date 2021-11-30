#include <cmath>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;
int Maximum_Sum_Subarray(int arr[], int n)
{
	int ans = INT_MIN;
	for (int start_index = 0; start_index < n; ++start_index)
	{
		int sum = 0;
		for (int sub_array_size = 1; sub_array_size <= n; ++sub_array_size)
		{
			if (start_index + sub_array_size > n)					break;
			sum += arr[start_index + sub_array_size - 1];				ans = max(ans, sum);
		}
	}
	return ans;
}
int main()
{
	duration<double> res_sum;
	duration<double> result;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(-100, 100);
	int size;
	cout << "Input size massive: ";
	cin >> size;

	int* arr = new int[size];
	double* timee = new double[20];
	for (size_t i = 0; i < 20; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			arr[j] = dist(gen);
			//	cout << arr[i] << " ";
		}
		auto t1 = system_clock::now();
		Maximum_Sum_Subarray(arr, size);
		auto t2 = system_clock::now();

		result = t2 - t1;
		timee[i] = result.count();
		res_sum = res_sum + result;
		//cout << "exp: " << i + 1 << " time: " << result.count()<<endl ;
		cout << "exp: " << i + 1 << " time: " << timee[i] << endl;
	}
	double sum = 0, max = -99999, min = 99999;
	for (size_t j = 0; j < 20; j++)
	{
		sum += timee[j];
		if (timee[j] > max)
			max = timee[j];
		if (timee[j] < min)
			min = timee[j];
	}
	cout << "average: " << sum / 20.0 << " min :" << min << " max: " << max << endl;


	return 0;
}

