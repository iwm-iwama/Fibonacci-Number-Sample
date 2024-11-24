#!/usr/bin/env ruby
#coding:utf-8
#-------------------------------------------------------------------------------
# BigNum
# $ ruby fib_quick2.rb [NUM]
#-------------------------------------------------------------------------------
# 以下のサイトを参考にした（ほぼ引用）
#   フィボナッチ数を計算する多分最速の方法
#   https://qiita.com/mp2147483647/items/4b450a$f21894c2f9e712
#-------------------------------------------------------------------------------

def RtnFibIntr(
	num
)
	if num.zero?
		return [1, 2] 
	end

	if num.even?
		num_half = num / 2
		f1, l1 = RtnFibIntr(num_half)
		pow_m1 = (-1) ** num_half
		l2 = (l1 * l1) - (2 * pow_m1)
		f2 = (f1 * l1) - pow_m1
	elsif (num % 8) == 7
		f1, l1 = RtnFibIntr(num + 1)
		f2 = (2 * f1) - l1
		l2 = (3 * f2) - f1
	else
		f1, l1 = RtnFibIntr(num - 1)
		f2 = (3 * f1) - l1
		l2 = (2 * f2) - f1
	end

	return [f2, l2]
end

def SubFib(
	num
)
	if num <= 0
		return
	end

	print(
		num,
		"\t",
		RtnFibIntr(num - 1)[0],
		"\n"
	)
end

def main()
	num = 0
	if ARGV.length > 0
		num = ARGV[0].to_i
	end
	SubFib(num)
end

main()
