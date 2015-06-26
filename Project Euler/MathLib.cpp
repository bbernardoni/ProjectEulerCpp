#include "MathLib.h"

bool MathLib::isPalindromic(long n)
{
	std::string s = std::to_string((long long)n);
	int l = strlen(s.c_str());
	for(int i=0; i<=l/2; ++i)
		if(s.c_str()[i] != s.c_str()[l-i-1])
			return false;
	return true;
}

// wrong when n=1 but in most cases I don't care and this is faster
bool MathLib::isPrime(long n)
{
	if(isMultiple(n, 2L)){
		if(n!=2)
			return false;
		else
			return true;
	}
	for(long i=3; sqrt((double)n)>=i; i+=2)
		if(isMultiple(n, i))
			return false;
	return true;
}

// safe alt to isPrime
bool MathLib::isPrime_s(long n)
{
	if(n==1)
		return false;
	else
		return isPrime(n);
}

int MathLib::numOfDivisors(long n)
{
	long sqrtn = (long)sqrt((double)n);
	int c=0;
	for(long i=1; i<sqrtn; ++i)
		if(isMultiple(n, i))
			c++;
	c *= 2;
	if(isMultiple(n, sqrtn))
		c++;
	return c;
}

long MathLib::sumOfDivisors(long n)
{
	long sqrtn = (long)(sqrt((double)n) + 0.99);
	long s=1;
	for(long i=2; i<sqrtn; ++i)
		if(isMultiple(n, i))
			s += i + (n/i);
	if(n == sqrtn * sqrtn)
		s += sqrtn;
	return s;
}

void MathLib::quicksort(char *a, int bufLen, int lo, int hi)
{
	if(lo < hi){
		int p = partition(a, bufLen, lo, hi);
		quicksort(a, bufLen, lo, p - 1);
		quicksort(a, bufLen, p + 1, hi);
	}
}

// lo is the index of the leftmost element of the subarray
// hi is the index of the rightmost element of the subarray (inclusive)
int MathLib::partition(char *a, int bufLen, int lo, int hi){
	int storeIndex = lo;
	// Compare remaining array elements against pivotValue = A[hi]
	for(int i=lo; i<hi; ++i){
		if(strcmp(&a[i*bufLen], &a[hi*bufLen]) < 0){
			swap(a, bufLen, storeIndex, i);
			storeIndex++;
		}
	}
	swap(a, bufLen, storeIndex, hi);  // Move pivot to its final place
	return storeIndex;
}

void MathLib::swap(char *a, int bufLen, int i, int j){
	if(bufLen > SWAP_BUFFER_LENGTH){
		printf("swap buffer too small\n");
		return;
	}
	char temp[SWAP_BUFFER_LENGTH];
	strcpy_s(temp, bufLen, &a[i*bufLen]);
	strcpy_s(&a[i*bufLen], bufLen, &a[j*bufLen]);
	strcpy_s(&a[j*bufLen], bufLen, temp);
}

long MathLib::factorial(long n){
	if (n<=1)
		return 1;
	else
		return n * factorial(n-1);
}

bool MathLib::isPentagonal(long long n)
{ // 1+24n has to be a square and (1+sqrt(1+24n)) % 6 == 0
	long long rad = 1+24*n;
	long long sqrtn = (long long)sqrt((double)rad);
	if(sqrtn*sqrtn == rad)
		if((1+sqrtn) % 6 == 0)
			return true;
	return false;
}

long MathLib::gcd(long a, long b)
{
	long t;
	while(b!=0){
		t = b;
		b = a % b;
		a = t;
	}
    return a;
}