# Notes on Bit Picking

## XOR
Only set a bit to 1 if one or the other is set to 1 and the other is 0:

```
    int i = 0;
    int j = 1;
    
    i ^j = 1;
    
    int i = 1;
    int j = 1;
    
    i ^ j = 0; 
```

> **_IMPORTANT_**

* Shifting by a negative number or a number greater than bit width is undefined!
* All vacant bits are filled in by 0 no matter if shifting left or right.
* Left shifting by 0 always results in 1:

```
1 << 0 = 1 because x^1 == 1
```

AND (&) allows the checking a bit's state (on or off).

** Bit Position is zero-based **


## Left Shift

```
n == bit_position_to_set (zero based in a bit array)
```

Left shift effectively multliplies by 2.

a << n is the same as mathematically: a * (2^n)

Where:
 * a: The number whose bits to shift.
 * n: The number of places to shift (e.g. 1 is shift 1 place, 2 is shift two places).
     * In code this is the index into the bit array of a number.

This example can see that multiplying by 2 not only gives 10 but also shifts the bits by one to the left:

```
0 in binary: (0000) : 0 << 0 = 0 (0000) of 0 * (2^0) = 0  // Shift 0 by 0 places.

1 in binary: (0001) : 1 << 0 = 1 (0001) or 1 * (2^0) = 1  // Shift 1 by 0 places

1 in binary: (0001) : 1 << 1 = 2 (0010) or 1 * (2^1) = 2  // Shift 1 by 1 place

1 in binary: (0001) : 1 << 2 = 4 (0100) or 1 * (2^2) = 4  // Shift 1 by 2 places

5 in binary: (0101) : 5 << 1 = 10 (1010)  or 5 * (2^1)  // Shift bits in 5 one place:

5 in binary: (0101) : 5 << 3 = 40 (101000) or 5 * (2^3) // Shift bits in 5 three places
```

### Left Shift Usages

#### Get a bit (check if a bit is set):
* Check if the bit in bit_position is set in num and if zero, bit is not set.  If true, bit is set.

```
bool is_set = (num & (1 << bit_position) != 0);

true = (1 & (1 << 0)) != 0  // num = 0001  bit_position = 0

true = (2 & (1 << 1)) != 0  // num == 0010 bit_position = 1

```

#### Set a bit
** (Packing data into a single integer) **:
* Updates the bit in bit_position of num and returned the updated bit value (0 or 1).
* Can pack individual items by shifting a bit number into the appropriate position.

```
int updated_bit_value = num | (1 << bit_position);

int result = num | (1 << pos);
int result = 1 | (1 << 3);  // Set the thrid bit from the right to 1 in the number 1.
```

Where:
 * result: The result containing the bit set.
 * num: Usually 1 but the value of the bit to set.
 * pos: The position of the bit in num to set.

<b>Basically, use the value of 1 and using the shift operator, shift the binary representation of 1 to n
    places where n+1 is the place of the bit we want to shift.  Then using OR, turn the number
    s (n+1)th bit to 1.
 </b>

#### Invert bits
Use tilde operator, will invert all bits.

```
mask = ~num_to_mask

inverted of 0000 (0) is 1111
inverted of 0001 (1) is 1110
inverted of 0010 (2) is 1101
inverted of 0011 (3) is 1100
inverted of 0100 (4) is 1011
```

#### Bit Masking
* A mask defines which bits you want to keep, and which bits you want to clear.
* Allows multiple values to be set in the same, single number like an int.
* Bit Masking is setting a bit into a specific location.

```
To create a mask, shift to a position and invert:

* bit_pos_to_clear is zero-based) *

mask = ~(1 << bit_pos_to_clear);
```

```
result = value << positions:
    r = 1 << 3 Shifts the bits in 1 by 3 positions.
    1 << 3 = 1000  Creates a mask with the 4th bit set.
```

```
Given the following bits, we want to clear all upper 4 bits but keep all lower 4 bits:

Applying the mask:

result = mask & value

Mask:   00001111
Value:  01010101
Result: 00000101
```

##### Common Operations
* Setting a bit using OR (|)
* Checking if a bit is set or not using AND (&)
* Clearing a bit using AND with negated maks (See below on clearing a bit but: val = num & ( ~(1 << bit_pos) ) ).
* Used to create a Bit Mask.  Bit Masks are used to isolate, set, or clear specific bits in a binary number.

