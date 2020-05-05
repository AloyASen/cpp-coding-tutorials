# load files into cpp programs

tested using coliru compiler (online) hosted
at

the command used is

```shell
g++ -std=c++17 -O2 -Wall -pedantic -pthread main.cpp && ./a.out
```

and now the same is to be stored down into system and stored into

fileName : readFileUniversalPath.cc

and compiled using the command

```shell
g++ -std=c++17 -O2 -Wall -pedantic -pthread readFileUniveralPath.cc -lstdc++fs -o readFileUniveralPath.out
```

to find the version of the compiler (I have used GCC to compile on linux)
Modify the command to fit your usecase

```shell
g++ -o getGCC_version.out getGCC_version.cc

my output :: Hello from GCC 7.4.0 !
```

**Note:: for newer versions of gcc this filesystem header has been moved to the mainstream code
do remember to upgrade the header inputs accordingly.
