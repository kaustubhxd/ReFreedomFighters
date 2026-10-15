#include "ff.h"
extern "C" void THISCALL ext_4e73b0(void*,void*,void*,void*,float,float);
extern "C" void ext_633654(u32);
static u32 THISCALL restore_transform(u8* me,u32 id,u32 skip){
 if((u16)id==*(u16*)(me+0x115)){
  me[0x10e]=0;
  for(int i=0;i<6;i++)*(u32*)(me+0xd2+4*i)=*(u32*)(me+0x11b+4*i);
  u32* ticks=(u32*)(G(u8*,0x70039c)+0x40);
  if(me+0xf6!=(u8*)ticks)*(u32*)(me+0xf6)=*ticks;
  float zero[3]={0,0,0};
  if(!skip)vcall<void>(*(void**)(me+0x44),0x74,me+0x90,me+0x84);
  vcall<void>(*(void**)(me+0x44),0x84,zero);
  u32 copy[3];for(int i=0;i<3;i++)copy[i]=*(u32*)(me+0xd2+4*i);
  vcall<void>(*(void**)(me+0x44),0x88,copy);
  float seconds=(float)*(s32*)(me+0xf6)*G(float,0x6785e4);
  ext_4e73b0(me+0x48,zero,copy,me+0xde,*(float*)(me+0xea),seconds);
 }
 ext_633654(0);return 0;
}
PCREG(4a64c0,restore_transform);
