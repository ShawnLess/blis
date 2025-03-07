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

// Guard the function definitions so that they are only compiled when
// #included from files that define the object API macros.
#ifdef BLIS_ENABLE_OAPI

//
// Define object-based interfaces.
//

#undef  GENFRONT
#define GENFRONT( opname ) \
\
void PASTEMAC(opname,EX_SUF) \
     ( \
       obj_t*  x, \
       obj_t*  y  \
       BLIS_OAPI_CNTX_PARAM  \
     ) \
{ \
	BLIS_OAPI_CNTX_DECL \
\
	num_t     dt        = bli_obj_datatype( *x ); \
\
	conj_t    conjx     = bli_obj_conj_status( *x ); \
	dim_t     n         = bli_obj_vector_dim( *x ); \
	void*     buf_x     = bli_obj_buffer_at_off( *x ); \
	inc_t     inc_x     = bli_obj_vector_inc( *x ); \
	void*     buf_y     = bli_obj_buffer_at_off( *y ); \
	inc_t     inc_y     = bli_obj_vector_inc( *y ); \
\
	if ( bli_error_checking_is_enabled() ) \
	    PASTEMAC(opname,_check)( x, y ); \
\
	/* Invoke the void pointer-based function. */ \
	bli_call_ft_7 \
	( \
	   dt, \
	   opname, \
	   conjx, \
	   n, \
	   buf_x, inc_x, \
	   buf_y, inc_y, \
	   cntx  \
	); \
}

GENFRONT( addv )
GENFRONT( copyv )
GENFRONT( subv )



#undef  GENFRONT
#define GENFRONT( opname ) \
\
void PASTEMAC(opname,EX_SUF) \
     ( \
       obj_t*  alpha, \
       obj_t*  x, \
       obj_t*  y  \
       BLIS_OAPI_CNTX_PARAM  \
     ) \
{ \
	BLIS_OAPI_CNTX_DECL \
\
	num_t     dt        = bli_obj_datatype( *x ); \
\
	conj_t    conjx     = bli_obj_conj_status( *x ); \
	dim_t     n         = bli_obj_vector_dim( *x ); \
	void*     buf_x     = bli_obj_buffer_at_off( *x ); \
	inc_t     inc_x     = bli_obj_vector_inc( *x ); \
	void*     buf_y     = bli_obj_buffer_at_off( *y ); \
	inc_t     inc_y     = bli_obj_vector_inc( *y ); \
\
	void*     buf_alpha; \
\
	obj_t     alpha_local; \
\
	if ( bli_error_checking_is_enabled() ) \
	    PASTEMAC(opname,_check)( alpha, x, y ); \
\
	/* Create local copy-casts of scalars (and apply internal conjugation
	   as needed). */ \
	bli_obj_scalar_init_detached_copy_of( dt, BLIS_NO_CONJUGATE, \
	                                      alpha, &alpha_local ); \
	buf_alpha = bli_obj_buffer_for_1x1( dt, alpha_local ); \
\
	/* Invoke the void pointer-based function. */ \
	bli_call_ft_8 \
	( \
	   dt, \
	   opname, \
	   conjx, \
	   n, \
	   buf_alpha, \
	   buf_x, inc_x, \
	   buf_y, inc_y, \
	   cntx  \
	); \
}

GENFRONT( axpyv )
GENFRONT( scal2v )


#undef  GENFRONT
#define GENFRONT( opname ) \
\
void PASTEMAC(opname,EX_SUF) \
     ( \
       obj_t*  x, \
       obj_t*  y, \
       obj_t*  rho  \
       BLIS_OAPI_CNTX_PARAM  \
     ) \
{ \
	BLIS_OAPI_CNTX_DECL \
\
	num_t     dt        = bli_obj_datatype( *x ); \
\
	conj_t    conjx     = bli_obj_conj_status( *x ); \
	conj_t    conjy     = bli_obj_conj_status( *y ); \
	dim_t     n         = bli_obj_vector_dim( *x ); \
	void*     buf_x     = bli_obj_buffer_at_off( *x ); \
	inc_t     inc_x     = bli_obj_vector_inc( *x ); \
	void*     buf_y     = bli_obj_buffer_at_off( *y ); \
	inc_t     inc_y     = bli_obj_vector_inc( *y ); \
	void*     buf_rho   = bli_obj_buffer_at_off( *rho ); \
\
	if ( bli_error_checking_is_enabled() ) \
	    PASTEMAC(opname,_check)( x, y, rho ); \
\
	/* Invoke the void pointer-based function. */ \
	bli_call_ft_9 \
	( \
	   dt, \
	   opname, \
	   conjx, \
	   conjy, \
	   n, \
	   buf_x, inc_x, \
	   buf_y, inc_y, \
	   buf_rho, \
	   cntx  \
	); \
}

GENFRONT( dotv )


