#pragma once

#include <cstring>
#include <cstdio>

// Class for operations with very big numbers
// Right now max size is 1024 digits
// numbers are stored little endian
class BigInt
{
public:
	BigInt();
	BigInt(BigInt *b);
	BigInt(char *c);
	BigInt(const char *c);
	BigInt(char *c, int size);
	template <typename T> 
	BigInt(T num);
	
	
	BigInt operator+(const BigInt& second);
	BigInt operator-(const BigInt& second);
	BigInt operator*(const BigInt& second);
	BigInt operator^(const long& second);
	BigInt operator%(const BigInt& second);

	BigInt operator+=(const BigInt& second);
	BigInt operator-=(const BigInt& second);
	BigInt operator*=(const BigInt& second);
	BigInt operator^=(const long& second);
	
	bool operator==(const BigInt& second);

	static bool absCmp(const BigInt& first, const BigInt& second);

	void zero();
	void assign(char *c);
	void times10ToN(long n);
	void reverse();

	bool isZero();
	bool isPalindrome();
	char charAt(int n);

	void getCStr(char *out, int size);
	void print();
	void println();
	
	int getMagnitude() const;
	long getLong();
	long getDigitSum();

	static const int BIG_INT_MAX_SIZE = 1024;
protected:
	static const int MIN_BUFFER_SIZE = 2;
	char value[BIG_INT_MAX_SIZE];
	
	BigInt add(const BigInt& first, const BigInt& second);
	BigInt sub(const BigInt& first, const BigInt& second, bool flipSign = false);
	void add(const BigInt& second);
	void sub(const BigInt& second, bool flipOps = false);
	void neg();
};

template <typename T> 
BigInt::BigInt(T num)
{
	zero();
	if(num<0){
		value[BIG_INT_MAX_SIZE-2] = '-';
		num = -num;
	}
	for(int i=0; num>0; ++i){
		if(i > BIG_INT_MAX_SIZE-2)
			return;
		value[i] = '0' + (num%10);
		num /= 10;
	}
}