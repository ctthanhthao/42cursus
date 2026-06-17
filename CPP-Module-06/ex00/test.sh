#!/bin/bash

EXEC=./converter

GREEN='\033[0;32m'
NC='\033[0m'

tests=(
    "'a'"
    "'*'"
    "0"
    "42"
    "127"
    "128"
    "-1"
    "2147483647"
    "2147483648"
    "-2147483648"
    "-2147483649"
    "42.0"
    "42.0f"
    "4.2"
    "4.2f"
    "nan"
    "nanf"
    "+inf"
    "-inf"
    "+inff"
    "-inff"
    "+353454354654656757"
)

for test in "${tests[@]}"
do
    echo "========================================"
    echo -e "${GREEN}INPUT: $test${NC}"
    echo "----------------------------------------"
    $EXEC "$test"
    echo
done

invalids=(
    ""
    "abc"
    "42abc"
    "4.2ff"
    "++42"
    "--42"
    "1.2.3"
    "0x42"
)
echo "========== INVALID INPUTS =========="

for test in "${invalids[@]}"
do
	echo "========================================"
    echo -e "${GREEN}INPUT: $test${NC}"
    echo "----------------------------------------"
    $EXEC "$test"
    echo
done