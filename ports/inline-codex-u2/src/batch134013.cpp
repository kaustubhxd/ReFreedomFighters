#include "ff.h"
extern "C" void FASTCALL ext_4e0d40(float*,const float*,float);
extern "C" void FASTCALL ext_43e920(float*,const float*,const float*);
extern "C" void FASTCALL ext_43e960(float*,const float*);
extern "C" void THISCALL ext_4e0d80(float*,float);
extern "C" void FASTCALL ext_43e8e0(float*,const float*,const float*);
extern "C" void FASTCALL ext_4de040(float*,const float*,const float*);
static void THISCALL fn4c9780(u8* s,float* out){
 for(u32 i=0;i<3;++i){
  const float* basis=(float*)(s+0x77);float base[3],diff[3];float* axis=out+(2-i)*3;
  ext_4e0d40(base,basis,G(float,s+0x5f+i*4));ext_43e920(diff,axis,base);
  float sum=diff[0]*diff[0]+diff[1]*diff[1];sum=sum+diff[2]*diff[2];float len=(float)crt::sqrt((double)sum);
  if(len>0){float dot=basis[0]*diff[0]+basis[1]*diff[1];dot=dot+basis[2]*diff[2];float projection[3];ext_4e0d40(projection,basis,dot/len);ext_43e960(diff,projection);}
  ext_4e0d80(diff,G(float,s+0x6b+i*4));ext_43e8e0(axis,diff,base);
 }
 ext_4de040(out,out,out+3);
}
PCREG(4c9780,fn4c9780);
