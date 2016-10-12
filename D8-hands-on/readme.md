# run hpl with GPU (Moreno Baricevic is acknowledged)

## Ulysses

make a directory in your home and cd in it

```
mkdir ~/hpl+gpu && cd ~/hpl+gpu
```
copy files

```
cp /scratch/baro/hpl+gpu/* .
```

to run with 1 GPU

```
ln -sf HPL.dat.np1 HPL.dat ; NP=1 ./wrap.sh
```

to run with 2 GPU

```
ln -sf HPL.dat.np2 HPL.dat ; NP=2 ./wrap.sh
```

**reserved queue: reserved2**

```
qsub ... -q reserved2
```

## Cosint

make a directory in your home and cd in it

```
mkdir ~/hpl+gpu && cd ~/hpl+gpu
```
copy files

```
cp /lustre/mhpc/eas/hpl+gpu/* .
```

to run with 1 GPU

```
ln -sf HPL.dat.np1 HPL.dat ; NP=1 ./wrap.sh
```

to run with 2 GPU

```
ln -sf HPL.dat.np2 HPL.dat ; NP=2 ./wrap.sh
```

**reserved queue: gpu**

```
qsub ... -q gpu
```




