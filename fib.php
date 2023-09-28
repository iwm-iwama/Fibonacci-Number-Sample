#!/usr/bin/php
<?php
//--------------------------------------------------------------------
// BigNum: extension=gmp
// $ php.exe fib.php [NUM]
//--------------------------------------------------------------------
function subFib(
	$num
)
{
	if($num < 0)
	{
		return;
	}

	echo "0\t0", PHP_EOL;
	if($num < 1)
	{
		return;
	}

	echo "1\t1", PHP_EOL;
	if($num < 2)
	{
		return;
	}

	$fib0 = 0;
	$fib1 = 1;
	$fib2 = 0;
	$cnt = 1;

	$Buf = "";

	while($num > $cnt)
	{
		$fib2 = gmp_add($fib1, $fib0);
		$fib0 = $fib1;
		$fib1 = $fib2;
		++$cnt;

		$Buf .= $cnt;
		$Buf .= "\t";
		$Buf .= gmp_strval($fib1);
		$Buf .= PHP_EOL;
	}

	echo $Buf;
}

function main()
{
	$ARGC = $_SERVER['argc'];
	$ARGV = $_SERVER['argv'];
	$num = 0;
	if($ARGC > 1 && is_numeric($ARGV[1]))
	{
		$num = (int)$ARGV[1];
	}
	subFib($num);
}

main();
?>
