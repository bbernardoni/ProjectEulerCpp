#include "Problems.h"

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

long Problems::problem60r(long *primes, long *mask, int level, int prev)
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
int Problems::problem61r(int prev, int level)
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

void Problems::problem67()
{
	int a;
	int tri[100][100];
	int sums[100];
	std::string line;
	std::ifstream myfile ("p067_triangle.txt");
	if (myfile.is_open()){
		int i=0;
		int j=0;
		std::string token;
		std::stringstream iss;
		while (getline(myfile, line)){
			iss << line;
			while (getline(iss, token, ' ')){
				tri[i][j] = atoi(token.c_str());
				j++;
			}
			j=0;
			i++;
			iss.clear();
		}
		myfile.close();
	}
	for(int i=0; i<100; ++i)
		sums[i] = tri[99][i];
	for(int i=98; i>=0; --i){
		for(int j=0; j<=i; ++j){
			if(sums[j] < sums[j+1]){
				sums[j] = sums[j+1];
			}
			sums[j] += tri[i][j];
		}
	}
	a = sums[0];
	printf("The answer to problem 67 is '%d'\n", a);
}

void Problems::problem68()
{
/*
I cheated this one through intelligent guess and check
to get a 16 digit number 10 must be on the outside
to get the most significant number is determined by the lowest external node
put 6-10 externally to get highest low external node of 6
total sum = (6+7+8+9+10) + 2*(1+2+3+4+5) = 40 + 2*15 = 70
row sum = 70 / 5 = 14
each row must total to 14
10 row needs 3&1
6 row needs 5&3
keep building to get solution below
   10
     3  9
   5   1
 6  2 4 8
	 7
*/
	printf("The answer to problem 68 is 6531031914842725\n");
}

void Problems::problem69()
{
	/* phi(n) = n * (1-1/p1) * (1-1/p2) ...  * (1-1/pr)
	n / phi(n) = 1/( (1-1/p1)*(1-1/p2)...*(1-1/pr) )
	must have most unique primes */
	long a = 2;
	for(long i=3; a*i<1000000; i+=2)
		if(MathLib::isPrime(i))
			a *= i;
	printf("The answer to problem 69 is '%d'\n", a);
}

void Problems::problem70()
{
	const static int PRIMES_TESTING = 1000;
	double phiPerN, maxPhiPerN = 0.0;
	long primes[PRIMES_TESTING];
	int digitDistro1[10];
	int digitDistro2[10];
	long a=1, temp;
	int j=0;
	primes[j++] = 2;
	for(long i=3; j<PRIMES_TESTING; i+=2){
		if(MathLib::isPrime(i))
			primes[j++] = i;
	}
	for(long i=10; i<10000000; ++i){
		phiPerN = 1.0;
		temp = i;
		for(j=0; primes[j]<=temp&&j<PRIMES_TESTING; ++j){
			if(temp%primes[j] == 0){
				phiPerN *= (1.0 - 1.0/primes[j]);
				while(temp%primes[j] == 0)
					temp /= primes[j];
				if(phiPerN < maxPhiPerN+0.00000001)
					break;
			}
		}
		if(phiPerN < maxPhiPerN+0.00000001)
			continue;
		if(phiPerN == 1.0)
			continue;
		for(int k=0; k<10; ++k){
			digitDistro1[k] = 0;
			digitDistro2[k] = 0;
		}
		temp = i;
		while(temp){
			digitDistro1[temp%10]++;
			temp /= 10;
		}
		temp = (long)(i*phiPerN+0.0001);
		while(temp){
			digitDistro2[temp%10]++;
			temp /= 10;
		}
		int l;
		for(l=0; l<10; ++l){
			if(digitDistro1[l] != digitDistro2[l])
				break;
		}
		if(l==10){
			maxPhiPerN = phiPerN;
			a=i;
		}
	}
	printf("The answer to problem 70 is '%d'\n", a);
}

void Problems::problem71()
{
	long n=2, d=5, a;
	while(d<1000000){
		a = n;
		n+=3;
		d+=7;
		for(int i=2; i<n; i+=2){
			if(n%i == 0 && d%i == 0){
				n/=i;
				d/=i;
			}
			if(i==2)
				i--;
		}
	}
	printf("The answer to problem 71 is '%d'\n", a);
}

void Problems::problem72()
{
	const static int PRIMES_BELOW_1E6 = 78498;
	long primes[PRIMES_BELOW_1E6];
	int j=0;
	primes[j++] = 2;
	long temp;
	long long a=0;
	double phi;
	for(long i=3; j<PRIMES_BELOW_1E6; i+=2){
		if(MathLib::isPrime(i))
			primes[j++] = i;
	}
	for(long i=2; i<=8; ++i){
		phi = (double)i;
		temp = i;
		for(int j=0; primes[j]<=temp&&j<PRIMES_BELOW_1E6; ++j){
			if(temp%primes[j] == 0){
				phi *= (1.0 - 1.0/primes[j]);
				while(temp%primes[j] == 0)
					temp /= primes[j];
			}
		}
		a += (long)(phi+0.001);
	}
	printf("The answer to problem 72 is '%lld'\n", a);
}

void Problems::problem73()
{
	long a = 0;
	for(int i=5; i<=12000; ++i){
		for(int j=i/3+1; j<(i+1)/2; ++j)
			if(MathLib::gcd(i, j) == 1)
				a++;
	}
	printf("The answer to problem 73 is '%d'\n", a);
}

void Problems::problem74()
{
	long a=0;
	long cycle[61];
	long facts[10];
	int j;
	long num, temp;
	facts[0] = 1;
	for(int i=1; i<10; ++i){
		facts[i] = facts[i-1] * i;
	}
	for(int i=1; i<1000000; ++i){
		j=0;
		num=i;
		cycle[j++] = i;
		while(true){
			temp = num;
			num = 0;
			while(temp){
				num += facts[temp%10];
				temp /= 10;
			}
			for(int k=0; k<j; ++k){
				if(num==cycle[k])
					goto cycleDone;
			}
			cycle[j++] = num;
		}
cycleDone:
		if(j==60)
			a++;
	}
	printf("The answer to problem 74 is '%d'\n", a);
}

void Problems::problem75()
{
	long a=0;//11;
	int k=0, l;
	std::vector<long> perim;
	perim.push_back(12);
	for(long i=2; 2*i*(i+1)<=1500000; ++i){
		for(long j=1; i>j && 2*i*(i+j)<=1500000; ++j){
			if(i%2 == j%2)
				continue;
			if(MathLib::gcd(i, j) != 1)
				continue;
			if(std::find(perim.begin(), perim.end(), 2*i*(i+j)) == perim.end())
				perim[k++] = 2*i*(i+j);
			if(k>100000)
				break;
		}
	}
	for(long i=12; i<1500000; ++i){

	}
	printf("The answer to problem 75 is '%d'\n", a);
}

/*
void Problems::problem()
{
	long a=0;
	printf("The answer to problem  is '%d'\n", a);
}
*/