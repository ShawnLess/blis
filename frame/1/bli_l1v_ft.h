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

#ifndef BLIS_L1V_FT_H
#define BLIS_L1V_FT_H


//
// -- Level-1v function types --------------------------------------------------
//

// addv, copyv, subv

#undef  GENTDEF
#define GENTDEF( ctype, ch, opname, tsuf ) \
\
typedef void (*PASTECH2(ch,opname,tsuf)) \
     ( \
       conj_t          conjx, \
       dim_t           n, \
       ctype*          x, inc_t incx, \
       ctype*          y, inc_t incy, \
       cntx_t*         cntx  \
     );

INSERT_GENTDEF( addv )
INSERT_GENTDEF( copyv )
INSERT_GENTDEF( subv )

// axpyv, scal2v

#undef  GENTDEF
#define GENTDEF( ctype, ch, opname, tsuf ) \
\
typedef void (*PASTECH2(ch,opname,tsuf)) \
     ( \
       conj_t          conjx, \
       dim_t           n, \
       ctype*          alpha, \
       ctype*          x, inc_t incx, \
       ctype*          y, inc_t incy, \
       cntx_t*         cntx  \
     );

INSERT_GENTDEF( axpyv )
INSERT_GENTDEF( scal2v )

// dotv

#undef  GENTDEF
#define GENTDEF( ctype, ch, opname, tsuf ) \
\
typedef void (*PASTECH2(ch,opname,tsuf)) \
     ( \
       conj_t          conjx, \
       conj_t          conjy, \
       dim_t           n, \
       ctype*          x, inc_t incx, \
       ctype*          y, inc_t incy, \
       ctype*          rho, \
       cntx_t*         cntx  \
     );

INSERT_GENTDEF( dotv )

// dotxv

#undef  GENTDEF
#define GENTDEF( ctype, ch, opname, tsuf ) \
\
typedef void (*PASTECH2(ch,opname,tsuf)) \
     ( \
       conj_t          conjx, \
       conj_t          conjy, \
       dim_t           n, \
       ctype*          alpha, \
       ctype*          x, inc_t incx, \
       ctype*          y, inc_t incy, \
       ctype*          beta, \
       ctype*          rho, \
       cntx_t*         cntx  \
     );

INSERT_GENTDEF( dotxv )

// invertv

#undef  GENTDEF
#define GENTDEF( ctype, ch, opname, tsuf ) \
\
typedef void (*PASTECH2(ch,opname,tsuf)) \
     ( \
       dim_t           n, \
       ctype*          x, inc_t incx, \
       cntx_t*         cntx  \
     );

INSERT_GENTDEF( invertv )

// scalv, setv

#undef  GENTDEF
#define GENTDEF( ctype, ch, opname, tsuf ) \
\
typedef void (*PASTECH2(ch,opname,tsuf)) \
     ( \
       conj_t          conjalpha, \
       dim_t           n, \
       ctype*          alpha, \
       ctype*          x, inc_t incx, \
       cntx_t*         cntx  \
     );

INSERT_GENTDEF( scalv )
INSERT_GENTDEF( setv )

// swapv

#undef  GENTDEF
#define GENTDEF( ctype, ch, opname, tsuf ) \
\
typedef void (*PASTECH2(ch,opname,tsuf)) \
     ( \
       dim_t           n, \
       ctype*          x, inc_t incx, \
       ctype*          y, inc_t incy, \
       cntx_t*         cntx  \
     );

INSERT_GENTDEF( swapv )




#endif

