#include "Problems.h"

void Problems::problem1()
{
	long a = 0;
	for(int i=1; i<1000; ++i)
		if(MathLib::isMultiple(i,3) || MathLib::isMultiple(i,5))
			a += i;
	printf("The answer to problem 1 is '%d'\n", a);
}

void Problems::problem2()
{
	long a = 0, j = 1, k = 1;
	for(long i=1; i<4000000; k=i, i+=j, j=k)
		if(MathLib::isMultiple(i,2L))
			a += i;
	printf("The answer to problem 2 is '%d'\n", a);
}

void Problems::problem3()
{
	long long a = 600851475143;
	for(long long i=2; sqrt((double)a)>i; ++i)
		if(MathLib::isMultiple(a, i))
			a /= i--;
	printf("The answer to problem 3 is '%d'\n", a);
}

void Problems::problem4()
{
	for(long i=1998; i>100; --i)
		for(long j=999; i/2<=j; --j)
			if(MathLib::isPalindromic(j*(i-j))){
				printf("The answer to problem 4 is '%d'\n", j*(i-j));
				return;
			}
}

void Problems::problem5()
{
	long a = 1;
	double log20 = log(20.0);
	for(long i=2; i<20; ++i){
		if(!MathLib::isPrime(i))
			continue;
		a *= (long)pow((double)i,(int)(log20/log((double)i)));
	}
	printf("The answer to problem 5 is '%d'\n", a);
}

void Problems::problem6()
{
	long x=0, y=0;
	for(int i=1; i<=100; ++i){
		x += i;
		y += i*i;
	}
	x *= x;
	printf("The answer to problem 6 is '%d'\n", x-y);
}

void Problems::problem7()
{
	int i=1;
	long a;
	for(a=3; i<10001; a+=2)
		if(MathLib::isPrime(a))
			i++;
	printf("The answer to problem 7 is '%d'\n", a-2);
}

void Problems::problem8()
{
	long long a = 0;
	long long t;
	for(int i=0; i<=1000-13; ++i){
		t = 1;
		for(int j=0; j<13; ++j)
			t *= (longNum[i+j]-'0');
		if(t>a)
			a = t;
	}
	printf("The answer to problem 8 is '%lld'\n", a);
}

void Problems::problem9()
{
	long a, b, c;
	for(c=998; c>=334; --c){
		for(b=1; b+c<1000; ++b){
			a = 1000-b-c;
			if(a*a + b*b == c*c){
				printf("The answer to problem 9 is '%d'\n", a*b*c);
				return;
			}
		}
	}
}

void Problems::problem10()
{
	long long a=2;
	for(long i=3; i<2000000; i+=2)
		if(MathLib::isPrime(i))
			a+=i;
	printf("The answer to problem 10 is '%lld'\n", a);
}

void Problems::problem11()
{
	long a = 0;
	long t;
	for(int i=0; i<20; ++i){
		for(int j=0; j<20; ++j){
			if(i < 17){
				t = grid20[i][j] * grid20[i+1][j] * grid20[i+2][j] * grid20[i+3][j];
				if(t>a)
					a=t;
			}
			if(j < 17){
				t = grid20[i][j] * grid20[i][j+1] * grid20[i][j+2] * grid20[i][j+3];
				if(t>a)
					a=t;
			}
			if(i < 17 && j < 17){
				t = grid20[i][j] * grid20[i+1][j+1] * grid20[i+2][j+2] * grid20[i+3][j+3];
				if(t>a)
					a=t;
				t = grid20[i][j+3] * grid20[i+1][j+2] * grid20[i+2][j+1] * grid20[i+3][j];
				if(t>a)
					a=t;
			}
		}
	}
	printf("The answer to problem 11 is '%d'\n", a);
}

void Problems::problem12()
{
	long a=1;
	for(int i=2; MathLib::numOfDivisors(a) <= 500; ++i)
		a += i;
	printf("The answer to problem 12 is '%d'\n", a);
}

void Problems::problem13()
{
	BigInt a(0);
	for(int i=0; i<100; ++i)
	{
		BigInt b(n100d50[i]);
		a += b;
	}
	char aOut[BigInt::BIG_INT_MAX_SIZE];
	a.getCStr(aOut, BigInt::BIG_INT_MAX_SIZE);
	char aBuf[11];
	memcpy(aBuf, aOut, 10);
	aBuf[10] = 0;
	printf("The answer to problem 13 is '%s'\n", aBuf);
}

void Problems::problem14()
{
	long a=1;
	int b=0;
	for(long i=2; i<1000000; ++i){
		long long x = i;
		int j;
		for(j=0; x!=1; ++j){
			if(x%2)
				x = 3*x + 1;
			else
				x /= 2;
		}
		if(j>b){
			b = j;
			a = i;
		}
	}
	printf("The answer to problem 14 is '%d'\n", a);
}

void Problems::problem15()
{
	long long x[21][21];
	for(int i=0; i<21; ++i)
	{
		x[0][i] = 1;
	}
	for(int i=1; i<21; ++i)
	{
		x[i][i] = x[i-1][i]*2;
		for(int j=i+1; j<21; ++j)
		{
			x[i][j] = x[i-1][j] + x[i][j-1];
		}
	}
	printf("The answer to problem 15 is '%lld'\n", x[20][20]);
}

void Problems::problem16()
{
	BigInt twoTo1000(2);
	twoTo1000 ^= 1000;
	long a = twoTo1000.getDigitSum();
	printf("The answer to problem 16 is '%d'\n", a);
}

