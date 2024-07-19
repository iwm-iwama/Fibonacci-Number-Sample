#!/usr/bin/env php
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

	$BufMax = 4 * 1000;
	$Buf = [$BufMax];
	$BufIndex = 0;

	while($num > $cnt)
	{
		$fib2 = gmp_add($fib1, $fib0);
		$fib0 = $fib1;
		$fib1 = $fib2;
		++$cnt;

		$Buf[$BufIndex + 0] = $cnt;
		$Buf[$BufIndex + 1] = "\t";
		$Buf[$BufIndex + 2] = gmp_strval($fib1);
		$Buf[$BufIndex + 3] = PHP_EOL;
		$BufIndex += 4;

		if($BufIndex >= $BufMax)
		{
			echo implode("", $Buf);
			$BufIndex = 0;
		}
	}

	echo implode("", array_slice($Buf, 0, $BufIndex));
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
