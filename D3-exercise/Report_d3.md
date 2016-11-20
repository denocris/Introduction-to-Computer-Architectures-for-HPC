# Report of Day 3: Fast Transpose

We develop two functions to compute the transpose of a square matrix. Everything can be found in the folder code/: 

- transpose.c

The fist function is the naive computation and is pretty slow. 

```c
for(i=0; i < dim; i++)
    for(j=0; j < dim; j++)
    AT[i*dim + j]=A[j*dim + i];
```

The second function is cache friendly and performs really better. The main lines of code are:
```c
for(i=0; i < dim; i+=block_size)
    for(j=0; j < dim; j+=block_size)
        for(bi = i; bi < i+block_size; ++bi)
            for(bj = j; bj < j+block_size; ++bj){
            AT[bi + bj*dim] = A[bi*dim + bj];
}
```

We checked the performance for four different matrix size (2048,4096,8192,16384) and in the case of the fast function we tried different block sizes. ATTENTION: on the y-axes we have Log(time).


![Figure_1](transpose.jpg)

The constant dashed lines in the figure represent the computational time of slow function. This is always greater than the fast function time.

Every details about the code can be found in the folder code/.