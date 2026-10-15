#include "ff.h"
extern "C" void THISCALL ext_5c9910(void*);
extern "C" float FASTCALL ext_4e0870(float*,float*);
static u8 THISCALL collisions(u8* me){
 ext_5c9910(me);s32 index=*(s32*)(me+0x68);*(u32*)(me+0x64)=0xffffffff;
 *(u32*)(me+index*0x82+0xa0)=0x3f800000;
 void* world=*(void**)(*(u8**)(G(u8*,0x70039c)+0x9b)+0xadc);
 u8 hit=vcall<u8>(world,0x2e0,me+index*0x82+0x6c,0u,0x40u,0x200000u,1u,0u);
 index=*(s32*)(me+0x68);
 if(hit)*(float*)(me+index*0x82+0xd9)=ext_4e0870((float*)(me+index*0x82+0x94),(float*)(me+index*0x82+0x6c));
 else *(u32*)(me+index*0x82+0xd9)=0x47c35000;
 ++*(s32*)(me+0x68);if(*(s32*)(me+0x68)>=5)*(u32*)(me+0x68)=1;
 *(u32*)(me+0xa0)=0x3f800000;
 world=*(void**)(*(u8**)(G(u8*,0x70039c)+0x9b)+0xadc);
 hit=vcall<u8>(world,0x2e0,me+0x6c,0u,0x40u,0x200000u,1u,0u);me[0x30b]=hit;
 if(hit)*(float*)(me+0xd9)=ext_4e0870((float*)(me+0x94),(float*)(me+0x6c));else *(u32*)(me+0xd9)=0x47c35000;
 if(*(u32*)(me+0x68)==1 || me[0x30b]){
  float best=G(float,0x68af2c);me[0x30a]=0;
  for(int i=0;i<5;i++){float d=*(float*)(me+0xd9+i*0x82);if(best>d){me[0x30a]=1;*(u32*)(me+0x64)=i;best=d;}}
  if(me[0x30a] && *(float*)(me+0x2f6)+G(float,0x679540)>best)vcall<void>(me,0xc4);
 }
 return me[0x30a];
}
PCREG(5c9ba0,collisions);
