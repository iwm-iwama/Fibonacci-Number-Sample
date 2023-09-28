#!/usr/bin/ruby
#---------------------------------------------------------------------
# BigNum
# $ ruby fib.rb [NUM]
#---------------------------------------------------------------------
def subFib(
	num = 0
)
	if num < 0
		return
	end

	puts "0\t0"
	if num < 1
		return
	end

	puts "1\t1"
	if num < 2
		return
	end

	fib0 = 0
	fib1 = 1
	fib2 = 0
	cnt = 1

	$Buf = ""

	while num > cnt
		fib2 = fib1 + fib0
		fib0 = fib1
		fib1 = fib2
		cnt += 1

		$Buf << cnt.to_s
		$Buf << "\t"
		$Buf << fib1.to_s
		$Buf << "\n"
	end

	print $Buf
end

def main()
	num = 0
	if ARGV.length > 0
		num = ARGV[0].to_i
	end
	subFib(num)
end

main()
