#include "ff.h"
extern "C" float THISCALL ext_4e5e80(void*);
extern "C" u32 THISCALL ext_4e5e60(void*);
extern "C" void THISCALL ext_4e0d00(float*,float);
extern "C" void THISCALL ext_4e0d80(float*,float);
extern "C" void THISCALL ext_4db2a0(void*,float*);
extern "C" void ext_633654(u32);
extern "C" double VECTORCALL ext_634d7c(double);
static void THISCALL load_rotation(u8* me,void* src) {
 for(int i=0;i<3;i++)*(float*)(me+0x4c+4*i)=ext_4e5e80(src);
 ext_4e0d00((float*)(me+0x4c),bitsf(0x3c8efa35));
 u8 type=**(u8**)src;
 if(type!=0xff && (type&0x3f)==3 && !ext_4e5e60(src))vcall<void>(me,0x68,0x10,0);
 *(u16*)(me+0x58)=0;me[0x5a]=0;
 void* tab=*(void**)(G(u8*,0x70039c)+0x9b);
 *(u16*)(me+0x48)=(u16)vcall<u32>(tab,0x114,0x6954c0,0,0x695494,0x10e);
 tab=*(void**)(G(u8*,0x70039c)+0x9b);
 *(u16*)(me+0x4a)=(u16)vcall<u32>(tab,0x114,0x6954d4,0,0x695494,0x10f);
 for(int i=0;i<3;i++)*(u32*)(me+0x77+4*i)=*(u32*)(me+0x4c+4*i);
 ext_4e0d80((float*)(me+0x77),1.0f);
 float m[9];ext_4db2a0(*(void**)(*(u8**)(me+0x44)+8),m);
 float x=*(float*)(me+0x77),y=*(float*)(me+0x7b),z=*(float*)(me+0x7f);
 *(float*)(me+0x63)=(y*m[4]+x*m[3])+z*m[5];
 *(float*)(me+0x67)=(y*m[1]+x*m[0])+z*m[2];
 *(float*)(me+0x5f)=(y*m[7]+x*m[6])+z*m[8];
 for(int i=0;i<3;i++) {
  float f=*(float*)(me+0x5f+4*i);
  double abs=__builtin_fabs((double)f);
  float out=0.0f;
  if(G(double,0x678610)>abs)out=(float)ext_634d7c((double)(G(float,0x678858)-f*f));
  *(float*)(me+0x6b+4*i)=out;
 }
 ext_633654(0);
}
PCREG(4c9330,load_rotation);
