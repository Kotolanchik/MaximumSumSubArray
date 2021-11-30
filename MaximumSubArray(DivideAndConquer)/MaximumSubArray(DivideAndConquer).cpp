#include <cmath>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;
int Maximum_Sum_Subarray(int arr[], int n)
{
	if (n == 1)
	{
		return arr[0];
	}
	int m = n / 2;
	int left_MSS = Maximum_Sum_Subarray(arr, m);
	int right_MSS = Maximum_Sum_Subarray(arr + m, n - m);
	int leftsum = INT_MIN, rightsum = INT_MIN, sum = 0;
	for (int i = m; i < n; i++)
	{
		sum += arr[i];
		rightsum = max(rightsum, sum);
	}
	sum = 0;
	for (int i = (m - 1); i >= 0; i--)
	{
		sum += arr[i];
		leftsum = max(leftsum, sum);
	}
	int ans = max(left_MSS, right_MSS);
	return max(ans, leftsum + rightsum);
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
	cout << "average: " << sum / 20.0 << " min: " << min << " max: " << max << endl;


	return 0;
}
