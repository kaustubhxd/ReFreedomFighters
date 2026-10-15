#include "ff.h"
extern "C" void THISCALL ext_4daf90(void*,float*);
extern "C" void THISCALL ext_4db7c0(void*,float*);
extern "C" void THISCALL ext_4e0d00(float*,float);
extern "C" void FASTCALL ext_4e0980(float*,const float*);
static void FASTCALL fn53fd10(u8* s,float* a,float* b,float* c,float* d){
 float pos[3],size[3];if(G(u32,G(u8*,s+0xc)+0x23)&0x100000)vcall<void>(s,0x2bc,pos,size,1u);
 else{ext_4daf90(G(void*,s+8),pos);ext_4db7c0(G(void*,s+8),size);}
 ext_4e0d00(size,bitsf(0x3c23d70a));
 for(int i=0;i<3;++i){if(G(float,0x67a288)>size[i])size[i]=G(float,0x67a288);if(size[i]>G(float,0x680a60))size[i]=2;}
 ext_4e0980(a,size);ext_4e0980(b,size);ext_4e0980(c,size);ext_4e0980(d,size);
}
PCREG(53fd10,fn53fd10);
