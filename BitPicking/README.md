# Notes on Bit Picking


> **_IMPORTANT_**

* Shifting by a negative number or a number greater than bit width is undefined!
* All vacant bits are filled in by 0 no matter if shifting left or right.
* Left shifting by 0 always results in 1:

```
1 << 0 = 1 because x^1 == 1
```

### Left Shift

```
n == bit_position_to_set
```

Left shift effectively multliplies by 2.

a << n is the same as mathematically: a * (2^n)

Where:
 * a: The number whose bits to shift.
 * n: The number of places to shift (e.g. 1 is shift 1 place, 2 is shift two places).

This example can see that multiplying by 2 not only gives 10 but also shifts the bits by one to the left:

```
5 in binary: (0101) : 5 << 1 = 10 (1010)  or 5 * (2^1)
```

Another example, shift bits in 5 three places:

```
5 in binary: (0101) : 5 << 3 = 40 (101000) or 5 * (2^3)
```

##### Usages

Get a bit:
* Check if the bit in bit_position is set in num and if zero, bit is not set.  If true, bit is set.

```
bool is_set = (num & (1 << bit_position) != 0);
```

Set a bit:
* Updates the bit in bit_position of num and returned the updated bit value (0 or 1).

```
int updated_bit_value = num | (1 << bit_position);
```

Clear a bit:
* Create a complement (~) of the bit_position then AND it.  This will result in
    * If the bit was set, it is unset.
    * If the bit was unset, it will be left alone.
* Returns the updated bit value.

```
int mask = ~(1 << bit_position)

int updated_bit_value = num & mask;
```

Bit Masking



Bit Masking and Manipulation
* Bit Masking is setting a bit into a specific location.
* Used to create a Bit Mask.  Bit Masks are used to isolate, set, or clear specific bits in a binary number.

Set a bit

```
int mask = 1 << 3;          // Creates a mask with the fourth bit (3+1) set (1000)
int value = 5;              // 5 in binary is 0101
int result = value & mask;  // Masks the larger value, isolating the fourth bit (1101).
```

Clear a bit

```

```



Packing data into a single integer
* Can pack individual items by shifting a bit number into the appropriate position.

Use this to set a bit via the | operator:

```
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

### Right Shift

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