void Problems::problem17()
{
	int a = 0;
	for(int i=0; i<10; ++i)
		a += letterCount[0][i]; //0-9
	a *= 9;
	for(int i=0; i<10; ++i)
		a += 10*letterCount[1][i]; //20-90
	for(int i=0; i<10; ++i)
		a += letterCount[2][i]; //10-19
	// a is now 0-99
	a *= 10;
	for(int i=1; i<10; ++i)
		a += 100*(letterCount[0][i] + hundredAnd); //0-9
	a -= 9*and;
	a += oneThousand;
	printf("The answer to problem 17 is '%d'\n", a);
}

void Problems::problem18()
{
	int a = 0;
	int t;
	int k;
	for(int i=0; i<16384; ++i){
		t=0;
		k=0;
		for(int j=0; j<15; ++j){
			t += sumTri[j][k];
			if(i&(1<<j))
				k++;
		}
		if(t>a)
			a = t;
	}
	printf("The answer to problem 18 is '%d'\n", a);
}

void Problems::problem19()
{
	int a=0;
	int d=2;
	for(int i=1901; i<=2000; ++i){
		for(int j=0; j<12; ++j){
			d += months[j];
			if((j==1) && (i%4==0))
				d++;
			d %= 7;
			if(!d)
				a++;
		}
	}
	printf("The answer to problem 19 is '%d'\n", a);
}

void Problems::problem20()
{
	BigInt one00Bang(1);
	for(int i=1; i<=100; ++i)
		one00Bang *= i;
	long a = one00Bang.getDigitSum();
	printf("The answer to problem 20 is '%d'\n", a);
}

void Problems::problem21()
{
	int a=0;
	for(int i=2; i<10000; ++i){
		long m = MathLib::sumOfDivisors(i);
		if(m>i){
			if(i == MathLib::sumOfDivisors(m)){
				if(m < 10000)
					a += i+m;
				else
					a += i;
			}
		}
	}
	printf("The answer to problem 21 is '%d'\n", a);
}

void Problems::problem22()
{
	static const int MAX_NAME_LEN = 12;
	static const int TOTAL_NAMES = 5163;
	long a = 0;
	char names[TOTAL_NAMES][MAX_NAME_LEN];
	std::ifstream pFile("p022_names.txt");
	if (pFile.is_open())
	{
		int i=0;
		pFile.ignore(1);
		do{
			pFile.get(names[i], MAX_NAME_LEN, '"');
			pFile.ignore(3);
			i++;
		}while(pFile.good() && (i<TOTAL_NAMES));
		pFile.close();
	}
	MathLib::quicksort(&(names[0][0]), MAX_NAME_LEN, 0, TOTAL_NAMES-1);
	int nameValue;
	for(int i=0; i<TOTAL_NAMES; ++i){
		nameValue = 0;
		for(int j=0; names[i][j]; ++j){
			nameValue += names[i][j] - '@';
		}
		a += nameValue*(i+1);
	}
	printf("The answer to problem 22 is '%d'\n", a);
}

void Problems::problem23()
{
	long a = 1;
	bool abundant;
	bool abund[28124];
	abund[0] = false;
	abund[1] = false;
	for(int i=2; i<=28123; ++i){
		abund[i] = (MathLib::sumOfDivisors(i) > i);
	}
	for(int i=2; i<=28123; ++i){
		abundant = false;
		for(int j=12; i-j>=12; ++j){
			if(abund[j] && abund[i-j]){
				abundant = true;
				break;
			}
		}
		if(!abundant)
			a += i;
	}
	printf("The answer to problem 23 is '%d'\n", a);
}

void Problems::problem24()
{
	long position = 999999;
	long facts[10];
	int digitsUsed[10];
	int i;
	for(i=0; i<10; ++i){
		facts[i] = MathLib::factorial(i);
		digitsUsed[i] = i;
	}
	unsigned long a=0;
	for(i=9; i>=0; --i){
		int digit = position/facts[i];
		a *= 10;
		a += digitsUsed[digit];
		position -= facts[i]*digit;
		for(int j=digit+1; j<10; ++j){
			digitsUsed[j-1] = digitsUsed[j];
		}
	}
	printf("The answer to problem 24 is '%u'\n", a);
}

void Problems::problem25()
{
	BigInt a(1);
	BigInt b(1);
	BigInt *ap = (&a);
	BigInt *bp = (&b);
	BigInt *cp;
	int i;
	for(i=3; i<30000; ++i){
		cp = ap;
		ap = bp;
		bp = cp;
		(*ap) += (*bp);
		if(ap->getMagnitude() >= 1000)
			break;
	}
	printf("The answer to problem 25 is '%d'\n", i);
}

void Problems::problem26()
{
	int a=0;
	int j;
	for(int i=999; i>0; i-=2){
		if(!MathLib::isPrime(i) || i==5)
			continue;
		BigInt nines(0);
		BigInt divisor(i);
		for(j=1; j<1020; j++){
			nines.times10ToN(1);
			nines += 9;
			if((nines%divisor).isZero())
				break;
		}
		if(j+1 == i){
			a = i;
			break;
		}
	}
	printf("The answer to problem 26 is '%d'\n", a);
}

void Problems::problem27()
{
	long ans = 0;
	int p = 0;
	int x;
	for(int a=-999; a<1000; ++a){
		for(int b=2; b<1000; ++b){
			if(!MathLib::isPrime(b))
				continue;
			for(x=0; ; x++){
				int num = x*x + a*x + b;
				if(num<2)
					break;
				if(!MathLib::isPrime(num))
					break;
			}
			if(x>p){
				p = x;
				ans = a*b;
			}
		}
	}
	printf("The answer to problem 27 is '%d'\n", ans);
}

