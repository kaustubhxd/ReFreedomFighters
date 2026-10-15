#include "ff.h"
extern "C" void THISCALL ext_562260(void*);
extern "C" void THISCALL ext_4f9680(void*,u32);
extern "C" void THISCALL ext_575d00(void*);
static void THISCALL selectRegion(u8* s){
 if(!s[0x88])return;
 ext_562260(s);
 if(*(u32*)(s+0xdc)!=2 || s[0x21b])return;
 void* actor=vcall<void*>(s,0x84);float pos[3];vcall<void>(actor,0x308,pos);
 if(*(float*)(s+0x21c)!=pos[0] || *(float*)(s+0x220)!=pos[1]){
  *(float*)(s+0x21c)=pos[0];*(float*)(s+0x220)=pos[1];
  u32 selected=0;float best=0;
  for(int i=0;i<5;++i){u8* region=s+0x224+0x24*i;
   float priority=*(float*)(region+0xc);
   if(*(u32*)region && priority>best && pos[0]>*(float*)(region+4) && *(float*)(region+0x10)>pos[0] && pos[1]>*(float*)(region+8) && *(float*)(region+0x14)>pos[1]){selected=*(u32*)region;best=priority;}
  }
  if(selected)vcall<void>(vcall<void*>(s,0x84),0x2ec,selected);
 }
 u32 current=vcall<u32>(vcall<void*>(s,0x84),0x2f0);
 if(*(u32*)(s+0x206)!=current){
  s[0x216]=0;
  for(int i=0;i<5;++i)if(*(u32*)(s+0x224+0x24*i) && *(u32*)(s+0x224+0x24*i)==current){
   *(u32*)(s+0x20a)=current;s[0x216]=1;ext_4f9680((void*)0x700e24,0);
  }
 }
 *(u32*)(s+0x206)=vcall<u32>(vcall<void*>(s,0x84),0x2f0);
 ext_575d00(s);
}
PCREG(574e70,selectRegion);
