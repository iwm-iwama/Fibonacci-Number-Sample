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
	print("0\t0")
	if num < 1:
		return
	print("1\t1")
	if num < 2:
		return
	fib0 = 0
	fib1 = 1
	fib2 = 0
	cnt = 1
	buf = []
	while num > cnt:
		fib2 = fib1 + fib0
		fib0 = fib1
		fib1 = fib2
		cnt += 1
		buf.append(str(cnt))
		buf.append("\t")
		buf.append(str(fib1))
		buf.append("\n")
	print("".join(buf), end="", sep="")

def main():
	num = 0
	if len(Args[1]) > 0:
		num = int(Args[1])
	subFib(num)

main()
