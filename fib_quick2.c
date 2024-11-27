//------------------------------------------------------------------------------
// BigNum
// <Windows>
//   $ gcc -O3 -Wall fib_quick2.c -static -lgmp -o fib_quick2.c.exe & strip fib_quick2.c.exe
//   $ fib_quick2.c.exe [NUM]
// <Linux>
//   $ gcc -O3 -Wall ./fib_quick2.c -static -lgmp -o ./fib_quick2.c.bin ; strip ./fib_quick2.c.bin
//   $ ./fib_quick2.c.bin [NUM]
//
// 以下のサイトを参考にした。
//   フィボナッチ数を計算する多分最速の方法
//   https://qiita.com/mp2147483647/items/4b450a$f21894c2f9e712
//------------------------------------------------------------------------------
#include <gmp.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	mpz_t value[2];
}
$struct_ai;

mpz_t $f1, $f2;
mpz_t $l1, $l2, $l3;

$struct_ai
RtnFibIntr(
	int num
)
{
	$struct_ai rtn;

	if(! num)
	{
		mpz_init_set_si(rtn.value[0], 1);
		mpz_init_set_si(rtn.value[1], 2);
		return rtn;
	}

	if(! (num & 1))
	{
		int _numHalf = (int)(num / 2);
		int _iPm = (! (_numHalf & 1) ? 1 : -1);
		$struct_ai _ai = RtnFibIntr(_numHalf);
			mpz_set($f1, _ai.value[0]);
			mpz_set($l1, _ai.value[1]);
			mpz_mul($l2, $l1, $l1);
			mpz_init_set_si($l3, (2 * _iPm));
			mpz_sub($l2, $l2, $l3);
			mpz_mul($f2, $f1, $l1);
			mpz_init_set_si($l3, _iPm);
			mpz_sub($f2, $f2, $l3);
		mpz_clear(_ai.value[0]);
		mpz_clear(_ai.value[1]);
	}
	else if((num % 8) == 7)
	{
		$struct_ai _ai = RtnFibIntr(num + 1);
			mpz_set($f1, _ai.value[0]);
			mpz_set($l1, _ai.value[1]);
			mpz_mul_ui($f2, $f1, 2);
			mpz_sub($f2, $f2, $l1);
			mpz_mul_ui($l2, $f2, 3);
			mpz_sub($l2, $l2, $f1);
		mpz_clear(_ai.value[0]);
		mpz_clear(_ai.value[1]);
	}
	else
	{
		$struct_ai _ai = RtnFibIntr(num - 1);
			mpz_set($f1, _ai.value[0]);
			mpz_set($l1, _ai.value[1]);
			mpz_mul_ui($f2, $f1, 3);
			mpz_sub($f2, $f2, $l1);
			mpz_mul_ui($l2, $f2, 2);
			mpz_sub($l2, $l2, $f1);
		mpz_clear(_ai.value[0]);
		mpz_clear(_ai.value[1]);
	}

	mpz_init_set(rtn.value[0], $f2);
	mpz_init_set(rtn.value[1], $l2);

	return rtn;
}

void
SubFib(
	int num
)
{
	if(num <= 0)
	{
		return;
	}

	mpz_init($f1);
	mpz_init($f2);
	mpz_init($l1);
	mpz_init($l2);
	mpz_init($l3);

	$struct_ai _ai = RtnFibIntr(num - 1);
		gmp_printf("%zd\t%Zd\n", num, _ai.value[0]);
	mpz_clear(_ai.value[0]);
	mpz_clear(_ai.value[1]);

	mpz_clear($f1);
	mpz_clear($f2);
	mpz_clear($l1);
	mpz_clear($l2);
	mpz_clear($l3);
}

int
main(
	int ARGC,
	char *ARGV[]
)
{
	int num = 0;
	if(ARGC > 1)
	{
		num = atoi(ARGV[1]);
	}
	SubFib(num);
	return 0;
}
