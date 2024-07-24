#!/usr/bin/env ruby
#coding:utf-8
#-------------------------------------------------------------------------------
# BigNum
# $ ruby fib_quick.rb [NUM]
#-------------------------------------------------------------------------------
#【参考】require "matrix" を使用した例
#-------------------------------------------------------------------------------
=begin
	require "matrix"
	def subFib(
		num = 0
	)
		print(num, "\t", ((Matrix[[1, 1], [1, 0]] ** num)[0, 1]), "\n")
	end
	subFib(num)
=end
#-------------------------------------------------------------------------------

class Fibonacci
	def initialize()
	end

	def mul(mat1, mat2)
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

	def pow(mat1, num)
		if num < 2
			return mat1
		end

		if (num % 2) == 0
			mat2 = pow(mat1, (num / 2).to_i)
			return mul(mat2, mat2)
		else
			i1 = num - 1
			mat2 = pow(mat1, i1)
			return mul(mat1, mat2)
		end
	end

	def output(num)
		case num
			when .. -1
				return
			when 0
				puts "0\t0"
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

		print(num, "\t", mat2[0][1], "\n")
	end
end

Fib = Fibonacci.new()

def main()
	num = 0
	if ARGV.length > 0
		num = ARGV[0].to_i
	end

	# Normal: [num]
	Fib.output(num)

	# Debug: [0..num]
=begin
		num += 1
		num.times do |_i1|
			Fib.output(_i1)
		end
=end

end

main()