void Problems::problem28()
{
	long a = 1;
	for(int i=3; i<=1001; i+=2){
		a += 4*i*i-6*(i-1);
	}
	printf("The answer to problem 28 is '%d'\n", a);
}

void Problems::problem29()
{
	int a = 99*99;
	for(int i=2; i*i<=100; ++i){
		if(i==4 || i==8 || i==9)
			continue;
		int maxPower = (int)(log(100.0)/log((double)i));
		for(int j=1; j<maxPower; ++j){
			for(int k=j+1; k<=maxPower; ++k){
				for(int p=2; p<=100; ++p){
					int kp = k*p;
					if((kp%j) || (kp/j > 100))
						continue;
					int l;
					for(l=1; l<j; ++l)
						if(!(kp%l) && (kp/l <= 100))
							break;
					if(l==j)
						a--;
				}
			}
		}
	}
	printf("The answer to problem 29 is '%d'\n", a);
}

void Problems::problem30()
{
	long a = 0;
	long fifths[10];
	for(long i=0; i<10; ++i){
		fifths[i] = i*i*i*i*i;
	}
	long sum;
	long num;
	for(long i=2; i<fifths[9]*7; ++i){
		num = i;
		sum = 0;
		for(int num=i; num!=0; num /= 10){
			sum += fifths[num%10];
		}
		if(sum == i)
			a += i;
	}
	printf("The answer to problem 30 is '%d'\n", a);
}

static const int pence[] = {1, 2, 5, 10, 20, 50, 100, 200};
long problem31r(long ways, int coin, int moneyLeft)
{
	if(coin == 0)
		return ways+1;
	int i;
	for(i=0; i<moneyLeft; i+=pence[coin]){
		ways = problem31r(ways, coin-1, moneyLeft-i);
	}
	if(i == moneyLeft)
		return ways+1;
	else
		return ways;
}
void Problems::problem31()
{
	long a = problem31r(0, 7, 200);
	printf("The answer to problem 31 is '%d'\n", a);
}

void Problems::problem32()
{
	long a = 0;
	bool digitsUsed[10];
	for(int i=1234; i<=9876; ++i){
		digitsUsed[0] = true;
		for(int j=1; j<10; ++j)
			digitsUsed[j] = false;
		int num = i;
		int j;
		for(j=0; j<4; ++j){
			if(digitsUsed[num%10])
				break;
			digitsUsed[num%10] = true;
			num /= 10;
		}
		if(j!=4)
			continue;
		if(i==3569)
			j=0;
		for(j=2; j<10; ++j){
			if(digitsUsed[j])
				continue;
			if(i%j != 0)
				continue;
			num = i/j;
			if(num < 1234)
				continue;
			digitsUsed[j] = true;
			int k;
			for(k=0; k<4; ++k){
				if(digitsUsed[num%10])
					break;
				digitsUsed[num%10] = true;
				num /= 10;
			}
			if(k==4){
				a += i;
				break;
			}
			num = i/j;
			for(int l=0; l<k; ++l){
				digitsUsed[num%10] = false;
				num /= 10;
			}
			digitsUsed[j] = false;
		}
		if(j!=10)
			continue;
		for(j=12; j<99; ++j){
			//stop
			if(digitsUsed[j%10] || digitsUsed[j/10] || (j%10 == j/10))
				continue;
			if(i%j != 0)
				continue;
			num = i/j;
			if(num < 123)
				continue;
			digitsUsed[j%10] = true;
			digitsUsed[j/10] = true;
			int k;
			for(k=0; k<3; ++k){
				if(digitsUsed[num%10])
					break;
				digitsUsed[num%10] = true;
				num /= 10;
			}
			if(k==3){
				a += i;
				break;
			}
			num = i/j;
			for(int l=0; l<k; ++l){
				digitsUsed[num%10] = false;
				num /= 10;
			}
			digitsUsed[j%10] = false;
			digitsUsed[j/10] = false;
		}
	}
	printf("The answer to problem 32 is '%d'\n", a);
}

void Problems::problem33()
{
	int n=1;
	int d=1;
	int i2, j2;
	for(int i=10; i<100; ++i){
		for(int j=10; j<i; ++j){
			if(i%10==0 && j%10==0)
				continue;
			if(i%10 == j%10){
				i2 = i/10;
				j2 = j/10;
			}else if(i%10 == j/10){
				i2 = i/10;
				j2 = j%10;
			}else if(i/10 == j%10){
				i2 = i%10;
				j2 = j/10;
			}else if(i/10 == j/10){
				i2 = i%10;
				j2 = j%10;
			}else
				continue;
			if(((double)j2)/i2 == ((double)j)/i){
				n *= j2;
				d *= i2;
			}
		}
	}
	for(int i=2; i<=n; ++i)
		if(n%i==0 && d%i==0){
			d/=i;
			n/=i;
			i--;
		}
	printf("The answer to problem 33 is '%d'\n", d);
}

void Problems::problem34()
{
	long a=0;
	long facts[10];
	facts[0] = 1;
	for(int i=1; i<10; ++i){
		facts[i] = MathLib::factorial(i);
	}
	long num, sum;
	for(long i=10; i<facts[9]*6; ++i){
		num = i;
		sum = 0;
		while(num>0){
			sum += facts[num%10];
			num /= 10;
		}
		if(sum == i)
			a += i;
	}
	printf("The answer to problem 34 is '%d'\n", a);
}

