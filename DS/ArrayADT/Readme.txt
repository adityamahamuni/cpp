# Challenges

# Find Missing Element in Sorted Array

## Finding single missing element in an Array

1. Using summation formula - O(n)

	a. Sum = n * (n+1) / 2
	b. find the sum of all elements in the array
	c. return the difference between Summation and sum of all elements in the array.

2. Using Indices - O(n)

	l = first element
	h = last element
	n = number of elements in the array

	diff = l - first index(0)

	for i:=0 to n-1:

		if A[i] - i != diff:
		return diff+i;


## Finding Multiple missing elements in an Array

1. Using Indices - O(n)

	l = first element
	h = last element
	n = number of elements in the array

	diff = l - first index(0)

	for i:=0 to n-1:

		if A[i] - i != diff:
		while (diff < A[i] - 1):
			print(i+diff);
		diff++;



# Find Duplicates in Sorted Array

	A = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20}

	n = number of elements
	lastDuplicate = 0;

	for i:=0 to n:
		if A[i] == A[i+1] and if lastDuplicate != A[i]:
			display A[i]; lastDuplicate := A[i];


 ## Counting Duplicates -

	n = number of elements
	lastDuplicate = 0;
	
	for i:=0 to n-1:
		if A[i] == A[i+1] 
			j = j+1;
			while (A[j] == A[i]):
				j++;
				print(j-1 + "number is appearing" + j-i + "times.");
				i = j-1;

			if lastDuplicate != A[i]:
				display A[i]; lastDuplicate := A[i];


## Find Duplicates in Sorted Array using Hashing - O(n)

	A = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20}

	H = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} - 20 elements

		for i:= 0 to n-1:
			H[A[i]]++;

		for i:= 0 to max:
			if H[i] > 1:
				print(i + "number is appearing " + H[i] + "times.");


## Find Duplicates in Unsorted Array

		A = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7}



# Find a pair with sum k

## General Method - O(n^2)
	A = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14}

	a + b = k

	for i:=0 to n-1:
		for j:=i+1 to n:
			if A[i] + A[j] == k:
				print(A[j], A[j]);


## Hashing - O(n)
	A = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14}

	H = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

	for i:=0 to n:
		if H[k-A[i]] != 0:
			print(A[i], k-A[i]);
		H[A[i]]++;



# Find a pair with sum k in Sorted Array

	A = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14}

	i:=0, j:=n-1

	while i<j:
		if A[i] + A[j] == k:
			print(A[i], A[j]);
			i++;
			j--;
		else if A[i] + A[j] < k:
			i++;
		else:
			j--;


# Find Max and Min in one sweep - O(n)

	A = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4}

	min := A[0];
	max := A[0];

	for i:=0 to n:
		if A[i] < min:
			min := A[i]
		else if A[i] > max:
			max := A[i]
