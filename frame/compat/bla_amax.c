/*

   BLIS    
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2014, The University of Texas at Austin

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    - Neither the name of The University of Texas at Austin nor the names
      of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "blis.h"


//
// Define BLAS-to-BLIS interfaces.
//
#undef  GENTFUNC
#define GENTFUNC( ftype_x, chx, blasname, blisname ) \
\
f77_int PASTEF772(i,chx,blasname) \
     ( \
       f77_int* n, \
       ftype_x* x, f77_int* incx  \
     ) \
{ \
	dim_t    n0; \
	ftype_x* x0; \
	inc_t    incx0; \
	gint_t   bli_index; \
	f77_int  f77_index; \
	err_t    init_result; \
\
	/* If the vector is empty, return an index of zero. This early check
	   is needed to emulate netlib BLAS. Without it, bli_?amaxv() will
	   return 0, which ends up getting incremented to 1 (below) before
	   being returned, which is not what we want. */ \
	if ( *n < 1 || *incx <= 0 ) return 0; \
\
	/* Initialize BLIS (if it is not already initialized). */ \
	bli_init_auto( &init_result ); \
\
	/* Convert/typecast negative values of n to zero. */ \
	bli_convert_blas_dim1( *n, n0 ); \
\
	/* If the input increments are negative, adjust the pointers so we can
	   use positive increments instead. */ \
	bli_convert_blas_incv( n0, x, *incx, x0, incx0 ); \
\
	/* Call BLIS interface. */ \
	PASTEMAC(chx,blisname) \
	( \
	  n0, \
	  x0, incx0, \
	  &bli_index, \
	  NULL  \
	); \
\
	/* Convert zero-based BLIS (C) index to one-based BLAS (Fortran)
	   index. */ \
	f77_index = bli_index + 1; \
\
	/* Finalize BLIS (if it was initialized above). */ \
	bli_finalize_auto( init_result ); \
\
	return f77_index; \
}

#ifdef BLIS_ENABLE_BLAS2BLIS
INSERT_GENTFUNC_BLAS( amax, amaxv )
#endif

