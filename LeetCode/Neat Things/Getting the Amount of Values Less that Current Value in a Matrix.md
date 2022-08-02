# Code
```C++
int temp = n - 1; //n being the size of the array, inputted array n x n, last row
int count = 0;
                 
//see how many elements are less than the mid
for(int i = 0; i < n; i++){
    while(temp >= 0 && matrix[i][temp] > middle){ //temp in col
	    temp--; //reduce the column temp ptr by one if above true.
        } 
	    count += (temp+1); //add temp + 1 to get count
    }
```

### Description
You have a nx n array and you need to find the amount of values in the matrix that are less than or equal to the passed in value.

Note: The array must be in sorted order for this to work. Meaning that the columns and row never decrease. Easy way to see it is in array context, if the numbers never get smaller from left to right between the arrays then we have sorted matrix.

Example:
((1, 5, 9), (10, 11, 13), (12, 13, 15)) Inputted Val -> 10 : *Output ->* 4

# Notes
- The thing I got most stuck on was how count was being added up. The temp + 1 -> temp is the row we are in, and since the array is already sorted we can just assume all temps that are in columns before (lower numbers) are also included since they would be less also. The 1 is for the element we are currently looking at. So all the elements in the columns before that are for this particular row, and the current element.

# Run Time / Space Time
Run time - O
Space time - O