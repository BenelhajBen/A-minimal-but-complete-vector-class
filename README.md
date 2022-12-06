# A-minimal-but-complete-vector-class
A vector class that takes into account a minimal but complete implementation.


List of functionality that can be used:

vector[unsigned index]: with exception handling for index out of bounds. allows you to edit data
at(unsigned index): with exception handling for index out of bounds. allows you to edit data
push_back: to insert data into your vector.
pop: to remove data from your vector.
GetSize: returns the current size or the amount of data in the vector.
= Assignment operator to set a vector to another existing vector, and a copy constructor that allows you to copy a new vector from and already existing vector.
begin: returns the first value within the vector.
end: return the last value within the vector.
GetCapacity: returns the current capacity or the storage space in memory for the amount of values that can be added to the vector. This will change as more values are inserted into the vector.

List of functionaly that can be optionally added:
reserve: Set the maximum allowed memory to be allocated within the vector.
resize: Resize the capacity of the vector or the maximum allowed elements the vector can hold.




