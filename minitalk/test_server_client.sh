#!/bin/bash

# Paths to server and client executables
SERVER="./server"
CLIENT="./client"

# Check if server and client exist
if [[ ! -x "$SERVER" || ! -x "$CLIENT" ]]; then
  echo "Error: server or client executable not found or not executable."
  echo "Make sure the server and client are compiled and available."
  exit 1
fi

# Start the server
echo "Starting the server..."
$SERVER &
SERVER_PID=$!
echo "Server started with PID: $SERVER_PID"

# Wait for the server to initialize
sleep 1

# Test cases
declare -a TEST_CASES=(
    "Hello, World!"      # Simple message
    "42"                 # Numeric message
    'Special chars: !@#$%^&*()' # Special characters
    "Long message: $(head -c 500 < /dev/zero | tr '\0' 'A')" # Very long message
    ""                   # Empty message
    "Spaces and tabs\tand newlines\n" # Spaces, tabs, and newlines
)

# Function to send a message and validate the output
send_message() {
    local message="$1"
    printf "Sending message: '%s'\n" "$message"
    $CLIENT $SERVER_PID "$message"
    echo
}

# Run test cases
for test_case in "${TEST_CASES[@]}"; do
    send_message "$test_case"
    sleep 1 # Ensure proper handling of messages
done

# Stop the server
echo "Stopping the server..."
kill $SERVER_PID
wait $SERVER_PID 2>/dev/null
echo "Server stopped."

echo "All tests completed."
