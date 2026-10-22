#include <iostream>
#include <iomanip> 
#include <time.h> 
using namespace std;
void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}
void Print(int* a, const int size, int i)
{
	cout << setw(3) << a[i] << ",";
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;

}
int Sum(int* a, const int size,int i)
{
	if (i >= size)
		return 0;


	if (a[i] > 0 || a[i] % 3 != 0)
		return a[i] + Sum(a, size, i + 1);
	else
		return Sum(a, size, i + 1);
}
int N(int* a, const int size,int i)
{
	if (i >= size)
		return 0;
	int count = N(a, size, i + 1);
	if (a[i] > 0 || a[i] % 3 != 0) {
		return count + 1;
	}
	return count;
}
void Modify(int* a, const int size,int i)
{
	if (i >= size)
		return;
	if (a[i] > 0 || a[i] % 3 != 0) {
		a[i] = 0;
	}
	Modify(a, size, i + 1);
}
int main()
{
	srand((unsigned)time(NULL));
	const int n = 22;
	int a[n];
	int Low = -10;
	int High = 35;
	Create(a, n, Low, High,0);
	cout << "a[22]=";
	Print(a, n,0);
	cout << "sum=" << Sum(a, n, 0) << "  N=" << N(a, n,0) << endl;
	Modify(a, n,0);
	cout << "a[22]=";
	Print(a, n,0);
	return 0;
}
