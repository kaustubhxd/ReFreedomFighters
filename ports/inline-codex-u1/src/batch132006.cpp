#include "ff.h"
template<class T> static T& at6(void* p,u32 n){return *(T*)((u8*)p+n);}
static void THISCALL effects(u8* self){
 s32 idx=at6<s32>(self,0x2d);if(idx==-1)return;
 u8* fx=at6<u8*>(self,0x63f4);u8* info=at6<u8*>(self,8);
 bool special=fx && at6<u32>(self,0x39)==1;
 if(special){
  for(int off=0x18;off<0x34;off+=4)at6<u32>(fx,off)=0;
  at6<u32>(fx,0x34)=0x3f800000;
 }
 if(at6<u32>(info,0x8065)){
  s32 count=at6<s32>(info,0x8071+0x110*idx);
  if(count){
   for(s32 i=0;i<count;++i){
    u8* entry=info+0x8079+0x110*idx+8*i;u32 kind=at6<u32>(entry,4);
    if(kind==1){
     float x=G(float,0x678858)-at6<float>(at6<void*>(entry,0),0xc);
     if(special){
      at6<u32>(fx,0x24)=0x3e800000;at6<u32>(fx,0x28)=0x40000000;at6<u32>(fx,0x2c)=0x3f800000;
      float y=(float)at6<s32>(fx,0x20)-x*G(float,0x6a3c64);
      at6<s32>(fx,0x20)=_mm_cvttss_si32(_mm_set_ss(y));
     }else{
      double y=(double)x*G(double,0x68c740);y=y*G(double,0x693d60);
      at6<float>(self,0x63d7)=(float)((double)at6<float>(self,0x63d7)-y);
     }
    }else if(special && kind==8){at6<u32>(fx,0x30)=0;at6<u32>(fx,0x34)=0x3f800000;}
   }
   if(!special && 0.0f>at6<float>(self,0x63d7))at6<u32>(self,0x63d7)=0;
  }
 }
 if(special)vcall<void>(at6<void*>(self,0x63f4),8);
}
PCREG(54c970,effects);
