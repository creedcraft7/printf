int main()
// {
//     // Test Case 1: Basic Specifiers
//     char arr1[] = "Char test 1: %c\n";
//     printf(arr1, 'c');
//     ft_printf(arr1, 'c');

//     char arr2[] = "String test 2: %s\n";
//     printf(arr2, "ORION");
//     ft_printf(arr2, "ORION");

//     char arr3[] = "Decimal test 3: %d\n";
//     printf(arr3, -42);
//     ft_printf(arr3, -42);

//     char arr4[] = "Integer test 4: %i\n";
//     printf(arr4, -42);
//     ft_printf(arr4, -42);

//     char arr5[] = "Unsigned test 5: %u\n";
//     printf(arr5, 42);
//     ft_printf(arr5, 42);

//     char arr6[] = "Hex test (lowercase) 6: %x\n";
//     printf(arr6, 1337);
//     ft_printf(arr6, 1337);

//     char arr7[] = "Hex test (uppercase) 7: %X\n";
//     printf(arr7, 42);
//     ft_printf(arr7, 42);

//     char arr8[] = "Pointer test 8: %p\n";
//     printf(arr8, &arr8);
//     ft_printf(arr8, &arr8);

//     // Test Case 2: Flags
//     char arr9[] = "Plus flag test 9: %+d\n";
//     printf(arr9, 42);
//     ft_printf(arr9, 42);

//     char arr10[] = "Minus flag test 10: %-10d\n";
//     printf(arr10, 42);
//     ft_printf(arr10, 42);

//     char arr11[] = "Negative number with width and precision 11: %010.5d\n";
//     printf(arr11, -42);
//     ft_printf(arr11, -42);

//     char arr12[] = "Zero padding test 12: %010d\n";
//     printf(arr12, 42);
//     ft_printf(arr12, 42);

//     // Test Case 3: Width
//     char arr13[] = "Width test 13: %10d\n";
//     printf(arr13, 42);
//     ft_printf(arr13, 42);

//     // Test Case 4: Precision
//     char arr14[] = "Precision test (string) 14: %.5s\n";
//     printf(arr14, "ORION");
//     ft_printf(arr14, "ORION");

//     char arr15[] = "Precision test (integer) 15: %.5d\n";
//     printf(arr15, 42);
//     ft_printf(arr15, 42);

//     char arr16[] = "Precision test (unsigned) 16: %.5u\n";
//     printf(arr16, 42);
//     ft_printf(arr16, 42);

//     // Test Case 5: Width and Precision Combined
//     char arr17[] = "Width and precision test (string) 17: %10.5s\n";
//     printf(arr17, "ORION");
//     ft_printf(arr17, "ORION");

//     char arr18[] = "Width and precision test (integer) 18: %10.5d\n";
//     printf(arr18, 42);
//     ft_printf(arr18, 42);

//     // Test Case 6: Edge Cases
//     char arr19[] = "Zero test (integer) 19: %d\n";
//     printf(arr19, 0);
//     ft_printf(arr19, 0);

//     char arr20[] = "Negative test (integer) 20: %d\n";												
//     printf(arr20, -42);
//     ft_printf(arr20, -42);

//     char arr21[] = "Large unsigned test 21: %u\n";
//     printf(arr21, 4294967296);
//     ft_printf(arr21, 4294967296);

//     char arr22[] = "Negative number with width and precision 22: %010.5d\n";
//     printf(arr22, -42);
//     ft_printf(arr22, -42);	

//     char arr23[] = "NULL pointer test 23: %p\n";
//     printf(arr23, NULL);
//     ft_printf(arr23, NULL);

//     // Test Case 7: Unsupported/Invalid Specifiers
//     char arr24[] = "Invalid specifier test 24: %q hhhh\n";
//     printf(arr24);
//     ft_printf(arr24);

//     // Test Case 8: Combining Flags and Specifiers
//     char arr25[] = "Combined flags test 25: %+010d\n";
//     printf(arr25, 42);
//     ft_printf(arr25, 42);

