#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	double sum = 0;//累加器设double变量
	for (int i = 1; i <= n; i ++) {
		int x;
		cin >> x;
		sum += x;//累加答案
	}
	printf ("%.2lf", sum/n);//保留两位小数
	return 0;
}