void Problems::problem35()
{
	int a=1;
	int digits[6];
	long num;
	int j, k;
	for(long i=3; i<1000000; i+=2){
		if(!MathLib::isPrime(i))
			continue;
		num = i;
		for(j=0; num>0; ++j){
			digits[j] = num % 10;
			num /= 10;
		}
		for(k=1; k<j; ++k){
			num = 0;
			for(int l=0; l<j; ++l){
				num *= 10;
				num += digits[(j+k-l-1)%j];
			}
			if(!MathLib::isPrime(num))
				break;
		}
		if(k==j)
			a++;
	}
	printf("The answer to problem 35 is '%d'\n", a);
}

void Problems::problem36()
{
	long a=0;
	int j;
	for(long i=1; i<1000000; ++i){
		if(!MathLib::isPalindromic(i))
			continue;
		int l = (int)(log((double)i)/log(2.0)+1);
		for(j=0; j<=l/2; ++j)
			if((!(i&(1<<j))) != (!(i&(1<<(l-j-1)))))
				break;
		if(j>l/2)
			a += i;
	}
	printf("The answer to problem 36 is '%d'\n", a);
}

void Problems::problem37()
{
	long a=0;
	int c=0;
	long num;
	for(long i=11; c<11; i+=2){
		if(!MathLib::isPrime(i))
			continue;
		num = i;
		while(num>0){
			if(!MathLib::isPrime_s(num))
				break;
			num /= 10;
		}
		if(num > 0)
			continue;
		long mod10s = 10;
		while(mod10s < i){
			if(!MathLib::isPrime_s(i%mod10s))
				break;
			mod10s *= 10;
		}
		if(mod10s < i)
			continue;
		c++;
		a+=i;
	}
	printf("The answer to problem 37 is '%d'\n", a);
}

void Problems::problem38()
{
	long a=0;
	long pan, prod, num;
	int digits[10];
	int l;
	for(int i=2; i<9; ++i){
		pan = 0;
		for(long j = (long)(pow(10.0, 9/i-1)); pan < 987654321; ++j){
			pan = j;
			for(int k=2; k<=i; ++k){
				prod = k*j;
				pan *= (long)pow(10.0,(int)(log10((double)prod))+1);
				pan += prod;
			}
			if(pan<123456789 || pan>987654321)
				continue;
			digits[0] = true;
			for(l=1; l<10; ++l)
				digits[l] = false;
			num = pan;
			for(l=0; l<9; ++l){
				if(digits[num%10])
					break;
				digits[num%10] = true;
				num /= 10;
			}
			if(l==9)
				if(pan>a)
					a = pan;
		}
	}
	printf("The answer to problem 38 is '%d'\n", a);
}

void Problems::problem39()
{
	int a=0, t=0, c;
	double p;
	for(int i=12; i<=1000; i+=2){
		c = 0;
		p = i;
		for(int d=3; p*(p-2.0*d)/2.0/(p-d) >= d; ++d)
			if((i*(i-2*d))%(i-d)==0)
				c++;
		if(c>t){
			t = c;
			a = i;
		}
	}
	printf("The answer to problem 39 is '%d'\n", a);
}

void Problems::problem40()
{
	int a=1;
	long d=0, j=0;
	long ten=1;
	for(int i=0; i<7; ++i){
		while(d<ten){
			j++;
			d += (long)log10((double)j) + 1;
		}
		a *= (j/((long)pow(10.0, d-ten)))%10;
		ten *= 10;
	}
	printf("The answer to problem 40 is '%d'\n", a);
}

long problem41r(bool *digitsUsed, int maxDigits, int digitsLeft, long num){
	if(digitsLeft == 0){
		if(MathLib::isPrime(num))
			return num;
		else
			return 0;
	}
	for(int i=maxDigits; i>0; --i){
		if(!digitsUsed[i]){
			digitsUsed[i] = true;
			long ret = problem41r(digitsUsed, maxDigits, digitsLeft-1, num*10+i);
			if(ret != 0)
				return ret;
			digitsUsed[i] = false;
		}
	}
	return 0;
}
void Problems::problem41()
{
	long a;
	bool digitsUsed[10];
	for(int i=1; i<10; ++i)
		digitsUsed[i] = false;
	digitsUsed[0] = true;
	for(int i=9; i>0; --i){
		a=problem41r(digitsUsed, i, i, 0);
		if(a != 0)
			break;
	}
	printf("The answer to problem 41 is '%d'\n", a);
}

void Problems::problem42()
{
	int a=0;
	static const int MAX_NAME_LEN = 15;
	static const int TOTAL_NAMES = 1786;
	char words[TOTAL_NAMES][MAX_NAME_LEN];
	std::ifstream pFile("p042_words.txt");
	if (pFile.is_open())
	{
		int i=0;
		pFile.ignore(1);
		do{
			pFile.get(words[i], MAX_NAME_LEN, '"');
			pFile.ignore(3);
			i++;
		}while(pFile.good() && (i<TOTAL_NAMES));
		pFile.close();
	}
	for(int i=0; i<TOTAL_NAMES; ++i){
		int num=0, j=0;
		while(words[i][j])
			num += words[i][j++] - '@';
		int tri=0;
		for(int k=1; tri<num; ++k){
			tri = k*(k+1)/2;
			if(tri==num)
				a++;
		}
	}
	printf("The answer to problem 42 is '%d'\n", a);
}

