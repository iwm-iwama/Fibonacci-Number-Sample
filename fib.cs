//------------------------------------------------------------------------------
// BigNum
// $ csc -o+ -w:4 -r:System.Numerics.dll -out:fib.cs.exe fib.cs
// $ fib.cs.exe [NUM]
//------------------------------------------------------------------------------
using System;
using System.IO;
using System.Numerics;
using System.Text;

namespace Program
{
	internal class Sub
	{
		private static void SubFib(int iNum = 0)
		{
			if (iNum < 0)
			{
				return;
			}

			Console.WriteLine("0\t0");
			if (iNum < 1)
			{
				return;
			}

			Console.WriteLine("1\t1");
			if (iNum < 2)
			{
				return;
			}

			BigInteger fib0 = 0;
			BigInteger fib1 = 1;
			BigInteger fib2 = 0;
			int iCnt = 1;

			StreamWriter SW = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
			Console.SetOut(SW);
			StringBuilder Buf = new StringBuilder(10_000_000);

			while (iNum > iCnt)
			{
				fib2 = fib1 + fib0;
				fib0 = fib1;
				fib1 = fib2;
				++iCnt;

				_ = Buf.Append(iCnt.ToString());
				_ = Buf.Append("\t");
				_ = Buf.Append(fib1.ToString());
				_ = Buf.Append(Environment.NewLine);
			}

			Console.Write(Buf.ToString());
			Console.Out.Flush();
		}

		private static void Main(string[] ARGS)
		{
			int iNum = 0;
			if (ARGS.Length > 0)
			{
				int.TryParse(ARGS[0], out iNum);
			}
			SubFib(iNum);
		}
	}
}
