def adaptive_insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]  # current element to be inserted
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]  # shifting elements to the right
            j -= 1
        arr[j + 1] = key  # placing the current element in its correct position

# Example usage:
arr = [5, 2, 4, 6, 1, 3]
adaptive_insertion_sort(arr)
print("Sorted array:", arr)