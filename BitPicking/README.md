# Notes on Bit Picking


> **_IMPORTANT_**

* Shifting by a negative number or a number greater than bit width is undefined!
* All vacant bits are filled in by 0 no matter if shifting left or right.
* Left shifting by 0 always results in 1:

```
1 << 0 = 1 because x^1 == 1
```

AND (&) allows the checking a bit's state (on or off).


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
* Bit Masking is setting a bit into a specific location.
* Allows multiple values to be set in the same, single number like an int.
* Used to create a Bit Mask.  Bit Masks are used to isolate, set, or clear specific bits in a binary number.

 * mask of 0 = ~0 (0000) == 1111
 * mask of 1 = ~(1 << 0) == 0111


#### Clear a bit ** (use Masking for this): **
* Create a complement (~) of the bit_position then AND it.  This will result in
    * If the bit was set, it is unset.
    * If the bit was unset, it will be left alone.
* Returns the updated bit value.

```
int mask = ~(1 << bit_position)
int updated_bit_value = num & mask;

bit position to clear: 0  (0000)
Shifted 0001 (1 << bit_pos_to_clear)
mask: 1110 (~(1 << bit_pos_to_clear))
num 0001 : (1) 
value 0000 (num & mask) 

bit position to clear: 1  (0001)
Shifted 0010 (1 << bit_pos_to_clear)
mask: 1101 (~(1 << bit_pos_to_clear))
num 0001 : (1)
value 0001 (num & mask) Note how the bit in pos 0 remains 1

bit position to clear: 1  (0001)
Shifted 0010 (1 << bit_pos_to_clear)
mask: 1101 (~(1 << bit_pos_to_clear))
num 0010 : (2) 
value 0000 (num & mask) Note how the bit in pos 1 is cleared
```




## Right Shift

Right shift effectively divides by 2.

a >> n is the same mathematically as a / (2^n)

(Same operands as left shift)

Example:

```
20 in binary: (10100) 20 >> 2 = 5 (1010) or 20 / (2^2)
```


 *
 * result = value << positions:
 *      r = 1 << 3 Shifts the bits in 1 by 3 positions.
 *      1 << 3 = 1000  Creates a mask with the 4th bit set.
