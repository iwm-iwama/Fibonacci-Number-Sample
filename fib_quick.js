#!/usr/bin/env node
//---------------------------------------------------------------------
// BigNum
// $ node fib_quick.js [NUM]
//---------------------------------------------------------------------
const OS = require("os");
NL = OS.EOL;

class Fibonacci
{
	constructor()
	{
	}

	mul(mat1, mat2)
	{
		let rtn = [[BigInt(0), BigInt(0)], [BigInt(0), BigInt(0)]];
		for(let _i1 = 0; _i1 < 2; _i1++)
		{
			for(let _i2 = 0; _i2 < 2; _i2++)
			{
				for(let _i3 = 0; _i3 < 2; _i3++)
				{
					rtn[_i1][_i2] += mat1[_i1][_i3] * mat2[_i3][_i2];
				}
			}
		}
		return rtn;
	}

	pow(mat1, num)
	{
		if(num < 2)
		{
			return mat1;
		}

		if((num % 2) == 0)
		{
			let mat2 = this.pow(mat1, ((num / 2) ^ 0));
			return this.mul(mat2, mat2);
		}
		else
		{
			let i1 = num - 1;
			let mat2 = this.pow(mat1, i1);
			return this.mul(mat1, mat2);
		}
	}

	output(num)
	{
		if(num < 0)
		{
			return;
		}

		switch(num)
		{
			case 0:
				process.stdout.write("0\t0" + NL);
				return;
			case 1:
				process.stdout.write("1\t1" + NL);
				return;
			case 2:
				process.stdout.write("2\t1" + NL);
				return;
		}

		let mat1 = [[BigInt(1), BigInt(1)], [BigInt(1), BigInt(0)]];
		let mat2 = this.pow(mat1, num);

		process.stdout.write(num + "\t" + mat2[0][1] + NL);
	}
}

function main()
{
	let num = 0;
	const ARGS = process.argv.slice(2);
	if(! isNaN(ARGS[0]))
	{
		num = parseInt(ARGS[0], 10);
	}
	const Fib = new Fibonacci();
	Fib.output(num);
}

main();
