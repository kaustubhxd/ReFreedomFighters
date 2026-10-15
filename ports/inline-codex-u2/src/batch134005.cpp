#include "ff.h"
static float envelope(u8* p,float t){
 float a=G(float,p),b=G(float,p+4),c=G(float,p+8),d=G(float,p+12);
 float high=G(float,p+16),low=G(float,p+20),offset=G(float,p+24);
 if(a>t)return (high*t)/a-offset;
 t=t-a;
 if(b>t){float f=t/b;return (G(float,0x678858)-f)*high+low*f-offset;}
 t=t-b;
 if(c>t)return low-offset;
 t=t-c;
 if(d>t){float f=t/d;return (G(float,0x678858)-f)*low-offset;}
 return 0;
}
static void THISCALL fn43d0f0(u8* self){
 for(s32 i=0;i<G(s32,self+0x80);++i){
  u8* entry=self+i*24;u32 type=G(u32,entry+8);if(type-1>10)continue;
  u32 diff=G(u32,G(u8*,0x70039c)+0x30)-G(u32,entry+12);float t=float((s32)diff)*G(float,0x6785e4);
  u8* p=self+type*0x3a+0x91;
  G(float,entry+0x18)=G(u8,p+28)?envelope(p,t):0;
  G(float,entry+0x1c)=G(u8,p+57)?envelope(p+29,t):0;
 }
}
PCREG(43d0f0,fn43d0f0);