static const int primes7[] = {1,2,3,5,7,11,13,17}; // 1 is added for algorithm simplification
long long problem43r(bool *digitsUsed, int *digits, int curDigit){
	long long sum = 0;
	if(curDigit == -1){
		for(int i=0; i<10; ++i){
			sum *= 10;
			sum += digits[i];
		}
		return sum;
	}
	for(int i=0; i<10; ++i){
		if(!digitsUsed[i]){
			if(curDigit < 8)
				if((digits[curDigit+2]+digits[curDigit+1]*10+i*100)%primes7[curDigit] != 0)
					continue;
			digitsUsed[i] = true;
			digits[curDigit] = i;
			sum += problem43r(digitsUsed, digits, curDigit-1);
			digitsUsed[i] = false;
		}
	}
	return sum;
}
void Problems::problem43()
{
	bool digitsUsed[10];
	int digits[10];
	for(int i=0; i<10; ++i){
		digitsUsed[i] = false;
	}
	long long a = problem43r(digitsUsed,digits,9);
	printf("The answer to problem 43 is '%lld'\n", a);
}

void Problems::problem44()
{
	long long d, p1, p2, s, j;
	for(long i=1; true; ++i){
		p1 = i*(3*i-1)/2;
		for(j=1; j<i; ++j){
			p2 = j*(3*j-1)/2;
			d = p1 - p2;
			s = p1 + p2;
			if(MathLib::isPentagonal(d))
				if(MathLib::isPentagonal(s))
					break;
		}
		if(j<i)
			break;
	}
	printf("The answer to problem 44 is '%lld'\n", d);
}


void Problems::problem45()
{
	long t=40755, p=40755, h=40755;
	int ti, pi=165, hi=143;
	p += 1 + 3*pi++;
	for(ti=285; t!=p || t!=h; ++ti){
		t += ti+1;
		if(t>p)
			p += 1 + 3*pi++; 
		if(t>h)
			h += 1 + 4*hi++;
	}
	printf("The answer to problem 45 is '%d'\n", t);
}

void Problems::problem46()
{
	int a, i;
	for(a=3; true; a+=2){
		if(MathLib::isPrime(a))
			continue;
		for(i=1; a>2*i*i; ++i)
			if(MathLib::isPrime(a-2*i*i))
				break;
		if(a<=2*i*i)
			break;
	}
	printf("The answer to problem 46 is '%d'\n", a);
}

void Problems::problem47()
{
	long a, num;
	int c=0, d;
	for(a=2; true; ++a){
		d=0;
		num = a;
		if(num%2 == 0){
			d++;
			while(num%2 == 0)
				num /= 2;
		}
		for(int i=3; i<=sqrt((double)num); i+=2){
			if(num%i == 0){
				d++;
				while(num%i == 0)
					num /= i;
			}
		}
		if(a != 1)
			d++;
		if(d == 4)
			c++;
		else
			c=0;
		if(c == 4)
			break;
	}
	printf("The answer to problem 47 is '%d'\n", a-3);
}

void Problems::problem48()
{
	long long a=0, p;
	for(int i=1; i<=1000; ++i){
		p=1;
		for(int j=1; j<=i; ++j){
			p *= i;
			p %= 10000000000;
		}
		a += p;
		a %= 10000000000;
	}
	printf("The answer to problem 48 is '%lld'\n", a);
}

void Problems::problem49()
{
	int digits[10];
	int digitsC[10];
	int num;
	for(int i=1001; i<=9995; i+=2){
		if(!MathLib::isPrime(i))
			continue;
		for(int j=i+2; j*2<=9999+i; j+=2){
			if(!MathLib::isPrime(j))
				continue;
			if(!MathLib::isPrime(2*j-i))
				continue;
			for(int k=0; k<10; ++k){
				digits[k] = 0;
				digitsC[k] = 0;
			}
			num = i;
			for(int k=0; k<4; ++k){
				digits[num%10]++;
				num /= 10;
			}
			num = j;
			for(int k=0; k<4; ++k){
				digitsC[num%10]++;
				num /= 10;
			}
			for(int k=0; k<10; ++k){
				if(digits[k] != digitsC[k])
					goto nextJ;
				digitsC[k] = 0;
			}
			num = 2*j-i;
			for(int k=0; k<4; ++k){
				digitsC[num%10]++;
				num /= 10;
			}
			for(int k=0; k<10; ++k){
				if(digits[k] != digitsC[k])
					goto nextJ;
			}
			if(i == 1487)
				continue;
			printf("The answer to problem 49 is '%d%d%d'\n", i, j, 2*j-i);
			return;
			nextJ:;
		}
	}
}

void Problems::problem50()
{
	long a=2;
	for(int i=3; i+a<1000000; i+=2){
		if(MathLib::isPrime(i))
			a += i;
	}
	if(MathLib::isPrime(a)){
		printf("The answer to problem 50 is '%d'\n", a);
		return;
	}
	a-=2;
	for(int i=3; a>0; i+=2){
		if(!MathLib::isPrime(i))
			continue;
		if(MathLib::isPrime(a))
			break;
		a-=i;
	}
	printf("The answer to problem 50 is '%d'\n", a);
}

void Problems::problem51()
{
	long a, num;
	int digits[3];
	for(a=10001; true; a+=2){
		if(!MathLib::isPrime(a))
			continue;
		num = a/10;
		int c=0;
		while(num>0){
			if(num%10 == 1)
				c++;
			num /= 10;
		}
		if(c<3)
			continue;
		num = a/10;
		int j=0;
		for(int i=1; j<3; ++i, num /= 10)
			if(num%10 == 1)
				digits[j++] = i;
		c=1;
		long mask = (long)(pow(10.0,digits[0]) + pow(10.0,digits[1]) + pow(10.0,digits[2]));
		num = a;
		for(int i=2; i<10; ++i){
			num += mask;
			if(MathLib::isPrime(num))
				c++;
		}
		if(c==8)
			break;
	}
	printf("The answer to problem 51 is '%d'\n", a);
}

