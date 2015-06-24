#pragma once

#include <cmath>
#include <string>

class MathLib
{
public:
	template <typename T>
	static bool isMultiple(T num, T mult);
	static bool isPalindromic(long n);
	static bool isPrime(long n);
	static bool isPrime_s(long n);
	static int numOfDivisors(long n);
	static long sumOfDivisors(long n);
	static void quicksort(char *a, int bufLen, int lo, int hi);
	static int partition(char *a, int bufLen, int lo, int hi);
	static void swap(char *a, int bufLen, int i, int j);
	static long factorial(long n);
	static bool isPentagonal(long long n);

	static const int SWAP_BUFFER_LENGTH = 30;
};

template <typename T>
static bool MathLib::isMultiple(T num, T mult)
{
	return (!(num%mult));
}