//------------------------------------------------------------------------------
// BigNum
// $ csc.exe -o+ -w:4 -r:System.Numerics.dll -out:fib.cs.exe fib.cs
// $ fib.cs.exe [NUM]
//------------------------------------------------------------------------------
using System;
using System.Numerics;
using System.Text;

namespace Program
{
	internal class Sub
	{
		static void SubFib(
			int num = 0
		)
		{
			if(num < 0)
			{
				return;
			}

			Console.WriteLine("0\t0");
			if(num < 1)
			{
				return;
			}

			Console.WriteLine("1\t1");
			if(num < 2)
			{
				return;
			}

			BigInteger fib0 = 0;
			BigInteger fib1 = 1;
			int cnt = 1;

			StringBuilder SB = new StringBuilder();

			while(num > cnt)
			{
				BigInteger fib2 = fib1 + fib0;
				fib0 = fib1;
				fib1 = fib2;
				++cnt;

				SB.Append(cnt.ToString());
				SB.Append("\t");
				SB.Append(fib1.ToString());
				SB.Append(Environment.NewLine);
			}

			Console.Write(SB);
		}

		static void Main(string[] ARGS)
		{
			int num = 0;
			if(ARGS.Length > 0)
			{
				int.TryParse(ARGS[0], out num);
			}
			SubFib(num);
		}
	}
}
