#!node
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

	const OS = require("os");
	NL = OS.EOL;

	process.stdout.write("0\t0" + NL);
	if(num < 1)
	{
		return;
	}

	process.stdout.write("1\t1" + NL);
	if(num < 2)
	{
		return;
	}

	let fib0 = BigInt(0);
	let fib1 = BigInt(1);
	let fib2 = BigInt(0);
	let cnt = 1;

	const BufMax = 4 * 1000;
	let Buf = [BufMax];
	let BufIndex = 0;

	while(num > cnt)
	{
		fib2 = fib1 + fib0;
		fib0 = fib1;
		fib1 = fib2;
		++cnt;

		Buf[BufIndex + 0] = cnt;
		Buf[BufIndex + 1] = "\t";
		Buf[BufIndex + 2] = fib1;
		Buf[BufIndex + 3] = NL;
		BufIndex += 4;

		if(BufIndex >= BufMax)
		{
			process.stdout.write(Buf.join(""));
			BufIndex = 0;
		}
	}

	process.stdout.write(Buf.slice(0, BufIndex).join(""));
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
