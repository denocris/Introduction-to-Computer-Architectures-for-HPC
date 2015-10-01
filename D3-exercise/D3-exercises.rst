D3-exercises
============


Exercise 1
==========

- First  develop  a  raw  version  of  the  transpose  code  for  a square   matrix.   
- Implement   a   second   version   of   the transpose  code  (the  fast-transpose)  including  the  cache friendly   schema   presented   in   class.   Check   the  performance  difference  for  different  matrix  sizes  (1024, 2048, 4096) and different buffer sizes. 

Exercise 2
==========

- Develop a matrix-matrix multiplication code in c, using a buffer to store the columns of the second matrix. For the operation c(n,o)=a(n,m)*b(m,o) this amount to store in the buffer the columns of b. The order of loops should be such that you could reuse the buffer as much as possible.   
