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


//
// Define template prototypes for level-1f kernels.
//

#undef  GENTPROT
#define GENTPROT( ctype, ch, opname ) \
\
void PASTEMAC(ch,opname) \
     ( \
       conj_t  conjx, \
       conj_t  conjy, \
       dim_t   n, \
       ctype*  alphax, \
       ctype*  alphay, \
       ctype*  x, inc_t incx, \
       ctype*  y, inc_t incy, \
       ctype*  z, inc_t incz, \
       cntx_t* cntx  \
     );

INSERT_GENTPROT_BASIC( axpy2v_ker_name )


#undef  GENTPROT
#define GENTPROT( ctype, ch, opname ) \
\
void PASTEMAC(ch,opname) \
     ( \
       conj_t  conja, \
       conj_t  conjx, \
       dim_t   m, \
       dim_t   b_n, \
       ctype*  alpha, \
       ctype*  a, inc_t inca, inc_t lda, \
       ctype*  x, inc_t incx, \
       ctype*  y, inc_t incy, \
       cntx_t* cntx  \
     );

INSERT_GENTPROT_BASIC( axpyf_ker_name )


#undef  GENTPROT
#define GENTPROT( ctype, ch, opname ) \
\
void PASTEMAC(ch,opname) \
     ( \
       conj_t  conjxt, \
       conj_t  conjx, \
       conj_t  conjy, \
       dim_t   n, \
       ctype*  alpha, \
       ctype*  x, inc_t incx, \
       ctype*  y, inc_t incy, \
       ctype*  rho, \
       ctype*  z, inc_t incz, \
       cntx_t* cntx  \
     );

INSERT_GENTPROT_BASIC( dotaxpyv_ker_name )


#undef  GENTPROT
#define GENTPROT( ctype, ch, opname ) \
\
void PASTEMAC(ch,opname) \
     ( \
       conj_t  conjat, \
       conj_t  conja, \
       conj_t  conjw, \
       conj_t  conjx, \
       dim_t   m, \
       dim_t   b_n, \
       ctype*  alpha, \
       ctype*  a, inc_t inca, inc_t lda, \
       ctype*  w, inc_t incw, \
       ctype*  x, inc_t incx, \
       ctype*  beta, \
       ctype*  y, inc_t incy, \
       ctype*  z, inc_t incz, \
       cntx_t* cntx  \
     );

INSERT_GENTPROT_BASIC( dotxaxpyf_ker_name )


#undef  GENTPROT
#define GENTPROT( ctype, ch, opname ) \
\
void PASTEMAC(ch,opname) \
     ( \
       conj_t  conjat, \
       conj_t  conjx, \
       dim_t   m, \
       dim_t   b_n, \
       ctype*  alpha, \
       ctype*  a, inc_t inca, inc_t lda, \
       ctype*  x, inc_t incx, \
       ctype*  beta, \
       ctype*  y, inc_t incy, \
       cntx_t* cntx  \
     );

INSERT_GENTPROT_BASIC( dotxf_ker_name )

