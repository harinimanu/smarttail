#include <memory.h>
//N-width of the image
//M-height of the image
void medianfilter(const element* image, element* result, int N, int M)
{
   //Move window through all elements of the image
   for (int m = 1; m < M - 1; ++m)
      for (int n = 1; n < N - 1; ++n)
      {
         //Pick up window elements
         int k = 0;
         element window[9];
         for (int j = m - 1; j < m + 2; ++j)
            for (int i = n - 1; i < n + 2; ++i)
               window[k++] = image[j * N + i];
         //Order elements (only half of them)
         for (int j = 0; j < 5; ++j)
         {
            //Find position of minimum element
            int min = j;
            for (int l = j + 1; l < 9; ++l)
            if (window[l] < window[min])
               min = l;
            //Put found minimum element in its place
            const element temp = window[j];
            window[j] = window[min];
            window[min] = temp;
         }
         //result-the middle element
         result[(m - 1) * (N - 2) + n - 1] = window[4];
      }
}
void medianfilter(element* image, element* result, int N, int M)
{
   //Check arguments
   if (!image || N < 1 || M < 1)
      return;
   //Allocate memory for signal extension
   element* extension = new element[(N + 2) * (M + 2)];
   //heck memory allocation
   if (!extension)
      return;
   //Create image extension
   for (int i = 0; i < M; ++i)
   {
      memcpy(extension + (N + 2) * (i + 1) + 1,
         image + N * i,
         N * sizeof(element));
      extension[(N + 2) * (i + 1)] = image[N * i];
      extension[(N + 2) * (i + 2) - 1] = image[N * (i + 1) - 1];
   }
   //Fill first line of image extension
   memcpy(extension,
      extension + N + 2,
      (N + 2) * sizeof(element));
   //Fill last line of image extension
   memcpy(extension + (N + 2) * (M + 1),
      extension + (N + 2) * M,
      (N + 2) * sizeof(element));
   //Call median filter implementation
   _medianfilter(extension, result ? result : image, N + 2, M + 2);
   //Free memory
   delete[] extension;
}