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
long Problems::problem31r(long ways, int coin, int moneyLeft)
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

long Problems::problem41r(bool *digitsUsed, int maxDigits, int digitsLeft, long num){
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
long long Problems::problem43r(bool *digitsUsed, int *digits, int curDigit){
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