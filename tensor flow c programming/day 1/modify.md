clang -o tensorflowc++test tensorflowc++test.c -I/usr/local/include -L/usr/local/lib -ltensorflow


this program has been compiled while the anaconda environment is active ... once done the code is ready to be used without the env activated

the code can also be ported for different machine architectural implementations by using llc {{ in the llvm suite }}
