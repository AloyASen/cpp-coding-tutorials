

created webcam_capture.cpp
g++ -Wall -g -c webcam_capture.cpp -o webcam_capture.x
chmod +x webcam_capture.x
./webcam_capture.x
bash: ./webcam_capture.x: cannot execute binary file: Exec format error



Interesting i've compiled in in reverse order and it worked...

WORKS (EXEC)
$ g++ -Wall -o webcam_capture.bin webcam_capture.cpp

FAILS (EXEC)
$ g++ -Wall -g -c webcam_capture.cpp -o webcam_capture.bin




compiling with -c option, the output is an object file, such as main.o, my_code.o, not executable. without -c option, gcc compile the codes directly from C/C++ code to executable (without object files).

That's why you get strange "reverse order" results.

We normally do:

Compile: g++ -Wall -o webcam_capture.o -c webcam_capture.cpp (reverse ok), and
Link: g++ -Wall -o webcam_capture.bin webcam_capture.o
And normally, we don't even use .bin extension for the executables. The executable normally has no extension in Unix/Linux.
