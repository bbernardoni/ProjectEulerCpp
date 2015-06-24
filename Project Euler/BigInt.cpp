#include "BigInt.h"

BigInt::BigInt()
{
	zero();
}

BigInt::BigInt(BigInt *b)
{
	memcpy(value, b->value, BIG_INT_MAX_SIZE);
}

BigInt::BigInt(char *c)
{
	assign(c);
}

BigInt::BigInt(const char *c)
{
	assign((char*)c);
}

BigInt::BigInt(char *c, int size)
{
	memcpy(value, c, size);
}

// BigInt::BigInt(T num) needs to be in the header file

void BigInt::zero()
{
	memset(value, '0', BIG_INT_MAX_SIZE);
	value[BIG_INT_MAX_SIZE-1] = 0;
}

void BigInt::assign(char *c)
{
	zero();
	int size = strlen(c);
	if(size > BIG_INT_MAX_SIZE-1)
		return;
	int i=size-1;
	if(c[0] == '-')
		value[BIG_INT_MAX_SIZE-2] = '-';
	for(int j=0; i>=0 && c[i] != '-'; ++j, --i)
		value[j] = c[i];
}

BigInt BigInt::operator+(const BigInt& second)
{
	if(value[BIG_INT_MAX_SIZE-2] == second.value[BIG_INT_MAX_SIZE-2])
		return add(*this, second);
	else if(!absCmp(*this, second))
		return sub(second, *this);
	else
		return sub(*this, second);
}

BigInt BigInt::operator-(const BigInt& second)
{
	if(value[BIG_INT_MAX_SIZE-2] != second.value[BIG_INT_MAX_SIZE-2])
		return add(*this, second);
	else if(!absCmp(*this, second))
		return sub(second, *this, true);
	else
		return sub(*this, second);
}

BigInt BigInt::operator*(const BigInt& second)
{
	char out[BIG_INT_MAX_SIZE];
	memset(out, '0', BIG_INT_MAX_SIZE);
	int carry = 0;
	for(int i=0; i<BIG_INT_MAX_SIZE-2; ++i)
	{
		if(!second.value[i])
			continue;
		for(int j=0; i+j<BIG_INT_MAX_SIZE-2; ++j)
		{
			int digit = (value[j] - '0') * (second.value[i] - '0') + (out[i+j] - '0') + carry;
			carry = digit / 10;
			digit %= 10;
			out[i+j] = digit + '0';
		}
		carry = 0;
	}
	out[BIG_INT_MAX_SIZE-2] = (value[BIG_INT_MAX_SIZE-2]==value[BIG_INT_MAX_SIZE-2])? '0': '-';
	out[BIG_INT_MAX_SIZE-1] = 0;
	return BigInt(out, BIG_INT_MAX_SIZE);
}
/*  _____
sec|first
   ______
12|876789
          _________________
123456789|98765432123456789
*/
/*BigInt BigInt::operator/(const BigInt& second)
{
	return BigInt();
}*/

BigInt BigInt::operator^(const long& second)
{
	BigInt first(this);
	for(int i=1; i < second; i++)
	{
		first *= (*this);
	}
	return first;
}

BigInt BigInt::operator%(const BigInt& second)
{
	BigInt dividend(this);
	BigInt divisor(second);
	int startM = dividend.getMagnitude() - divisor.getMagnitude();
	divisor.times10ToN(startM);
	for(int i=startM; i >= 0; --i)
	{
		while(absCmp(dividend, divisor)){
			dividend -= divisor;
		}
		divisor.times10ToN(-1);
	}
	return dividend;
}

BigInt BigInt::operator+=(const BigInt& second)
{
	if(value[BIG_INT_MAX_SIZE-2] == second.value[BIG_INT_MAX_SIZE-2])
		add(second);
	else
		sub(second, !absCmp(*this, second));
	return *this;
}

BigInt BigInt::operator-=(const BigInt& second)
{
	neg();
	(*this) += second;
	neg();
	return *this;
}

BigInt BigInt::operator*=(const BigInt& second)
{
	char out[BIG_INT_MAX_SIZE];
	memset(out, '0', BIG_INT_MAX_SIZE);
	int carry = 0;
	for(int i=0; i<BIG_INT_MAX_SIZE-2; ++i)
	{
		if(!second.value[i])
			continue;
		for(int j=0; i+j<BIG_INT_MAX_SIZE-2; ++j)
		{
			int digit = (value[j] - '0') * (second.value[i] - '0') + (out[i+j] - '0') + carry;
			carry = digit / 10;
			digit %= 10;
			out[i+j] = digit + '0';
		}
		carry = 0;
	}
	out[BIG_INT_MAX_SIZE-2] = (value[BIG_INT_MAX_SIZE-2]==value[BIG_INT_MAX_SIZE-2])? '0': '-';
	out[BIG_INT_MAX_SIZE-1] = 0;
	memcpy(value, out, BIG_INT_MAX_SIZE);
	return *this;
}

BigInt BigInt::operator^=(const long& second)
{
	BigInt first(this);
	for(int i=1; i < second; i++)
	{
		(*this) *= first;
	}
	return (*this);
}

bool BigInt::operator==(const BigInt& second)
{
	return (strcmp(value, second.value)==0);
}

BigInt BigInt::add(const BigInt& first, const BigInt& second)
{
	char out[BIG_INT_MAX_SIZE];
	int carry = 0;
	for(int i=0; i<BIG_INT_MAX_SIZE-2; ++i)
	{
		int digit = first.value[i] + second.value[i] + carry - '0';
		carry = digit / ':';
		digit -= 10*carry;
		out[i] = digit;
	}
	out[BIG_INT_MAX_SIZE-2] = first.value[BIG_INT_MAX_SIZE-2];
	out[BIG_INT_MAX_SIZE-1] = 0;
	return BigInt(out, BIG_INT_MAX_SIZE);
}

