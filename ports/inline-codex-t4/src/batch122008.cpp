#include "ff.h"
extern "C" u8* ext_5fa630();
static void THISCALL fn5f3c90(u8* s,u8* a){
 *(float*)(a+4)=vcall<float>(ext_5fa630(),4);
 u8* start=s+0xbe;u8* cur=*(u8**)(s+0xb6);
 if(cur!=start&&*(u32*)a==1&&*(u32*)(cur-20)==1&&*(u16*)(a+12)==*(u16*)(cur-8)){
  ++*(u32*)(cur-12);return;
 }
 *(u32*)(a+8)=1;
 cur=*(u8**)(s+0xb6);
 if(*(u32*)cur==3){typedef void(*Free)(u32);(*(Free*)0x6762ec)(*(u32*)(cur+12));}
 cur=*(u8**)(s+0xb6);
 for(u32 i=0;i<20;++i)cur[i]=a[i];
 *(u8**)(s+0xb6)+=20;
 if(*(u8**)(s+0xb6)==s + 0xbe + 20*(*(u32*)(s+0xba))) *(u8**)(s+0xb6)=start;
}
PCREG(5f3c90,fn5f3c90);
