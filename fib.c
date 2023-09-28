//------------------------------------------------------------------------------
// BigNum
// $ gcc -O3 -Wall -o fib.c.exe fib.c -lgmp & strip fib.c.exe
// $ fib.c.exe [NUM]
//------------------------------------------------------------------------------
#include <gmp.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void
subFib(
	int_fast64_t iNum
)
{
	if(iNum < 0)
	{
		return;
	}

	puts("0\t0");
	if(iNum < 1)
	{
		return;
	}

	puts("1\t1");
	if(iNum < 2)
	{
		return;
	}

	uint_fast64_t BufMax = 1000;
	const uint_fast64_t BufDMZ = 5000;
	uint_fast64_t BufEnd = 0;

	mpz_t fib0, fib1, fib2;
		mpz_init_set_si(fib0, 0);
		mpz_init_set_si(fib1, 1);
		mpz_init_set_si(fib2, 0);
	int_fast64_t iCnt = 1;

	char *Buf = calloc((BufMax + BufDMZ), sizeof(char));

	while(iNum > iCnt)
	{
		mpz_add(fib2, fib1, fib0);
		mpz_set(fib0, fib1);
		mpz_set(fib1, fib2);
		++iCnt;

		BufEnd += gmp_sprintf((Buf + BufEnd), "%lld\t%Zd\n", iCnt, fib1);

		if(BufEnd >= BufMax)
		{
			BufMax *= 2;
			Buf = realloc(Buf, ((BufMax + BufDMZ) * sizeof(char)));
		}
	}

	fputs(Buf, stdout);

	free(Buf);

	///printf("BufEnd/BufMax = %llu/%llu\n", BufEnd, BufMax);
}

int
main(
	int ARGC,
	char* ARGV[]
)
{
	int_fast64_t iNum = 0;
	if(ARGC > 1)
	{
		iNum = atoll(ARGV[1]);
	}
	subFib(iNum);
	return 0;
}
