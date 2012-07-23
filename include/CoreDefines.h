/***********************************************************************
* Some useful preprocessor definitions
* Please add the approriate ifdef/endif blocks for various operating systems if you find any 
* incompatibilities
*/

#include <assert.h> 

#ifdef WIN32
	MEMCPY(dst, size, src, num) (memcpy_s((dst), (size), (src), (num)))
#else
#endif