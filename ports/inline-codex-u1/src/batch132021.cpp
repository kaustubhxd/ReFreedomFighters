#include "ff.h"
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
static void THISCALL move21(u8* self){
 u32 now=*(u32*)(G(u8*,0x70039c)+0x40);
 s32 prior=_mm_cvttss_si32(_mm_set_ss(*(float*)(self+0x74)*G(float,0x678620)));
 s32 elapsed=(s32)((now-(u32)prior)*10u);
 float dt=(float)elapsed*G(float,0x6785e4);
 for(int k=0;k<3;++k){float amount=(float)(*(u32*)(self+0x70));float* p=(float*)(self+0x4c+4*k);*p=(amount*(*(float*)(self+0x64+4*k)))*dt+*p;}
 vcall<void>(*(void**)(self+0x48),0x70,self+0x4c);
 float diff[3];ext_43e920(diff,self+0x4c,self+0x58);
 float dot=(*(float*)(self+0x68))*diff[1]+diff[0]*(*(float*)(self+0x64));dot=dot+(*(float*)(self+0x6c))*diff[2];
 if(dot>G(float,0x6785d0)){
  for(int k=0;k<3;++k)*(u32*)(self+0x4c+4*k)=*(u32*)(self+0x58+4*k);
  vcall<void>(self,0x84,self+0x58);vcall<void>(self,0x88);
 }
 *(float*)(self+0x74)=(float)(*(s32*)(G(u8*,0x70039c)+0x40))*G(float,0x6785e4);
}
PCREG(4a3860,move21);
