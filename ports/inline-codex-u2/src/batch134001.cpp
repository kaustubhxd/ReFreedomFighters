#include "ff.h"
extern "C" void FASTCALL ext_4de420(float*,const float*);
extern "C" void FASTCALL ext_441970(float*,const float*,const float*);
extern "C" void FASTCALL ext_441940(float*,const float*);
static void THISCALL fn462640(u8* s,void* a,void* b,u32 c,u32 d){
  u8* base=G(u8*,s+8);
  if(!G(u32,base+0x6c)) return;
  vcall<void>(a,0x54,base,c,d,G(void*,s+0x6c));
  if(!(G(u8,G(u8*,s+0x1c)+4)&8)) return;
  float* matrix=vcall<float*>(G(void*,s+0x6c),0x58,s);
  u8* bounds=vcall<u8*>(s,0x2cc);
  u32 n=G(u32,s+0x20);
  for(u32 i=0;i<n;++i){
    if(!(G(u8,G(u8*,s+0x1c)+i*24+4)&8)) continue;
    float origin[3], extent[3];
    for(u32 j=0;j<3;++j){origin[j]=i?G(float,bounds+i*48+j*4):0; extent[j]=i?G(float,bounds+i*48+16+j*4):(j==2?10.0f:2.0f);}
    float m[9],p[3]; ext_4de420(m,matrix); ext_441970(p,origin,m); ext_441940(p,matrix+9);
    vcall<void>(s,0x98,m,p); vcall<void>(b,0x94,m,p); vcall<void>(a,0x6c,m,p,extent); vcall<void>(a,0x80,m,p,b);
    matrix+=12;
  }
}
PCREG(462640,fn462640);
