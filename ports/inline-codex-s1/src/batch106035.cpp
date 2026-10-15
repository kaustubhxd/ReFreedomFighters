#include "ff.h"
extern "C" u32 THISCALL ext_5de900(void*,const u32*);
extern "C" double VECTORCALL ext_634db8(double);
static float score35(u32 now,u8* record){
 float elapsed=(float)(s32)(now-*(u32*)(record+0xc));
 elapsed=elapsed*G(float,0x6785e4);elapsed=elapsed*G(float,0x6b724c);elapsed=elapsed/(*(float*)(record+0x14));
 return (float)(ext_634db8((double)elapsed)*(double)*(float*)(record+0x18));
}
static u32 THISCALL replace_record(u8* me,const u32* source){
 u32 n=*(u32*)(me+0x48);if(n<5)return ext_5de900(me+0x48,source);
 u32 now=*(u32*)(G(u8*,0x70039c)+0x40);u8* base=me+0x4c;u8* best=base;
 float minimum=score35(now,best);
 for(u32 i=1;i<n;i++){
  u8* candidate=base+0x28*i;float value=score35(now,candidate);
  if(minimum>value){best=candidate;minimum=value;}
 }
 for(int i=0;i<10;i++)*(u32*)(best+4*i)=source[i];
 return source[9];
}
PCREG(5de090,replace_record);
