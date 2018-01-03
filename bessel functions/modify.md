@dated 08 11 2017
------------------------

my bessel function is not being linked to 
the library functions being issued and the library file is not getting detected

====================================================================


@dated 09 11 2017
------------------------
the output of the bessel function is obtained

command

g++ gsl-lib-bessel.c -L/usr/local/lib -I /usr/local/include -lgsl -lgslcblas -lm -o gsl-lib-bessel

and ~/.bashrc is populated with LD_LIBRARY_PATH


==================================================================