void Problems::problem52()
{
	long a = (long)(1.0/7.0*999999.0);
	printf("The answer to problem 52 is '%d'\n", a);
}

void Problems::problem53()
{
	int a=0;
	for(int n=23; n<=100; ++n){
		for(int r=2; r*2<=n; ++r){
			long choose = n;
			for( int i = 2; i <= r; ++i ) {
				choose *= (n-i+1);
				choose /= i;
				if(choose>1000000){
					if(r*2==n)
						a++;
					else
						a+=2;
					break;
				}
			}
		}
	}
	printf("The answer to problem 53 is '%d'\n", a);
}

void Problems::problem54()
{
	long a=0;
	int cards[1000][10];
	std::string line;
	std::ifstream myfile ("p054_poker.txt");
	if (myfile.is_open()){
		int j=0;
		while ( getline (myfile,line) ){
			for(int i=0; i<10; ++i){
				char card = line.at(i*3);
				char suit = line.at(i*3+1);
				if(card<='9')
					cards[j][i] = 4*(card - '2');
				else if(card=='T')
					cards[j][i] = 32;
				else if(card=='J')
					cards[j][i] = 36;
				else if(card=='Q')
					cards[j][i] = 40;
				else if(card=='K')
					cards[j][i] = 44;
				else if(card=='A')
					cards[j][i] = 48;
				switch(suit){
				case 'S':
					//cards[j][i] += 0;
					break;
				case 'C':
					cards[j][i] += 1;
					break;
				case 'D':
					cards[j][i] += 2;
					break;
				case 'H':
					cards[j][i] += 3;
					break;
				}
			}
			j++;
		}
		myfile.close();
	}
	for(int i=0; i<1000; ++i){
		for(int j=0; j<2; ++j){
			for(int k=0; k<4; ++k){
				int temp = cards[i][j*5+k];
				for(int l=4; l>k; --l){
					if(cards[i][j*5+l] < temp){
						temp = cards[i][j*5+l];
						cards[i][j*5+l] = cards[i][j*5+k];
						cards[i][j*5+k] = temp;
					}
				}
			}
		}
	}
	bool straight[2];
	bool flush[2];
	int kind[2];
	bool done[2];
	int high[2];
	for(int i=0; i<1000; ++i){
		straight[0] = true;
		straight[1] = true;
		high[0] = cards[i][4]/4;
		high[1] = cards[i][9]/4;
		for(int j=0; j<4; ++j){
			if(cards[i][j]/4+4-j != high[0])
				straight[0] = false;
			if(cards[i][j+5]/4+4-j != high[1])
				straight[1] = false;
		}
		kind[0] = 0;
		kind[1] = 0;
		int highPair1=0;
		int highPair2=0;
		for(int j=0; j<4; ++j){
			high[0] = cards[i][j]/4;
			high[1] = cards[i][5+j]/4;
			for(int k=j+1; k<5; ++k){
				if(cards[i][k]/4 == high[0]){
					if(high[0]>highPair1)
						highPair1 = high[0];
					kind[0]++;
				}
				if(cards[i][k+5]/4 == high[1]){
					if(high[1]>highPair2)
						highPair2 = high[1];
					kind[1]++;
				}
			}
		}
		kind[0] = kind[0]*13+highPair1;
		kind[1] = kind[1]*13+highPair2;
		flush[0] = true;
		flush[1] = true;
		high[0] = cards[i][4]%4;
		high[1] = cards[i][9]%4;
		for(int j=0; j<4; ++j){
			if(cards[i][j]%4 != high[0])
				flush[0] = false;
			if(cards[i][j+5]%4 != high[1])
				flush[1] = false;
		}
		for(int j=0; j<9; ++j){
			switch(j){
			case 0://Royal/straight flush
				done[0] = (flush[0] && straight[0]);
				done[1] = (flush[1] && straight[1]);
				high[0] = cards[i][4]/4;
				high[1] = cards[i][9]/4;
				break;
			case 1://4 of a kind
				done[0] = (kind[0]/13 == 6);
				done[1] = (kind[1]/13 == 6);
				high[0] = kind[0]%13;
				high[1] = kind[1]%13;
				break;
			case 2://Full House
				done[0] = (kind[0]/13 == 4);
				done[1] = (kind[1]/13 == 4);
				high[0] = kind[0]%13;
				high[1] = kind[1]%13;
				break;
			case 3://Flush
				done[0] = flush[0];
				done[1] = flush[1];
				high[0] = cards[i][4]/4;
				high[1] = cards[i][9]/4;
				break;
			case 4://Straight
				done[0] = straight[0];
				done[1] = straight[1];
				high[0] = cards[i][4]/4;
				high[1] = cards[i][9]/4;
				break;
			case 5://Three of a Kind
				done[0] = (kind[0]/13 == 3);
				done[1] = (kind[1]/13 == 3);
				high[0] = kind[0]%13;
				high[1] = kind[1]%13;
				break;
			case 6://Two Pairs
				done[0] = (kind[0]/13 == 2);
				done[1] = (kind[1]/13 == 2);
				high[0] = kind[0]%13;
				high[1] = kind[1]%13;
				break;
			case 7://One Pair
				done[0] = (kind[0]/13 == 1);
				done[1] = (kind[1]/13 == 1);
				high[0] = kind[0]%13;
				high[1] = kind[1]%13;
				break;
			case 8://High Card
				done[0] = true;
				done[1] = true;
				high[0] = cards[i][4]/4;
				high[1] = cards[i][9]/4;
				break;
			}
			if(done[0] && done[1]){
				if(high[0] > high[1])
					a++;
				if(high[0] == high[1]){
					if(cards[i][4]/4 > cards[i][9]/4)
						a++;
				}
				break;
			}else if(done[0]){
				a++;
				break;
			}else if(done[1])
				break;
		}
	}
	printf("The answer to problem 54 is '%d'\n", a);
}

