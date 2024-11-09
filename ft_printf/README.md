ft_printf is a function that mimics the original printf
Requirements:
- Implement conversions: cspdiuxX%
- Manage any combination of the following flags " - 0 ." and the field minimum width under conversions
- Manage all following flags "# + (space)".

Functions Summary table
------------------------------------------------------------
|       |   -   |   0   |   .   |   #   |   +   |  (space) |
------------------------------------------------------------
|   c   |   Y   |       |       |       |       |          |
|   s   |   Y   |       |   Y   |       |       |          |
|   d   |   Y   |   Y   |   Y   |       |   Y   |    Y     |
|   i   |   Y   |   Y   |   Y   |       |   Y   |    Y     |
|   u   |   Y   |   Y   |   Y   |       |       |          |
|  x, X |   Y   |   Y   |   Y   |   Y   |       |          |
|   %   |       |       |       |       |       |          |
------------------------------------------------------------
Evaluation sheet : https://www.42evals.com/sheets/66b9c8b4e6188711fc26b877 
