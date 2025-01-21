# Minitalk

Minitalk is a simple message communication system using Unix signals. It allows a client to send messages to a server, where the server will process each message bit by bit using `SIGUSR1` and `SIGUSR2` signals.

## Overview

In this project, you will find:

- A **server** program that receives and decodes messages sent from multiple clients using signals.
- A **client** program that sends a message to the server by converting it into binary and transmitting each bit using the signals `SIGUSR1` and `SIGUSR2`.
  
The communication is based on sending each character of the message bit by bit, where `SIGUSR1` represents a 0 bit and `SIGUSR2` represents a 1 bit. The server decodes these signals and reconstructs the original message, printing it to the console.

## Features

- **Signal Communication:** Clients send messages bit by bit using `SIGUSR1` and `SIGUSR2` signals.
- **Message Handling:** Supports unicode messages with special characters, spaces, tabs, and newlines.
- **Server Feedback:** The server acknowledges each byte received and sends a response back to the client.

## How It Works

1. **Server:**
   - The server program listens for incoming signals (`SIGUSR1` and `SIGUSR2`).
   - It decodes the signals as bits and constructs the message bit by bit.
   - When a complete byte is received, it is printed to the console.
   - When an empty byte (value 0) is received, it indicates the end of the message.

2. **Client:**
   - The client program takes the server's PID and a message as input.
   - It converts the message into binary format and sends each bit using `SIGUSR1` (0) and `SIGUSR2` (1).
   - The client waits for the server to acknowledge each byte before proceeding.

## Compilation

You can compile the project using `make`. The Makefile handles the compilation of both the server and client programs.

```bash
make
```

This will generate the `server` and `client` executables.

## Usage

1. **Start the Server:**
   
   First, run the server program in one terminal. It will display its PID (Process ID).
   
   ```bash
   ./server
   ```

2. **Run the Client:**

   In another terminal, use the `client` program to send a message to the server. The client requires the server's PID as the first argument and the message as the second argument.
   
   ```bash
   ./client <server_pid> "<message>"
   ```

   Example:

   ```bash
   ./client 12345 "Hello, World!"
   ```

   The client will send the message "Hello, World!" to the server bit by bit.

3. **Test Script:**

   If you'd like to run a series of tests, you can use the provided script `test_server_client.sh`, which automates the process of starting the server, sending messages from the client, and stopping the server.

   ```bash
   ./test_server_client.sh
   ```

## Example

**Server:**

```bash
$ ./server
Server started with PID: 12345
```

**Client:**

```bash
$ ./client 12345 "Hello, World!"
Sending message: 'Hello, World!'
Sent: Hello, World!
Received: Hello, World!
```

**Server Output (printed message):**

```
Received: Hello, World!
```

## Notes

- The server can handle multiple clients, but the current implementation assumes that only one client is sending at a time. You may want to extend it to handle multiple clients simultaneously by implementing asynchronous signal handling.
- The `SIGUSR1` signal represents the binary value `0`, and `SIGUSR2` represents the binary value `1`. The server decodes these signals to form the original message.
- The client program sends the message bit by bit with a small delay (`usleep`) to ensure the server has time to process each bit.
