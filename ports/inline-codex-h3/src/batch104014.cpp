#include "ff.h"
extern "C" void FASTCALL ext_43e920(float*,float*,float*);
static u8 STDCALL three_vector_angle_test(float* origin,float* a,float* b,float* c,float threshold) {
  float da[3],db[3],dc[3];
  ext_43e920(da,a,origin);
  ext_43e920(db,b,origin);
  ext_43e920(dc,c,origin);
  float aa=da[0]*da[0]; aa=aa+da[1]*da[1]; aa=aa+da[2]*da[2];
  float bb=db[0]*db[0]; bb=bb+db[1]*db[1]; bb=bb+db[2]*db[2];
  float cc=dc[0]*dc[0]; cc=cc+dc[1]*dc[1]; cc=cc+dc[2]*dc[2];
  const float eps=G(float,0x67d9fc);
  if(cc<eps) return 1;
  if(aa>=eps) {
    float dot=dc[0]*da[0]; dot=dot+dc[1]*da[1]; dot=dot+dc[2]*da[2];
    float q=(dot*dot)/aa; q=q/cc;
    if(threshold>q) return 0;
  }
  float dot=db[0]*dc[0]; dot=dot+db[1]*dc[1]; dot=dot+db[2]*dc[2];
  if(bb<eps) return 1;
  float q=(dot*dot)/bb; q=q/cc;
  if(threshold>q) return 0;
  return 1;
}
PCREG(460870,three_vector_angle_test);
