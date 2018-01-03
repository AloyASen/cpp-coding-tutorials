this file is an example of templates in c++ 

this has been a priority to codes of large sizes since this 

introduces the requirement of design patterns in coding 

and also  allow other coders in the programming world to 

help in the mission  contribute to a collective world

dated 26 11 2017 
------------------

the program is correct but is not linking 


command 
--------------

g++ stac
ktemplate.cc -o stacktemplate -std=c++11


error in output
-------------

/tmp/ccuaLXln.o: In function `main':
stacktemplate.cc:(.text+0x33): undefined reference to `Stack<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Stack()'
stacktemplate.cc:(.text+0x189): undefined reference to `Stack<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::~Stack()'
stacktemplate.cc:(.text+0x1f0): undefined reference to `Stack<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::~Stack()'
collect2: error: ld returned 1 exit status