void Problems::problem55()
{
	bool checked[10000];
	for(int i=1; i<10000; i++){
		checked[i] = false;
	}
	int a = 0;
	int ib10000;
	BigInt p, r;
	for(int i=10; i<10000; i++){
		if(checked[i])
			continue;
		ib10000=1;
		p = i;
		r = p;
		if(!p.isPalindrome()){
			r.reverse();
			int index = r.getLong();
			if(!checked[index] && p.charAt(0)!='0'){
				checked[index] = true;
				ib10000++;
			}
		}
		int j=0;
		do{
			p += r;
			r = p;
			r.reverse();
			if(!BigInt::absCmp(p, 10000)){
				int index = p.getLong();
				if(!checked[index]){
					checked[index] = true;
					ib10000++;
					if(p.charAt(0)!='0'){
						checked[r.getLong()] = true;
						ib10000++;
					}
				}
			}
			j++;
		}while(!p.isPalindrome() && j<50);
		if(j==50){
			a += ib10000;
			continue;
		}
		if(!BigInt::absCmp(p, 10000)){
			checked[p.getLong()] = false;
		}
	}
	printf("The answer to problem 55 is '%d'\n", a);
}

void Problems::problem56()
{
	BigInt p, m;
	int a=0;
	for(int i=95; i<100; ++i){
		p = i;
		m = i;
		for(int j=2; j<100; ++j){
			p *= m;
			int t = p.getDigitSum();
			if(t>a)
				a=t;
		}
	}
	printf("The answer to problem 56 is '%d'\n", a);
}

void Problems::problem57()
{
	//(a+2*b)/(a+b)
	int a=0;
	double b=3, c=2;
	for(int i=1; i<1000; ++i){
		b = b+2*c;
		c = b-c;
		if((int)log10(b) != (int)log10(c))
			a++;
		if(i%3==0){
			b/=10.0;
			c/=10.0;
		}
	}
	printf("The answer to problem 57 is '%d'\n", a);
}

void Problems::problem58()
{
	long n=1;
	double p=0;
	for(int a=2; true; a+=2){
		n += a;
		if(MathLib::isPrime(n))
			p++;
		n += a;
		if(MathLib::isPrime(n))
			p++;
		n += a;
		if(MathLib::isPrime(n))
			p++;
		n += a;
		if(p/(2*a+1) < .1){
			printf("The answer to problem  is '%d'\n", a+1);
			return;
		}
	}
}

void Problems::problem59()
{
	static const int CIPHER_SIZE = 1202;
	long a=0;
	char cipher[CIPHER_SIZE];
	memset(cipher, 0, CIPHER_SIZE);
	std::string line;
	std::ifstream myfile ("p059_cipher.txt");
	if (myfile.is_open()){
		int j=0;
		while ( getline (myfile,line,',') ){
			cipher[j++] = stoi(line);
		}
		myfile.close();
	}
	char key[3];
	memset(key, 0, 3);
	int lock[3];
	lock[0]=1;
	lock[1]=1;
	lock[2]=1;
	for(int i=12; true; ++i){
		if(lock[i%3]>2)
			continue;
		if(cipher[i] & 0x40){
			char bump = (cipher[i] ^ ' ');
			if(key[i%3] == bump)
				lock[i%3]++;
			else{
				key[i%3] = bump;
				lock[i%3] = 1;
			}
		}
		if(lock[0]>2 && lock[1]>2 && lock[2]>2)
			break;
	}
	for(int i=0; i<CIPHER_SIZE-1; i++){
		char letter = (cipher[i] ^ key[i%3]);
		a += letter;
		printf("%c", letter);
	}
	printf("\nThe answer to problem 59 is '%d'\n", a);
}

long problem60r(long *primes, long *mask, int level, int prev)
{
	if(level == 5){
		long sum=0;
		for(int i=0; i<5; ++i){
			sum += primes[i];
		}
		return sum;
	}
	for(int i=3; i<prev; i+=2){
		if(!MathLib::isPrime(i) || i == 5)
			continue;
		if(i==673)
			primes[4] = 3;
		if(i==109)
			primes[4] = 3;
		mask[level] = (long)pow(10.0, (int)log10((double)i)+1);
		for(int j=0; j<level; ++j){
			if(!MathLib::isPrime(mask[j]*i+primes[j]))
				goto nextI;
			if(!MathLib::isPrime(mask[level]*primes[j]+i))
				goto nextI;
		}
		primes[level] = i;
		long ret = problem60r(primes, mask, level+1, i);
		if(ret)
			return ret;
		nextI:;
	}
	return 0;
}
void Problems::problem60()
{
	long primes[5];
	long mask[5];
	long a = problem60r(primes, mask, 0, 1000000);
	printf("The answer to problem 60 is '%d'\n", a);
}

