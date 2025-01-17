#!/bin/bash

# Test case array
test_cases=(
    "2 1 0"
    "42"
    "1 2 3 4 5"
    "1 2 one"
	"1 2 21474836479"
	"1 2 2"
	""
)
# Add a test case for 3 random numbers between 1 and 500
random_test_3=$(shuf -i 1-500 -n 3 | tr '\n' ' ')
# Add a test case for 5 random numbers between 1 and 500
random_test_5=$(shuf -i 1-500 -n 5 | tr '\n' ' ')
# Add a test case for 100 random numbers between 1 and 500
random_test_100=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
# Add a test case for 500 random numbers between 1 and 5000
random_test_500=$(shuf -i 1-5000 -n 500 | tr '\n' ' ')
test_cases+=("$random_test_3")
test_cases+=("$random_test_5")
test_cases+=("$random_test_100")
test_cases+=("$random_test_500")

# Loop through test cases
for case in "${test_cases[@]}"; do
    echo "Testing case: $case"

    # Run push_swap to get the sequence of operations, capturing stdout and stderr
    operations=$(./push_swap $case 2>stderr_output)
    stderr=$(cat stderr_output)

    # Check for "Error" in stderr
    if [[ "$stderr" == *"Error"* ]]; then
        echo "Test case '$case': Failed ❌ (Error detected in stderr)"
        echo
        continue
    fi
	# Ensure operations output is processed correctly
    if [[ -z "$operations" || "$operations" =~ ^[[:space:]]*$ ]]; then
        num_operations=0
    else
        # Remove empty lines and count the number of operations
        num_operations=$(echo "$operations" | sed '/^$/d' | wc -l)
    fi
    # Simulate operations using checker (or validate manually)
    result=$(echo "$operations" | ./checker $case 2>/dev/null)

    # Check if the output is OK (sorted correctly) or KO
    if [[ "$result" == "OK" || -z "$result" ]]; then
        echo "Test case '$case': Passed ✅ (Result: $result)"
		echo "Number of operations: $num_operations"
    else
        echo "Test case '$case': Failed ❌ (Result: $result)"
    fi
	echo
done

# Clean up temporary stderr file
rm -f stderr_output