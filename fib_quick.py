#!/usr/bin/env python3
#coding	utf-8
#-------------------------------------------------------------------------------
# BigNum
# $ python3 fib_quick.py [NUM]
#-------------------------------------------------------------------------------
import sys

Args = sys.argv

class Fib:
	def mul(mat1, mat2):
		rtn = [[0, 0], [0, 0]]
		for _i1 in range(2):
			for _i2 in range(2):
				for _i3 in range(2):
					rtn[_i1][_i2] += mat1[_i1][_i3] * mat2[_i3][_i2]
		return rtn

	def pow(mat1, num):
		if num < 2:
			return mat1

		if (num % 2) == 0:
			mat2 = Fib.pow(mat1, int(num / 2))
			return Fib.mul(mat2, mat2)
		else:
			i1 = num - 1
			mat2 = Fib.pow(mat1, i1)
			return Fib.mul(mat1, mat2)

	def output(num):
		match num:
			case int(x) if num < 0:
				return
			case 0:
				print("0\t0")
				return
			case 1:
				print("1\t1")
				return
			case 2:
				print("2\t1")
				return

		mat1 = [[1, 1], [1, 0]]
		mat2 = Fib.pow(mat1, num)

		# 4300文字縛り解除
		sys.set_int_max_str_digits(0)
		print(str(num), "\t", str(mat2[0][1]), end="\n", sep="")

def main():
	num = 0
	if len(Args) > 1:
		num = int(Args[1])
	Fib.output(num)

main()
