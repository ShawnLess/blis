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
       conj_t  conjx, \
       conj_t  conjy, \
       dim_t   n, \
       ctype*  alpha, \
       ctype*  x, inc_t incx, \
       ctype*  y, inc_t incy, \
       ctype*  beta, \
       ctype*  rho, \
       cntx_t* cntx  \
     ) \
{ \
	ctype* chi1; \
	ctype* psi1; \
	ctype  dotxy; \
	dim_t  i; \
	conj_t conjx_use; \
\
	/* If beta is zero, clear rho. Otherwise, scale by beta. */ \
	if ( PASTEMAC(ch,eq0)( *beta ) ) \
	{ \
		PASTEMAC(ch,set0s)( *rho ); \
	} \
	else \
	{ \
		PASTEMAC(ch,scals)( *beta, *rho ); \
	} \
\
	if ( bli_zero_dim1( n ) ) return; \
\
	PASTEMAC(ch,set0s)( dotxy ); \
\
	chi1 = x; \
	psi1 = y; \
\
	/* If y must be conjugated, we do so indirectly by first toggling the
	   effective conjugation of x and then conjugating the resulting dot
	   product. */ \
	conjx_use = conjx; \
\
	if ( bli_is_conj( conjy ) ) \
		bli_toggle_conj( conjx_use ); \
\
	if ( bli_is_conj( conjx_use ) ) \
	{ \
		for ( i = 0; i < n; ++i ) \
		{ \
			PASTEMAC(ch,dotjs)( *chi1, *psi1, dotxy ); \
\
			chi1 += incx; \
			psi1 += incy; \
		} \
	} \
	else \
	{ \
		for ( i = 0; i < n; ++i ) \
		{ \
			PASTEMAC(ch,dots)( *chi1, *psi1, dotxy ); \
\
			chi1 += incx; \
			psi1 += incy; \
		} \
	} \
\
	if ( bli_is_conj( conjy ) ) \
		PASTEMAC(ch,conjs)( dotxy ); \
\
	PASTEMAC(ch,axpys)( *alpha, dotxy, *rho ); \
}

INSERT_GENTFUNC_BASIC0( dotxv_ref )

