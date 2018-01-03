@dated -- 8 11 2017
-------------------------------

the file seems to have a lot of linkages and the file "libgslcblas.so" 
and other libraries are reportedly not being linked to the main source code.

============================================================================


@dated 09 11 2017
------------------------
the output of the bessel function is obtained

command

g++ qagiu_test.cpp -L/usr/local/lib -I /usr/local/include -lgsl -lgslcblas -lm -o qagiu_test

and ~/.bashrc is populated with LD_LIBRARY_PATH


==================================================================
