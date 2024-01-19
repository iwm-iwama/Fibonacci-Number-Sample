#!ruby
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

	$BufMax = 4 * 4096
	$Buf = [$BufMax]
	$BufIndex = 0

	while num > cnt
		fib2 = fib1 + fib0
		fib0 = fib1
		fib1 = fib2
		cnt += 1

		$Buf[$BufIndex + 0] = cnt.to_s
		$Buf[$BufIndex + 1] = "\t"
		$Buf[$BufIndex + 2] = fib1.to_s
		$Buf[$BufIndex + 3] = "\n"
		$BufIndex += 4

		if($BufIndex >= $BufMax)
			print $Buf.join("")
			$BufIndex = 0
		end
	end

	print $Buf.slice(0..($BufIndex - 1)).join("")
end

def main()
	num = 0
	if ARGV.length > 0
		num = ARGV[0].to_i
	end
	subFib(num)
end

main()
