//------------------------------------------------------------------------------
// BigNum
// <Windows>
//   $ gcc -O3 -Wall fib_quick.c -static -lgmp -o fib_quick.c.exe & strip fib_quick.c.exe
//   $ fib_quick.c.exe [NUM]
// <Linux>
//   $ gcc -O3 -Wall ./fib_quick.c -static -lgmp -o ./fib_quick.c.bin ; strip ./fib_quick.c.bin
//   $ ./fib_quick.c.bin [NUM]
//------------------------------------------------------------------------------
#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>

#define   N    2

void fib_mul(
	mpz_t matResult[N][N],
	mpz_t mat1[N][N],
	mpz_t mat2[N][N]
)
{
	for(int _i1 = 0; _i1 < N; _i1++)
	{
		for(int _i2 = 0; _i2 < N; _i2++)
		{
			mpz_init(matResult[_i1][_i2]);
		}
	}

	mpz_t fib_tmp;
		mpz_init(fib_tmp);
		for(int _i1 = 0; _i1 < N; _i1++)
		{
			for(int _i2 = 0; _i2 < N; _i2++)
			{
				for(int _i3 = 0; _i3 < N; _i3++)
				{
					mpz_mul(fib_tmp, mat1[_i1][_i3], mat2[_i3][_i2]);
					mpz_add(matResult[_i1][_i2], matResult[_i1][_i2], fib_tmp);
				}
			}
		}
		mpz_clear(fib_tmp);
}

void fib_pow(
	mpz_t matResult[N][N],
	mpz_t mat1[N][N],
	int num
)
{
	if(num < 2)
	{
		for(int _i1 = 0; _i1 < N; _i1++)
		{
			for(int _i2 = 0; _i2 < N; _i2++)
			{
				mpz_set(matResult[_i1][_i2], mat1[_i1][_i2]);
			}
		}
		return;
	}

	mpz_t fib_tmp[N][N];

		// fib_tmp[2][2] = {{0, 0}, {0, 0}}
		for(int _i1 = 0; _i1 < N; _i1++)
		{
			for(int _i2 = 0; _i2 < N; _i2++)
			{
				mpz_init(fib_tmp[_i1][_i2]);
			}
		}

		if((num % 2) == 0)
		{
			fib_pow(fib_tmp, mat1, (int)(num / 2));
			fib_mul(matResult, fib_tmp, fib_tmp);
		}
		else
		{
			int i1 = num - 1;
			fib_pow(fib_tmp, mat1, i1);
			fib_mul(matResult, mat1, fib_tmp);
		}

		for(int _i1 = 0; _i1 < N; _i1++)
		{
			for(int _i2 = 0; _i2 < N; _i2++)
			{
				mpz_clear(fib_tmp[_i1][_i2]);
			}
		}
}

void fib_output(
	int num
)
{
	if(num < 0)
	{
		return;
	}

	switch(num)
	{
		case 0:
			puts("0\t0");
			return;
			break;
		case 1:
			puts("1\t1");
			return;
			break;
		case 2:
			puts("2\t1");
			return;
			break;
	}

	mpz_t matResult[N][N];
	mpz_t mat1[N][N];

		// mat1[2][2] = {{1, 1}, {1, 0}}
		for(int _i1 = 0; _i1 < N; _i1++)
		{
			for(int _i2 = 0; _i2 < N; _i2++)
			{
				mpz_init_set_si(mat1[_i1][_i2], 1);
			}
		}
		mpz_init(mat1[1][1]);

		fib_pow(matResult, mat1, num);
		gmp_printf("%zu\t%Zd\n", num, matResult[0][1]);

		for(int _i1 = 0; _i1 < N; _i1++)
		{
			for(int _i2 = 0; _i2 < N; _i2++)
			{
				mpz_clear(matResult[_i1][_i2]);
				mpz_clear(mat1[_i1][_i2]);
			}
		}
}

int
main(
	int ARGC,
	char* ARGV[]
)
{
	int num = 0;
	if(ARGC > 1)
	{
		num = atoi(ARGV[1]);
	}

	// Normal: [num]
	fib_output(num);

	// Debug: [0..num]
	/*
		for(int _i1 = 0; _i1 <= num; _i1++)
		{
			fib_output(_i1);
		}
	*/

	return 0;
}
