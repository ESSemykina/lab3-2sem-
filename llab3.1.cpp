/*1.	Реализуйте алгоритм бинарного поиска, о котором шла речь на лекции. 
Решите задачу выполнения M (0<M<10000) поисковых запросов над массивом из N (0<N<100000) элементов,
используя проход по массиву циклом и бинарный поиск. Сравните время работы этих двух подходов.*/


#include<iostream>
#include<chrono>
#define N 100000
#define M 100000
class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};
void quicksort(int a, int b, int* mas2)
{
	if (a >= b)
		return;
	int m = rand() % (b - a + 1) + a;
	int k = mas2[m];
	int l = a - 1;
	int r = b + 1;
	while (1)
	{
		do l = l + 1; while (mas2[l] < k);
		do r = r - 1; while (mas2[r] > k);
		if (l >= r)
			break;
		std::swap(mas2[l], mas2[r]);
	}
	r = l;
	l = l - 1;
	quicksort(a, l, mas2);
	quicksort(r, b, mas2);
}
int binarysearch(int n, int mas[N], int k)
{

	if (k < mas[0])
	{
		return -1;
	}
	if (k == mas[0])
	{
		return 0;
	}
	if (k > mas[N - 1])
	{
		return -1;
	}
	int a = 0;
	int b = n - 1;
	while (a + 1 < b)
	{
		int c = (a + b) / 2;
		if (k > mas[c])
		{
			a = c;
		}
		else
		{
			b = c;
		}
	}
	if (mas[b] == k)
	{
		return b;
	}
	else
	{
		return -1;
	}
}
int main()
{
	srand(time(0));
	int mas[N];
	int mas1[M];
	int a = 0;
	int b = N - 1;
	int c;
	for (int i = 0; i < N; i++)
	{
		mas[i] = rand();
	}
	for (int j = 0; j < M; j++)
	{
		mas1[j] = rand();
	}
	quicksort(a, b, mas);
	// поиск данных
	Timer t;
	for (int i = 0; i < M; i++)
	{
		int j = binarysearch(N - 1, mas, mas1[i]);
	}
	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (mas[i] == mas1[j])
			{
				break;
			}
		}
	}*/
	//время работы бинарного поиска (0.0007735)
	//времы работы обычным перебором (1.92378)
	std::cout << "Time elapsed: " << t.elapsed() << '\n';
}