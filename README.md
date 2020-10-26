## OOP tar list implementation

The program works on Linux/Unix

To build:

    make         - prepare to execute
    make all     - same above
    make dep     - produce .o files
    make create  - creates test.tar to make a test
    make clean   - delete vice-files

Usage:

    $ ./mytar test

Sample output:

    drwxr-xr-x popo/popo         0 2020-10-26 14:49 a/
    -rw-r--r-- popo/popo     69368 2020-10-26 14:49 a/tar.o
    -rw-r--r-- popo/popo      3417 2020-10-26 14:46 a/tar.cpp
    -rw-r--r-- popo/popo     10512 2020-10-26 14:49 a/mytar.o
    -rw-r--r-- popo/popo       345 2020-10-26 14:49 a/Makefile
    -rw-r--r-- popo/popo       213 2020-10-26 13:31 a/mytar.cpp
    -rw-r--r-- popo/popo      1177 2020-10-26 14:15 a/tar.h

Reference:

    [Origin]:(https://github.com/calccrypto/tar.git)
