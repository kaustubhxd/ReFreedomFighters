#include "ff.h"
extern "C" void THISCALL ext_5b0cc0(void*,void*,void*);
extern "C" void THISCALL ext_5b10f0(void*);
extern "C" u8 THISCALL ext_5c2d90(void*,u32,void*,void*);
extern "C" u32 THISCALL ext_5ade30(void*);
extern "C" u32 THISCALL ext_5acfa0(void*);
extern "C" void THISCALL choose_inventory(u8* me,u32* output){
 u32 scratch[8];ext_5b0cc0(me+0x4b8,output,scratch);ext_5b10f0(me+0x4b8);
 if(me[2]==0x38){
  long double random=vcall<long double>(G(void*,0x70039c),0x1c0,0x6b0df8u,0x1e2u);
  float f=(float)(random*(long double)G(float,0x680a68)+(long double)G(float,0x678858));
  s32 count=_mm_cvttss_si32(_mm_set_ss(f));
  u32 entry[3],extra;
  for(s32 i=0;i<count;++i){
   if(ext_5c2d90(me+0x92,0x6b0ea0,entry,&extra))output[i+1]=entry[1];
   output[0]=entry[0];output[9]=count;
  }
 }else if(output[9])output[0]=ext_5ade30(me);
 else{
  u32 entry[3],extra;u32 name=ext_5acfa0(me+0x35a);
  if(ext_5c2d90(me+0x92,name,entry,&extra)){output[0]=entry[0];output[9]=1;output[1]=entry[1];}
 }
}
PCREG(5adef0,choose_inventory);
