#!/usr/bin/python3
#---------------------------------------------------------------------
# BigNum
# $ python fib.py [NUM]
#---------------------------------------------------------------------
import sys

Args = sys.argv

def subFib(
	num = 0
):
	if num < 0:
		return

	print("0\t0\n", end="", sep="")
	if num < 1:
		return

	print("1\t1\n", end="", sep="")
	if num < 2:
		return

	fib0 = 0
	fib1 = 1
	fib2 = 0
	cnt = 1

	BUF_MAX = 4 * 1000
	buf = [""] * BUF_MAX
	bufIndex = 0

	while num > cnt:
		fib2 = fib1 + fib0
		fib0 = fib1
		fib1 = fib2
		cnt += 1

		buf[bufIndex + 0] = str(cnt)
		buf[bufIndex + 1] = "\t"
		buf[bufIndex + 2] = str(fib1)
		buf[bufIndex + 3] = "\n"
		bufIndex += 4

		if(bufIndex >= BUF_MAX):
			print("".join(buf), end="", sep="")
			bufIndex = 0

	print("".join(buf[0:bufIndex]), end="", sep="")

def main():
	num = 0
	if len(Args[1]) > 0:
		num = int(Args[1])
	subFib(num)

main()