#undef  GENFRONT
#define GENFRONT( opname ) \
\
void PASTEMAC(opname,EX_SUF) \
     ( \
       obj_t*  alpha, \
       obj_t*  x, \
       obj_t*  y, \
       obj_t*  beta, \
       obj_t*  rho  \
       BLIS_OAPI_CNTX_PARAM  \
     ) \
{ \
	BLIS_OAPI_CNTX_DECL \
\
	num_t     dt        = bli_obj_datatype( *x ); \
\
	conj_t    conjx     = bli_obj_conj_status( *x ); \
	conj_t    conjy     = bli_obj_conj_status( *y ); \
	dim_t     n         = bli_obj_vector_dim( *x ); \
	void*     buf_x     = bli_obj_buffer_at_off( *x ); \
	inc_t     inc_x     = bli_obj_vector_inc( *x ); \
	void*     buf_y     = bli_obj_buffer_at_off( *y ); \
	inc_t     inc_y     = bli_obj_vector_inc( *y ); \
	void*     buf_rho   = bli_obj_buffer_at_off( *rho ); \
\
	void*     buf_alpha; \
	void*     buf_beta; \
\
	obj_t     alpha_local; \
	obj_t     beta_local; \
\
	if ( bli_error_checking_is_enabled() ) \
	    PASTEMAC(opname,_check)( alpha, x, y, beta, rho ); \
\
	/* Create local copy-casts of scalars (and apply internal conjugation
	   as needed). */ \
	bli_obj_scalar_init_detached_copy_of( dt, BLIS_NO_CONJUGATE, \
	                                      alpha, &alpha_local ); \
	bli_obj_scalar_init_detached_copy_of( dt, BLIS_NO_CONJUGATE, \
	                                      beta, &beta_local ); \
	buf_alpha = bli_obj_buffer_for_1x1( dt, alpha_local ); \
	buf_beta  = bli_obj_buffer_for_1x1( dt, beta_local ); \
\
	/* Invoke the void pointer-based function. */ \
	bli_call_ft_11 \
	( \
	   dt, \
	   opname, \
	   conjx, \
	   conjy, \
	   n, \
	   buf_alpha, \
	   buf_x, inc_x, \
	   buf_y, inc_y, \
	   buf_beta, \
	   buf_rho, \
	   cntx  \
	); \
}

GENFRONT( dotxv )


#undef  GENFRONT
#define GENFRONT( opname ) \
\
void PASTEMAC(opname,EX_SUF) \
     ( \
       obj_t*  x  \
       BLIS_OAPI_CNTX_PARAM  \
     ) \
{ \
	BLIS_OAPI_CNTX_DECL \
\
	num_t     dt        = bli_obj_datatype( *x ); \
\
	dim_t     n         = bli_obj_vector_dim( *x ); \
	void*     buf_x     = bli_obj_buffer_at_off( *x ); \
	inc_t     inc_x     = bli_obj_vector_inc( *x ); \
\
	if ( bli_error_checking_is_enabled() ) \
	    PASTEMAC(opname,_check)( x ); \
\
	/* Invoke the void pointer-based function. */ \
	bli_call_ft_4 \
	( \
	   dt, \
	   opname, \
	   n, \
	   buf_x, inc_x, \
	   cntx  \
	); \
}

GENFRONT( invertv )


#undef  GENFRONT
#define GENFRONT( opname ) \
\
void PASTEMAC(opname,EX_SUF) \
     ( \
       obj_t*  alpha, \
       obj_t*  x  \
       BLIS_OAPI_CNTX_PARAM  \
     ) \
{ \
	BLIS_OAPI_CNTX_DECL \
\
	num_t     dt        = bli_obj_datatype( *x ); \
\
	/* conj_t    conjalpha = bli_obj_conj_status( *alpha ); */ \
	dim_t     n         = bli_obj_vector_dim( *x ); \
	void*     buf_x     = bli_obj_buffer_at_off( *x ); \
	inc_t     inc_x     = bli_obj_vector_inc( *x ); \
\
	void*     buf_alpha; \
\
	obj_t     alpha_local; \
\
	if ( bli_error_checking_is_enabled() ) \
	    PASTEMAC(opname,_check)( alpha, x ); \
\
	/* Create local copy-casts of scalars (and apply internal conjugation
	   as needed). */ \
	bli_obj_scalar_init_detached_copy_of( dt, BLIS_NO_CONJUGATE, \
	                                      alpha, &alpha_local ); \
	buf_alpha = bli_obj_buffer_for_1x1( dt, alpha_local ); \
\
	/* Invoke the void pointer-based function. */ \
	bli_call_ft_6 \
	( \
	   dt, \
	   opname, \
	   BLIS_NO_CONJUGATE, /* internal conjugation applied during copy-cast. */ \
	   n, \
	   buf_alpha, \
	   buf_x, inc_x, \
	   cntx  \
	); \
}

GENFRONT( scalv )
GENFRONT( setv )


#undef  GENFRONT
#define GENFRONT( opname ) \
\
void PASTEMAC(opname,EX_SUF) \
     ( \
       obj_t*  x, \
       obj_t*  y  \
       BLIS_OAPI_CNTX_PARAM  \
     ) \
{ \
	BLIS_OAPI_CNTX_DECL \
\
	num_t     dt        = bli_obj_datatype( *x ); \
\
	dim_t     n         = bli_obj_vector_dim( *x ); \
	void*     buf_x     = bli_obj_buffer_at_off( *x ); \
	inc_t     inc_x     = bli_obj_vector_inc( *x ); \
	void*     buf_y     = bli_obj_buffer_at_off( *y ); \
	inc_t     inc_y     = bli_obj_vector_inc( *y ); \
\
	if ( bli_error_checking_is_enabled() ) \
	    PASTEMAC(opname,_check)( x, y ); \
\
	/* Invoke the void pointer-based function. */ \
	bli_call_ft_6 \
	( \
	   dt, \
	   opname, \
	   n, \
	   buf_x, inc_x, \
	   buf_y, inc_y, \
	   cntx  \
	); \
}

GENFRONT( swapv )


#endif

