# Python program for implementation of Insertion Sort

# Function to do insertion sort
def insertionSort(array):

	# Traverse through 1 to len(arr)

	for i in range(1, len(array)):

		key = array[i]

		# Move elements of arr[0..i-1], that are
		# greater than key, to one position ahead
		# of their current position

		j = i-1
		while j >= 0 and key < array[j] :
				array[j + 1] = array[j]
				j -= 1
		array[j + 1] = key


# Driver code to test above

array = [121, 101, 153, 55, 56]
insertionSort(array)
for i in range(len(array)):
	print ("% d" % array[i])