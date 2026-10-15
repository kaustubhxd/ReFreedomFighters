#include "ff.h"
extern "C" u32 VECTORCALL ext_633910(float);
static void STDCALL colors(u8* input){
 u32 alpha=ext_633910((G(float,0x678858)-G(float,input+0x40))*G(float,0x68af18));if(alpha>255)alpha=255;alpha<<=24;
 for(u32 i=0;i<G(u32,input+0x44);++i){u32 id=G(u32,input+0x58+4*i);void* table=G(void*,G(u32,G(u32,0x70039c)+0x1aa3)+0x18);
 u32 n=vcall<u32>(table,0xf4,id)*3;u32 buffer[96];for(u32 j=0;j<n;++j)buffer[j]=alpha+0xffffff;
 table=G(void*,G(u32,G(u32,0x70039c)+0x1aa3)+0x18);vcall<void>(table,0x70,id,2,(void*)buffer,n);
 }
}
PCREG(65f210,colors);