```
mask of 0 = ~0 (0000) == 1111
mask of 1 = ~(1 << 0) == 0111
```

#### Clear a bit ** (use Masking for this): **
* Create a complement (~) of the bit_position then AND it.  This will result in
    * If the bit was set, it is unset.
    * If the bit was unset, it will be left alone.
* Returns the updated bit value.

```
int mask = ~(1 << bit_position)
int updated_bit_value = num & mask;

// Notice how the bit position 0 is cleared to value = 0000 even though it was never set in num.
bit position to clear: 0            0000
Shifted: (1 << bit_pos_to_clear)    0001
mask: (~(1 << bit_pos_to_clear))    1110
num: (1)                            0001
value: (num & mask)                 0000

// Notice how the bit position 1 is zero and the value is still 0001 since the 0th bit is not touched.
bit position to clear: 1            0001
Shifted: (1 << bit_pos_to_clear)    0010
mask: (~(1 << bit_pos_to_clear))    1101
num: (1)                            0001
value: (num & mask)                 0001

// Notice how bit position is 1 and num is 0010 so it clears the bit in the second place (bit pos is 0-based).
bit position to clear: 1            0001
Shifted: (1 << bit_pos_to_clear)    0010
mask: (~(1 << bit_pos_to_clear))    1101
num: (2)                            0010
value: (num & mask)                 0000

// Notice how the bit position is 2 and num is 2.  Since bit pos is 0-based, it does not touch num's 2nd bit, hence 0010.
bit position to clear: 2            0010
Shifted: (1 << bit_pos_to_clear)    0100
mask: (~(1 << bit_pos_to_clear))    1011
num: (2)                            0010
value: (num & mask)                 0010

// Notice how want to clear bit at index 2 and 4 has bit set at index 2 so result is 0000 as it cleared index 2 bit.
bit position to clear: 2            0010
Shifted: (1 << bit_pos_to_clear)    0100
mask: (~(1 << bit_pos_to_clear))    1011
num: (4)                            0100
value: (num & mask)                 0000
```




## Right Shift

Right shift effectively divides by 2.

a >> n is the same mathematically as a / (2^n)

** Used commonly for fast division **
** Left bits are filled in with zeros **
** Can result in loss of digits as bits on the right are discarded **

* When applied to an unsigned or non-negative number, all vacent bits on the left are filled with zeros.
* When applied to a negateive number, ???  Se below.

* For unsigned ints all right bits are set to zero, a.k.a "Logical Right Shift"
* For signed ints the signed bit (left-most) is preserved a.k.a "Arithmetic Right Shift"

Example:

```
20 in binary: (10100) 20 >> 2 = 5 (1010) or 20 / (2^2)

number to shift << number of places to shift

num_places_to_shift:    0
num_to_shift: (1)       0001
shifted (1 >> 0):       0001

num_places_to_shift:    1
num_to_shift: (1)       0001
shifted (1 >> 1):       0000

num_places_to_shift:    1
num_to_shift: (3)       0011
shifted (3 >> 1):       0001
```

### 2's Compliment

** Subtracting a number is the same as adding a number's 2's compliment!! **
** When add a 2's compliment to the original number, the answer is zero **

```
int num1 = 5;
int num2 = 2;
int num_twos = ~(num2) + 1; // Invert all bits and add 1.
int answer = num1 + num_twos;

2's compliment 5 + -2 = 3
2's of 2 added to itself is 0
```

Better example:

```
Start with +6:    0110
Invert the bits:  1001
Add 1: 1010 Thus, 1010 represents −6 in two's complement.

```

Representing signed ints (+, 0, -) in binary

2's compliment has only one representation of a negative numbere whereas 1's compliment has + and 1 zero.

```
Eith a 8-bit int:

Notiation        Min  Max
Unsigned           0  255
1's compliment  -127 +127
2's compliment  -128 +127

```
* First, invert all bits of a number to convert (~)
* Add 1 to the result

```
result = 1 + ~num_to_convert

num to convert:   0 (0000)
inverted:        -1 (1111)
result:           0 (0000) (adding one to above really results in "1 0000" but since the bit width is 4, it's just 0000).

num to convert:   1 (0001)
inverted:        -2 (1110)
result:          -1 (1111)

num to convert:  -1 (1111)
inverted:         0 (0000)
result:           1 (0001)
```

