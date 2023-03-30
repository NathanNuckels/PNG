The equations are written in binary.

x^3 + x + 1 equation
1(x^3) + 0(x^2) + 1(x) + 1(1)
1        0        1      1

and so: 1011. 

The powers in a CRC-32 are:

0x104C11DB7 (Sometimes the leading 1 is missing)
1 0000010 01100000 10001110 110110111
The numbers are:
32,26,23,22,16,12,11,10,8,7,5,4,2,1,0
(x^1 = x and x^0 = 1 btw)


EXAMPLE: Solve a 3 bit crc with 

Message: 11010011101100
Equation: x^3 + x + 1
Equation: 1x^3 + 0x^2 + 1x^1 + 1x^0
Equation: 1      0      1      1

11010011101100 000 <- Input (right shifted by length of CRC)
1011               <- Devisor
-----XOR----------
01100011101100 000
 1011
-----XOR---------- XOR is the same as a bit-wise !=
00111011101100 000
  1011
00010111101100 000
   1011
00000001101100 000
       1011        <- The devisor jumps to the next 1, not one pit per iteration.
00000000110100 000
        1011
00000000011000 000
         1011
00000000001110 000
          1011
00000000000101 000
           101 1
00000000000000 100
               100 <- Final answer


Here is the CRC algorithm in PYTHON
(From wikapedia, Removed he 'filter' feature for simplicity)

def crc_remainder(inbits,poly):
	#all inputs are strings.
	poly=poly.lstrip('0')
	inlength=len(inbits)
	inbits=list(inbits)
	while '1' in inbits[:inlength]:
		cur_shift = inbits.index('1')
		for i in range(len(poly)):
			inbits[cur_shift+i]=str(int(poly[i]!=inbits[cur_shift+i]))
	return ''.join(inbits)[inlength:]
