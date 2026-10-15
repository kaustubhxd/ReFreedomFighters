#include "ff.h"
static void* table22(){return *(void**)(G(u8*,0x70039c)+0x9b);}
static void THISCALL load_effect(u8* me){
 u32 id=0;void* cfg=vcall<void*>(table22(),0x138);vcall<void>(cfg,0x88,0x681320,&id);
 *(void**)(me+0x114)=vcall<void*>(table22(),0x58,id);
 for(int i=0;i<2;i++){
  cfg=vcall<void*>(table22(),0x138);u32 raw=0;vcall<void>(cfg,0x84,i?0x6954f8:0x6954e8,&raw);
  *(u32*)(me+0x118+4*i)=raw;
 }
 cfg=vcall<void*>(table22(),0x138);s32* rgb=vcall<s32*>(cfg,0x9c,0x69c218,4);
 for(int i=0;i<3;i++)*(float*)(me+0x120+4*i)=(float)rgb[i]*G(float,0x697890);
 u32 key=*(u32*)(*(u8**)(me+0x114)+0x676);
 void* target=vcall<void*>(table22(),0x58,key);*(void**)(me+0x134)=target;
 *(u32*)(me+0x130)=vcall<u32>(target,0x100,0x67d9e8);
}
PCREG(5de260,load_effect);
