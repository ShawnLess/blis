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
       dim_t   n, \
       ctype*  alpha, \
       ctype*  x, inc_t incx, \
       ctype*  y, inc_t incy, \
       cntx_t* cntx  \
     ) \
{ \
	ctype* chi1; \
	ctype* psi1; \
	dim_t  i; \
\
	if ( bli_zero_dim1( n ) ) return; \
\
	/* If alpha is zero, return. */ \
	if ( PASTEMAC(ch,eq0)( *alpha ) ) return; \
\
	/* If alpha is one, use addv. */ \
	if ( PASTEMAC(ch,eq1)( *alpha ) ) \
	{ \
		/* Query the context for the kernel function pointer. */ \
		const num_t         dt     = PASTEMAC(ch,type); \
		PASTECH(ch,addv_ft) addv_p = bli_cntx_get_l1v_ker_dt( dt, BLIS_ADDV_KER, cntx ); \
\
		addv_p \
		( \
		  conjx, \
		  n, \
		  x, incx, \
		  y, incy, \
		  cntx  \
		); \
		return; \
	} \
\
	chi1 = x; \
	psi1 = y; \
\
	if ( bli_is_conj( conjx ) ) \
	{ \
		for ( i = 0; i < n; ++i ) \
		{ \
			PASTEMAC(ch,axpyjs)( *alpha, *chi1, *psi1 ); \
\
			chi1 += incx; \
			psi1 += incy; \
		} \
	} \
	else \
	{ \
		for ( i = 0; i < n; ++i ) \
		{ \
			PASTEMAC(ch,axpys)( *alpha, *chi1, *psi1 ); \
\
			chi1 += incx; \
			psi1 += incy; \
		} \
	} \
}

INSERT_GENTFUNC_BASIC0( axpyv_ref )