int polyNum[6][100];
int polyI[6];
bool used[6];
int seqNum[6];
int problem61r(int prev, int level)
{
	if(level == 5){
		if(seqNum[4]%100 != seqNum[5]/100)
			return 0;
		int sum=0;
		for(int i=0; i<6; ++i)
			sum += seqNum[i];
		return sum;
	}
	int j=0;
	for(int i=0; j<5-level; ++i){
		if(used[i])
			continue;
		j++;
		for(int k=0; k<polyI[i]; ++k){
			if(prev%100 != polyNum[i][k]/100)
				continue;
			seqNum[level] = polyNum[i][k];
			used[i] = true;
			int ret = problem61r(polyNum[i][k], level+1);
			if(ret)
				return ret;
			used[i] = false;
		}
	}
	return 0;
}
void Problems::problem61()
{
	int temp=1, a=0;
	for(int i=0; i<6; ++i){
		polyI[i] = 0;
		used[i] = false;
		seqNum[i] = 0;
	}
	for(int i=1; i*(i+1)/2 < 10000; ++i){
		temp = i*(i+1)/2;
		if(temp >= 1000 && temp < 10000){
			polyNum[0][polyI[0]++] = temp;
		}
		temp = i*i;
		if(temp >= 1000 && temp < 10000){
			polyNum[1][polyI[1]++] = temp;
		}
		temp = i*(3*i-1)/2;
		if(temp >= 1000 && temp < 10000){
			polyNum[2][polyI[2]++] = temp;
		}
		temp = i*(2*i-1);
		if(temp >= 1000 && temp < 10000){
			polyNum[3][polyI[3]++] = temp;
		}
		temp = i*(5*i-3)/2;
		if(temp >= 1000 && temp < 10000){
			polyNum[4][polyI[4]++] = temp;
		}
		temp = i*(3*i-2);
		if(temp >= 1000 && temp < 10000){
			polyNum[5][polyI[5]++] = temp;
		}
	}
	for(int i=0; i<polyI[5]; ++i){
		seqNum[5] = polyNum[5][i];
		a = problem61r(polyNum[5][i], 0);
		if(a)
			break;
	}
	printf("The answer to problem 61 is '%d'\n", a);
}

void Problems::problem62()
{
	long long cube1, cube2, temp;
	int digits, p;
	int digitDistro1[10];
	int digitDistro2[10];
	for(long long i=1; true; ++i){
		cube1 = i*i*i;
		digits = (int)log10((double)cube1);
		for(int k=0; k<10; ++k){
			digitDistro1[k] = 0;
		}
		temp = cube1;
		while(temp){
			digitDistro1[temp%10]++;
			temp /= 10;
		}
		p=1;
		for(long long j=i+1; true; ++j){
			cube2 = j*j*j;
			if(digits != (int)log10((double)cube2))
				break;
			for(int k=0; k<10; ++k){
				digitDistro2[k] = 0;
			}
			temp = cube2;
			while(temp){
				digitDistro2[temp%10]++;
				temp /= 10;
			}
			int l;
			for(l=0; l<10; ++l){
				if(digitDistro1[l] != digitDistro2[l])
					break;
			}
			if(l==10)
				p++;
		}
		if(p>=5)
			break;
	}
	printf("The answer to problem 62 is '%lld'\n", cube1);
}

void Problems::problem63()
{
	int a=0;
	for(double i=1.0; log10(pow(9.0,i))+1>i; ++i){
		for(double j=1.0; j<9.9; ++j){
			if((int)log10(pow(j,i))+1==i)
				a++;
		}
	}
	printf("The answer to problem 63 is '%d'\n", a);
}

void Problems::problem64()
{
	int a=0;
	double sqrtI;
	for(int i=2; i<10000; ++i){
		sqrtI = sqrt((double)i);
		if((double)((int)sqrtI) == sqrtI)
			continue;
		int j=0, p=0, q=1, n, ping;
		do{
			n = (int)((sqrtI+p)/q);
			ping = p - n*q;
			p = -ping;
			q = (i-ping*ping)/q;
			j++;
		}while(q != 1);
		if(j%2)
			a++;
	}
	printf("The answer to problem 64 is '%d'\n", a);
}

void Problems::problem65()
{
	long a=0;
	BigInt p(1), q(0), temp;
	int d;
	for(int i=100; i>0; --i){
		if(i%3==0)
			d=2*i/3;
		else if(i==1)
			d=2;
		else
			d=1;
		temp = p;
		p = p*d+q;
		q = temp;
	}
	a = p.getDigitSum();
	printf("The answer to problem 65 is '%d'\n", a);
}

/*
sqrt((x^2 - 1)/D) = y
x/sqrt(D) > y

An = bn * An-1 + An-2
Bn = bn * Bn-1 + Bn-2
A-1 = 1
B-1 = 0
A0 = b0
B0 = 1
*/
void Problems::problem66()
{
	BigInt x0, y0, x1, y1, x2, y2, xMax=0;
	int a=0;
	for(int D=2; D<=1000; ++D)
	{
		double sqrtI = sqrt((double)D);
		if((double)((int)sqrtI) == sqrtI)
			continue;
		x2 = 1;
		y2 = 0;
		x1 = (int)sqrtI;
		y1 = 1;
		int p=0, q=1, n=(int)sqrtI, ping;
		while(true){
			ping = p - n*q;
			p = -ping;
			q = (D-ping*ping)/q;
			n = (int)((sqrtI+p)/q);
			x0 = x1*n + x2;
			y0 = y1*n + y2;
			x2 = x1;
			y2 = y1;
			x1 = x0;
			y1 = y0;
			if(x0*x0-y0*y0*D == 1)
				break;
		}
		if(BigInt::absCmp(x0, xMax)){
			xMax = x0;
			a = D;
		}
	}
	printf("The answer to problem 66 is '%d'\n", a);
}

/*
void Problems::problem()
{
	
	printf("The answer to problem  is '%d'\n", a);
}
*/