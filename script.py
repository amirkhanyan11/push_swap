import random

# Get the desired range from the user
lower_bound = -100
upper_bound = 400 + 1  # Include upper bound

# lower_bound = int(input("Enter the lower bound of the range: "))
# upper_bound = int(input("Enter the upper bound of the range: ")) + 1  # Include upper bound

# Generate all unique random numbers in the range
total_numbers = upper_bound - lower_bound  # Calculate total numbers in range

# Use set to ensure unique elements (avoid duplicates)
random_numbers = set()
while len(random_numbers) < total_numbers:
  random_numbers.add(random.randint(lower_bound, upper_bound - 1))

# Convert set back to list for printing (optional)
# random_numbers_list = list(random_numbers)  # Uncomment if you prefer a list

# Print the numbers on a single line separated by spaces
print(*random_numbers)  # Unpack the set using * operator

