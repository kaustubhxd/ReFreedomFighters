#include "ff.h"
extern "C" void FASTCALL ext_451890(void*,void*,float);
extern "C" void STDCALL randomize_shape_point(u8* node,float* point){
 u8* data=*(u8**)(node+8);float dims[3]={*(float*)(data+0x40),*(float*)(data+0x44),*(float*)(data+0x48)};
 float basis[9];vcall<void>(node,0x80,basis,point);
 float factors[3];
 for(u32 i=0;i<3;++i){
  long double r=vcall<long double>(G(void*,0x70039c),0x1c0,0x6b410cu,0x8du+i);
  factors[i]=(float)((r-(long double)G(float,0x67a6ac))*(long double)dims[i]);
 }
 ext_451890(point,basis+6,factors[0]+factors[0]);
 ext_451890(point,basis+3,factors[1]+factors[1]);
 ext_451890(point,basis,factors[2]+factors[2]);
}
PCREG(5c4a00,randomize_shape_point);
