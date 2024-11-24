#!/usr/bin/env ruby
#coding:utf-8
#-------------------------------------------------------------------------------
# BigNum
# $ ruby fib_quick.rb [NUM]
#-------------------------------------------------------------------------------
#【参考】require "matrix" を使用した例
#-------------------------------------------------------------------------------
=begin

def subFib(
	num
)
	print(
		num,
		"\t",
		(Matrix[[1, 1], [1, 0]] ** num)[0, 1],
		"\n"
	)
end

def main()
	num = 0
	if ARGV.length > 0
		num = ARGV[0].to_i
	end
	subFib(num)
end

main()

=end

class Fibonacci
	def initialize()
	end

	def mul(
		mat1,
		mat2
	)
		rtn = [[0, 0], [0, 0]]
		2.times do |_i1|
			2.times do |_i2|
				2.times do |_i3|
					rtn[_i1][_i2] += mat1[_i1][_i3] * mat2[_i3][_i2]
				end
			end
		end
		return rtn
	end

	def pow(
		mat1,
		num
	)
		if num < 2
			return mat1
		end

		if num.even?
			mat2 = pow(mat1, (num / 2).to_i)
			return mul(mat2, mat2)
		else
			i1 = num - 1
			mat2 = pow(mat1, i1)
			return mul(mat1, mat2)
		end
	end

	def output(
		num
	)
		case num
			when .. 0
				return
			when 1
				puts "1\t1"
				return
			when 2
				puts "2\t1"
				return
		end

		mat1 = [[1, 1], [1, 0]]
		mat2 = pow(mat1, num)

		print(
			num,
			"\t",
			mat2[0][1],
			"\n"
		)
	end
end

Fib = Fibonacci.new()

def main()
	num = 0
	if ARGV.length > 0
		num = ARGV[0].to_i
	end
	Fib.output(num)
end

main()
