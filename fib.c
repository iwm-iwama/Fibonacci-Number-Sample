//------------------------------------------------------------------------------
// BigNum
// $ gcc -O3 -Wall -o fib.c.exe fib.c -lgmp & strip fib.c.exe
// $ fib.c.exe [NUM]
//------------------------------------------------------------------------------
#include <gmp.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
subFib(
	int iNum
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

	mpz_t fib0, fib1, fib2;
		mpz_init_set_si(fib0, 0);
		mpz_init_set_si(fib1, 1);
		mpz_init_set_si(fib2, 0);
	size_t iCnt = 1;

	// Buf Default
	const size_t BufBase = 5000;
	// strlen(fib1) ≒ iCnt * 0.21
	const double BufDmzRate = 0.21;
	//           Average   ProcCount
	// (BufDmzRate * 0.5 * 100) => (BufDmzRate * 50)
	const double BufAddAve = BufDmzRate * 50;
	size_t BufDmz = BufBase * BufDmzRate;
	size_t BufMax = BufBase * BufAddAve;
	char *Buf = calloc((BufDmz + BufMax), sizeof(char));
	size_t BufEnd = 0;

	while(iNum > iCnt)
	{
		mpz_add(fib2, fib1, fib0);
		mpz_set(fib0, fib1);
		mpz_set(fib1, fib2);
		++iCnt;

		BufEnd += gmp_sprintf((Buf + BufEnd), "%ld\t%Zd\n", iCnt, fib1);

		if(BufEnd >= (int)BufMax)
		{
			///printf("[%ld] Buf=%ld\tLen=%ld\tDiff=%ld\n", iCnt, (BufDmz + BufMax), strlen(Buf), (BufDmz + BufMax) - strlen(Buf));
			fputs(Buf, stdout);

			size_t _i1 = iCnt + BufBase;
			BufDmz = _i1 * BufDmzRate;
			BufMax = _i1 * BufAddAve;
			Buf = realloc(Buf, ((BufDmz + BufMax) * sizeof(char)));
			*Buf = 0;
			BufEnd = 0;
		}
	}

	///printf("[%ld] Buf=%ld\tLen=%ld\tDiff=%ld\n", iCnt, (BufDmz + BufMax), strlen(Buf), (BufDmz + BufMax) - strlen(Buf));
	fputs(Buf, stdout);

	free(Buf);
}

int
main(
	int ARGC,
	char* ARGV[]
)
{
	int iNum = 0;
	if(ARGC > 1)
	{
		iNum = atoll(ARGV[1]);
	}
	subFib(iNum);
	return 0;
}
