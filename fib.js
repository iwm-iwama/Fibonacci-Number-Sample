#!/usr/bin/node
//---------------------------------------------------------------------
// BigNum
// $ node fib.js [NUM]
//---------------------------------------------------------------------
function subFib(
	num
)
{
	if(num < 0)
	{
		return;
	}

	console.log("0\t0");
	if(num < 1)
	{
		return;
	}

	console.log("1\t1");
	if(num < 2)
	{
		return;
	}

	let fib0 = BigInt(0);
	let fib1 = BigInt(1);
	let fib2 = BigInt(0);
	let cnt = 1;

	let $Buf = "";

	while(num > cnt)
	{
		fib2 = fib1 + fib0;
		fib0 = fib1;
		fib1 = fib2;
		++cnt;

		$Buf += cnt;
		$Buf += "\t";
		$Buf += fib1;
		$Buf += "\n";
	}

	process.stdout.write($Buf);
}

function main()
{
	let num = 0;
	const ARGS = process.argv.slice(2);
	if(! isNaN(ARGS[0]))
	{
		num = parseInt(ARGS[0], 10);
	}
	subFib(num);
}

main();
