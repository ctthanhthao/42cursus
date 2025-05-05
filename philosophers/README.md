# Dining Philosophers Simulation

A C implementation of the classic Dining Philosophers problem, demonstrating inter-thread and inter-process synchronization using mutexes and POSIX named semaphores.

<img src= "https://github.com/user-attachments/assets/63a818b6-9714-4a45-8cb7-ce7059677c80" width="500" height="500"/>

## Features

### Mandatory Part

- Thread-based simulation with each philosopher as a separate thread.
- Synchronization of shared resources (forks) using mutexes.
- Asymmetric fork acquisition strategy to prevent deadlocks:
  - Even-numbered philosophers pick up the left fork first, then the right.
  - Odd-numbered philosophers pick up the right fork first, then the left.
- Two monitor threads:
  - **Death Monitor**: Continuously checks if any philosopher has died due to starvation.
  - **Fullness Monitor**: Checks if all philosophers have eaten the required number of times.

### Bonus Part

- Process-based simulation with each philosopher as a separate process.
- Synchronization of shared resources using POSIX named semaphores.
- Graceful handling of process termination and resource cleanup.
- In each process, there is a monitor death thread:
  - **Death Monitor**: Continuously checks if that philosopher has died due to starvation.

### Visualize philosopher actions
using the Philosophers Visualizer: https://nafuka11.github.io/philosophers-visualizer/ 

## Requirements

- GCC compiler
- Make
- POSIX-compliant operating system (e.g., Linux)
- Valgrind (optional, for debugging)

## Installation

1. **Build the project:**

   - **Mandatory Part:**

     ```bash
     philo> make
     ```

   - **Bonus Part:**

     ```bash
     philo_bonus> make
     ```

## Usage

- **Mandatory Part:**

  
```bash
  ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
  ```

- **Bonus Part:**

  
```bash
  ./philo_bonus [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
  ```

**Example:**


```bash
./philo 5 800 200 200 3
```

This command starts the simulation with 5 philosophers, where each philosopher must eat 3 times.

## Testing

To run the simulation under Valgrind for detecting memory leaks and concurrency issues:


```bash
valgrind --tool=helgrind --fair-sched=yes --history-level=none ./philo 5 800 200 200 3
```

Ensure that all semaphores are properly unlinked and resources are cleaned up after the simulation ends.

## Tester

A semi-automatic tester for checking 42's philosophers project (2021 curriculum).
https://github.com/MichelleJiam/LazyPhilosophersTester

## License

This project is licensed under the MIT License.
