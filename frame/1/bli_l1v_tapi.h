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
// Generate prototypes for level-1v operations.
//

#undef  addv_ker_name
#define addv_ker_name       addv

#undef  axpyv_ker_name
#define axpyv_ker_name      axpyv

#undef  copyv_ker_name
#define copyv_ker_name      copyv

#undef  dotv_ker_name
#define dotv_ker_name       dotv

#undef  dotxv_ker_name
#define dotxv_ker_name      dotxv

#undef  invertv_ker_name
#define invertv_ker_name    invertv

#undef  scalv_ker_name
#define scalv_ker_name      scalv

#undef  scal2v_ker_name
#define scal2v_ker_name     scal2v

#undef  setv_ker_name
#define setv_ker_name       setv

#undef  subv_ker_name
#define subv_ker_name       subv

#undef  swapv_ker_name
#define swapv_ker_name      swapv


// Include the level-1v kernel API template.

#include "bli_l1v_ker.h"

