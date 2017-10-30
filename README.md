## learn-unp

编译过程：

```
./configure    # try to figure out all implementation differences

cd lib         # build the basic library that all programs need
make           # use "gmake" everywhere on BSD/OS systems

cd ../libfree  # continue building the basic library
make

cd ../libroute # only if your system supports 4.4BSD style routing sockets
make           # only if your system supports 4.4BSD style routing sockets

# 非必要情况下
cd ../libxti   # only if your system supports XTI
make           # only if your system supports XTI
```
