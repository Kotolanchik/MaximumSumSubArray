#include <cmath>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;
int Maximum_Sum_Subarray(int arr[], int n)
{
	int ans = arr[0], sum = 0;
	for (int i = 1; i < n; ++i)
		ans = max(ans, arr[i]);
	if (ans < 0)
		return ans;
	ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (sum + arr[i] > 0)
			sum += arr[i];
		else
			sum = 0;
		ans = max(ans, sum);
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
