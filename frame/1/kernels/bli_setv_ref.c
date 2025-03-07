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

#undef  GENTFUNC
#define GENTFUNC( ctype, ch, varname ) \
\
void PASTEMAC(ch,varname) \
     ( \
       conj_t  conjalpha, \
       dim_t   n, \
       ctype*  alpha, \
       ctype*  x, inc_t incx, \
       cntx_t* cntx  \
     ) \
{ \
	ctype* chi1; \
	ctype  alpha_conj; \
	dim_t  i; \
\
	if ( bli_zero_dim1( n ) ) return; \
\
	chi1 = x; \
\
	if ( PASTEMAC(ch,eq0)( *alpha ) ) \
	{ \
		for ( i = 0; i < n; ++i ) \
		{ \
			PASTEMAC(ch,set0s)( *chi1 ); \
\
			chi1 += incx; \
		} \
	} \
	else \
	{ \
		PASTEMAC(ch,copycjs)( conjalpha, *alpha, alpha_conj ); \
\
		for ( i = 0; i < n; ++i ) \
		{ \
			PASTEMAC(ch,copys)( alpha_conj, *chi1 ); \
\
			chi1 += incx; \
		} \
	} \
}

INSERT_GENTFUNC_BASIC0( setv_ref )

