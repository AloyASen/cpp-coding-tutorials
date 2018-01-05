/*
this is the first program in function templates
@author :: Aloy Aditya Sen
dated:: 25 11 2017


Inline function instruct compiler to insert complete body of the function
 wherever that function got used in code.
  It also save overhead of variables push/pop on the stack, 
  while function calling. It also save overhead of return call from a
   function. It increases locality of reference by utilizing instruction cache.



-------------

The inline functions are
 a C++ enhancement feature to increase the execution time of a program.
  Functions can be instructed to compiler to make them inline
   so that compiler can replace those function definition wherever those are being called.
    as of (May 6, 2014) 




*/

template <typename t>
inline t const& max ( t const& a , t const& b){
	//this function returns the max of the parameters supplied
	return a<b ? b:a;
}

 //in the above program typename can also be replaced by 

 //the keyword class ... as both remains valid due to historical importance 
/*
 @dated 04 01 2018

 todays  learnings
 -----=====-----====

 template argument deduction does not undergo type casting to match params
 for casting specific arguments into desired types use the static_cast<[type to parse]>

 


*/
