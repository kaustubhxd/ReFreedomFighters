#include "ff.h"
extern "C" void FASTCALL ext_441940(void*,void*);
static void THISCALL spawnEntry(u8* s,void* value,s32 index,u32 param){
 u8* entry=*(u8**)(s+0x4c)+(u32)index*25;
 float matrix[9],pos[3];vcall<void>(*(void**)(s+0x44),0x80,matrix,pos);
 void* instance=*(void**)(entry+4);
 if(!instance){
  u8* table=*(u8**)(G(u8*,0x70039c)+0x9b);
  void* factory=vcall<void*>(table,0x58,*(u32*)(s+0x48));
  instance=vcall<void*>(factory,0x1bc,*(u32*)(table+0xadc),matrix,value,0u,0u,0u,0u);
  *(void**)(entry+4)=instance;
 }else{
  vcall<void>(instance,0x2c);
  vcall<void>(*(void**)(entry+4),0x7c,matrix,value);
 }
 if(!*(u32*)(entry+4))return;
 *(u32*)(entry+8)=param;entry[0x18]=0;
 float randoms[3];
 for(int i=0;i<3;++i){
  float centered=(float)(vcall<long double>(G(void*,0x70039c),0x1c0,0x6b410cu,0xe2u+(u32)i)-(long double)G(float,0x67a6ac));
  randoms[i]=(centered+centered)*(*(float*)(s+0x70+4*i));
 }
 for(int i=0;i<3;++i)*(float*)(entry+0xc+4*i)=randoms[i];
 ext_441940(entry+0xc,s+0x64);
 u8* clock=G(u8*,0x70039c)+0x40;
 if(entry!=clock)*(u32*)entry=*(u32*)clock;
}
PCREG(5c4cc0,spawnEntry);
