# push_swap

`push_swap` is a sorting algorithm program built with the goal of sorting a stack of integers using the smallest possible number of operations. The program implements a sorting algorithm and works on two stacks, `a` and `b`, to arrange the integers in ascending order.

### Overview

The program is divided into two main parts:

- **push_swap**: This is the primary program responsible for sorting the stack using a series of allowed operations. The goal is to sort the stack with the fewest moves possible, satisfying the project’s requirements.

- **checker**: This auxiliary program validates if the sorting operation performed by `push_swap` is correct. It verifies whether the final result of the stack is sorted correctly (ascending order) or not.

### Features

- The sorting algorithm is designed to sort a stack of integers using a limited set of operations.
- It checks whether the stack is sorted correctly using the `checker` program.
- The number of moves performed by `push_swap` is minimal, satisfying the project’s requirements.
- The program uses a **singly linked list** to represent the stack instead of a circular linked list (as suggested in the original reference by a Turkish developer, [Ayogun](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)).
- The operations are limited to the following:

  - `sa` (swap a): Swap the first two elements at the top of stack `a`.
  - `sb` (swap b): Swap the first two elements at the top of stack `b`.
  - `ss` (swap both): Perform `sa` and `sb` simultaneously.
  - `pa` (push a): Take the top element of `b` and push it onto `a`.
  - `pb` (push b): Take the top element of `a` and push it onto `b`.
  - `ra` (rotate a): Shift up all elements of stack `a` by one.
  - `rb` (rotate b): Shift up all elements of stack `b` by one.
  - `rr` (rotate both): Perform `ra` and `rb` simultaneously.
  - `rra` (reverse rotate a): Shift down all elements of stack `a` by one.
  - `rrb` (reverse rotate b): Shift down all elements of stack `b` by one.
  - `rrr` (reverse rotate both): Perform `rra` and `rrb` simultaneously.

### Implementation

The idea of the `push_swap` program comes from the [article by Ayogun](https://medium.com/@ayogun/push-swap-c1f5d2d41e97), where the original implementation uses a **circular linked list** to perform stack operations. In my implementation, however, I opted for a **singly linked list** to store the stack. This design decision was made to simplify the implementation and improve clarity while maintaining the functionality required by the project.

The program was developed to work with a set of numbers, where the input consists of a list of integers. The program should sort these integers using the least number of operations, and then it can be validated by the `checker` program.

### How It Works

1. **Input**: The program accepts a space-separated list of integers as input. The integers are then pushed onto the stack `a`.
   
2. **Sorting Algorithm**: The `push_swap` program sorts the integers using the allowed operations, aiming to minimize the number of operations.
   
3. **Validation**: After the sorting process, you can use the `checker` program to validate if the stack is properly sorted. The checker program will output "OK" if the stack is sorted in ascending order or "KO" if the stack is not sorted correctly.

### Usage

1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd push_swap
   ```

2. Compile the program:
   - To compile and create the `push_swap` executable:
   ```bash
   make all
   ```
   - To compile and create the `checker` executable (bonus program):
   ```bash
   make bonus
   ```
   
3. To use the `push_swap` program to sort a list of integers:
   ```bash
   ./push_swap 3 2 1
   ```

4. To use the `checker` program to validate the sorting:
   ```bash
   ./push_swap 3 2 1 | ./checker 3 2 1
   ```

### Example

```bash
$ ./push_swap 3 2 1
pb
pb
sa
pa
pa
$ ./push_swap 3 2 1 | ./checker 3 2 1
OK
```

### Requirements

- `push_swap` will sort the stack using the least number of moves possible (according to the project’s requirements).
- The program works with any input consisting of integers.
- The `checker` program ensures the stack is sorted correctly.

### Contribution

Feel free to fork the project and contribute by submitting pull requests or reporting issues. If you have suggestions or improvements, I’d love to hear them!
