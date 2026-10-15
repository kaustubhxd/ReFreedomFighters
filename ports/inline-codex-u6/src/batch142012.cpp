#include "ff.h"
static void THISCALL event(u8* me,s32 key,u32 flags){
 void* ob=vcall<void*>(G(void*,0x70039c),0x1b0);
 if(*(u32*)(me+0x137))return;
 if(ob){
  if((flags&0xff0000)==0x290000 && !(flags&0x40000000)){me[0x80]=1;return;}
  if(vcall<u8>(ob,0xc)){vcall<void>(ob,0x10,key,flags);return;}
 }
 if(key>=256 || (u8)key==1)return;
 u32 a=(u8)key*5,b=((flags>>16)&0x1ff)*5;u8* sys=G(u8*,0x70039c);
 sys[a+0xa0b]|=0x80;if(!sys[0x6e])sys[b+0xf0b]|=0x80;
 if(flags&0x40000000)return;
 sys[a+0xa0b]|=0x20;if(!sys[0x6e]){sys[b+0xf0b]|=0x20;sys[b+0xf0b]|=0x40;}
 s32 old=_mm_cvtt_ss2si(_mm_set_ss(*(float*)(sys+a+0xa07)*1024.0f));s32 elapsed=(s32)((u32)*(s32*)(sys+0x40)-(u32)old);
 if(elapsed<256){sys[a+0xa0b]|=0x10;if(!sys[0x6e])sys[b+0xf0b]|=0x10;}
 else{sys[a+0xa0b]&=0xef;if(!sys[0x6e])sys[b+0xf0b]&=0xef;}
 *(float*)(sys+a+0xa07)=(float)*(s32*)(sys+0x40)*G(float,0x6785e4);
 if(!sys[0x6e])*(float*)(sys+b+0xf07)=(float)*(s32*)(sys+0x40)*G(float,0x6785e4);
}
PCREG(654a60,event);