BigInt BigInt::sub(const BigInt& first, const BigInt& second, bool flipSign)
{
	char out[BIG_INT_MAX_SIZE];
	int carry = 0;
	for(int i=0; i<BIG_INT_MAX_SIZE-2; ++i)
	{
		int digit = first.value[i] - second.value[i] + carry;
		carry = (digit<0)? -1: 0;
		digit -= 10*carry;
		out[i] = digit + '0';
	}
	if(flipSign)
		out[BIG_INT_MAX_SIZE-2] = (first.value[BIG_INT_MAX_SIZE-2] == '-')? '0': '-';
	else
		out[BIG_INT_MAX_SIZE-2] = first.value[BIG_INT_MAX_SIZE-2];
	out[BIG_INT_MAX_SIZE-1] = 0;
	return BigInt(out, BIG_INT_MAX_SIZE);
}

//destructive add and sub for += / -=
void BigInt::add(const BigInt& second)
{
	int carry = 0;
	for(int i=0; i<BIG_INT_MAX_SIZE-2; ++i)
	{
		int digit = value[i] + second.value[i] + carry - '0';
		carry = digit / ':';
		digit -= 10*carry;
		value[i] = digit;
	}
}

void BigInt::sub(const BigInt& second, bool flipOps)
{
	int carry = 0;
	int digit;
	for(int i=0; i<BIG_INT_MAX_SIZE-2; ++i)
	{
		if(flipOps)
			digit = second.value[i] - value[i] + carry;
		else
			digit = value[i] - second.value[i] + carry;
		carry = (digit<0)? -1: 0;
		digit -= 10*carry;
		value[i] = digit + '0';
	}
	if(flipOps)
		value[BIG_INT_MAX_SIZE-2] = second.value[BIG_INT_MAX_SIZE-2];
	value[BIG_INT_MAX_SIZE-1] = 0;
}

void BigInt::neg()
{
	value[BIG_INT_MAX_SIZE-2] = (value[BIG_INT_MAX_SIZE-2] == '-')? '0': '-';
}

void BigInt::times10ToN(long n)
{
	if(n>0){
		memmove(&value[n], value, BIG_INT_MAX_SIZE-2-n);
		memset(value, '0', n);
	}else{
		memmove(value, &value[-n], BIG_INT_MAX_SIZE-2+n);
		memset(&value[BIG_INT_MAX_SIZE-2+n], '0', -n);
	}
}

void BigInt::reverse()
{
	char* first = &value[0];
	char* last = &value[getMagnitude()-1];
	while( first < last ) {
		char tmp = *first;
		*first = *last;
		*last = tmp;
		++first;
		--last;
	}
}

bool BigInt::isZero()
{
	for(int i=0; i<BIG_INT_MAX_SIZE-2; ++i)
		if(value[i] != '0')
			return false;
	return true;
}

bool BigInt::isPalindrome()
{
	int i;
	for(i=BIG_INT_MAX_SIZE-3; i>=0; --i)
		if(value[i] != '0')
			break;
	for(int j=0; j*2 < i; ++j)
		if(value[j] != value[i-j])
			return false;
	return true;
}

char BigInt::charAt(int n){
	if(n<BIG_INT_MAX_SIZE-2)
		return value[n];
	return 0;
}

// an absolute compare. true for first>=second else false
bool BigInt::absCmp(const BigInt& first, const BigInt& second)
{
	for(int i=BIG_INT_MAX_SIZE-3; i>=0; --i)
	{
		if(first.value[i] > second.value[i])
			return true;
		else if(first.value[i] < second.value[i])
			return false;
	}
	return true;
}

void BigInt::getCStr(char *out, int size)
{
	memset(out, 0, size);
	if(size < MIN_BUFFER_SIZE)
		return;
	int i=0;
	if(value[BIG_INT_MAX_SIZE-2] == '-')
		out[i++] = '-';
	bool leadingZeros = true;
	for(int j=BIG_INT_MAX_SIZE-2-i; j>=0; --j){
		if(leadingZeros){
			if(value[j] == '0')
				continue;
			else
				leadingZeros = false;
		}
		out[i++] = value[j];
		if(i>=size)
			return;
	}
	if(leadingZeros){
		out[0] = '0';
	}
}

void BigInt::print()
{
	char out[BIG_INT_MAX_SIZE];
	getCStr(out, BIG_INT_MAX_SIZE);
	printf("%s", out);
}

void BigInt::println()
{
	char out[BIG_INT_MAX_SIZE];
	getCStr(out, BIG_INT_MAX_SIZE);
	printf("%s\n", out);
}

int BigInt::getMagnitude()
const {
	int ret;
	for(ret=BIG_INT_MAX_SIZE-2; ret>0; --ret)
		if(value[ret] != '0')
			break;
	return ++ret;
}

long BigInt::getLong()
{
	int digits = getMagnitude();
	long ret = 0;
	reverse();
	for(int i=0; i<digits; ++i)
	{
		ret *= 10;
		ret += (value[i] - '0');
	}
	reverse();
	return ret;
}

long BigInt::getDigitSum()
{
	int digits = getMagnitude();
	long ret = 0;
	for(int i=0; i<digits; ++i)
	{
		ret += (value[i] - '0');
	}
	return ret;
}