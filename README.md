## learn-unp

Compile：

```shell
./configure    # try to figure out all implementation differences

cd lib         # build the basic library that all programs need
make           # use "gmake" everywhere on BSD/OS systems

cd ../libfree  # continue building the basic library
make

cd ../libroute # only if your system supports 4.4BSD style routing sockets
make           # only if your system supports 4.4BSD style routing sockets

# not necessary
cd ../libxti   # only if your system supports XTI
make           # only if your system supports XTI
```

create new directory：
```shell
# at this directory root, filename is not necessary
./newdir-sh <your directory name> <filename>
```

Those directories is necessary：
```
/lib
/libfree
/libroute
```
**you can remove another directories**
