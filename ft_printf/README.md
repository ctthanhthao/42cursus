## ft_printf is a function that mimics the original printf
### Requirements:
- Implement conversions: cspdiuxX%
- Manage any combination of the following flags " - 0 ." and the field minimum width under conversions
- Manage all following flags "# + (space)".

## Functions Summary table

| Conversion | - (Left Align) | 0 (Zero Padding) | . (Precision) | # (Alternate Form) | + (Sign) | (space) (Space) | 
| --- | --- | --- | --- | --- | --- | --- | 
| c (Character) | Yes |  |  |  |  |  | 
| s (String) | Yes |  | Yes |  |  |  | 
| d (Decimal) | Yes | Yes | Yes |  | Yes | Yes | 
| i (Integer) | Yes | Yes | Yes |  | Yes | Yes | 
| u (Unsigned) | Yes | Yes | Yes |  |  |  | 
| x (Hexadecimal) | Yes | Yes | Yes | Yes |  |  | 
| X (Hexadecimal) | Yes | Yes | Yes | Yes |  |  | 
| % (Percent) |  |  |  |  |  |  | 

Evaluation sheet : https://www.42evals.com/sheets/66b9c8b4e6188711fc26b877 
