# smarttail
<!-- I have learned about the median filter and how it works.

The basic idea behind this filter is for any element of the signal to look at its neighborhood and pick up the element that is most similar.

Median filter algorithm:

place a window over the element
pick up elements
Order elements
Take the middle element
In the function median filter(), I have first moved the window through all the elements of the image, and pick up the window elements. Since I need only the middle element in the window, I have sorted only half the elements and put the minimum element in its position. Then I have set the result to the middle element.
Edges:
First I have to extend my image.
I have done that by adding lines at top and bottom and columns to left and right.
If N or M is less than 1 or invalid Null input, we exit out of the function 
Next is to allocate memory for a signal extension. After successfully filling the lines, we call for the median filter implementation.

We free the memory by deleting the extension. -->