//     char arr26[] = "Combined flags test (precision) 26: %-010.5dhhhh\n";
//     printf(arr26, -42);
//     ft_printf(arr26, -42);

//     // Test Case 9: Multiple Specifiers in One String
//     char arr27[] = "Multiple specifiers test 27: %d %s %u %x\n";
//     printf(arr27, -42, "ORION", 42, 42);
//     ft_printf(arr27, -42, "ORION", 42, 42);

//     // Test Case 10: Empty Strings
//     char arr28[] = "Empty string test 28: %s\n";
//     printf(arr28, "");
//     ft_printf(arr28, "");

//     // Test Case 11: Special Character with %c
//     char arr29[] = "Special char test 29: %c\n";
//     printf(arr29, '\n');
//     ft_printf(arr29, '\n');

//     // Test Case 12: Edge Case for Zero Padding and Precision
//     char arr30[] = "Zero padding with precision 30: %05d\n";
//     printf(arr30, 42);
//     ft_printf(arr30, 42);

//     // Edge Case 1: Very Large Integer with Width and Zero Padding
//     char arr31[] = "Large number with width and zero padding 31: %020d\n";
//     printf(arr31, 9876543210);
//     ft_printf(arr31, 9876543210);

//     // Edge Case 2: Negative Number with Width and Precision
//     char arr32[] = "Negative number with width and precision 32: %010.5d\n";
//     printf(arr32, -42);
//     ft_printf(arr32, -42);

//     // Edge Case 3: Pointer Address with Width
//     int a = 42;
//     char arr33[] = "Pointer address with width 33: %20p\n";
//     printf(arr33, &a);
//     ft_printf(arr33, &a);

//     // Edge Case 4: Hexadecimal (lowercase) with Width, Zero Padding, and Precision
//     char arr34[] = "Hexadecimal with width, zero padding, and precision 34: %#010.6x\n";
//     printf(arr34, -42);
//     ft_printf(arr34, -42);

//     // Edge Case 5: Hexadecimal (uppercase) with Zero Padding, Width, and Precision
//     char arr35[] = "Hexadecimal (uppercase) with width, zero padding, and precision 35: %#010.6X\n";
//     printf(arr35, 42);
//     ft_printf(arr35, 42);

//     // Edge Case 6: Empty String with Width and Left Alignment
//     char arr36[] = "Empty string with width and left alignment 36: %-20s\n";
//     printf(arr36, "");
//     ft_printf(arr36, "");

//     // Edge Case 7: Empty String with Width and Right Alignment
//     char arr37[] = "Empty string with width and right alignment 37: %20s\n";
//     printf(arr37, "");
//     ft_printf(arr37, "");

//     // Edge Case 9: Unsigned Integer with Width and Precision
//     char arr38[] = "Unsigned integer with width and precision 38: %10.5u\n";
//     printf(arr38, 42);
//     ft_printf(arr38, 42);

//     // Edge Case 10: Negative Value with Width and Flags
//     char arr39[] = "Negative value with width and flags 39: %+10d\n";
//     printf(arr39, -42);
//     ft_printf(arr39, -42);

//     // Complex Case 1: Multiple Specifiers with Different Flags and Width
//     char arr40[] = "Multiple specifiers with different flags and width 40: %-10s %+10d %#10x\n";
//     printf(arr40, "Test", -42, 42);
//     ft_printf(arr40, "Test", -42, 42);

//     // Complex Case 2: Multiple Specifiers, Mixed Width, Precision, and Padding
//     char arr41[] = "Multiple specifiers with mixed width, precision, and padding 41: %10.5d %-10.3s %#10x\n";
//     printf(arr41, 42, "hello", 42);
//     ft_printf(arr41, 42, "hello", 42);

//     // Complex Case 3: Hexadecimal with Zero Padding and Precision in Uppercase
//     char arr42[] = "Hexadecimal with zero padding and precision (uppercase) 42: %#010.5X\n";
//     printf(arr42, 42);
//     ft_printf(arr42, 42);

//     return 0;
// }