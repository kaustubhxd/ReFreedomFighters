#include "ff.h"
extern "C" float STDCALL ext_4de000(float,float);
extern "C" void THISCALL ext_5c3560(void*,u8,u8);
static int truncf(float x){return _mm_cvtt_ss2si(_mm_set_ss(x));}
static float next(u8* me,u32 off){s32 now=*(s32*)(G(u8*,0x70039c)+0x40);s32 delta=truncf(*(float*)(me+off)*G(float,0x67862c));return (float)(s32)((u32)now-(u32)delta)*G(float,0x6785e4);}
static void THISCALL toggle(u8* me){
 u8* sys=G(u8*,0x70039c);s32 now=*(s32*)(sys+0x40);
 if(now<truncf((*(float*)(me+0x115)+*(float*)(me+0xfa))*1024.0f))return;
 if(me[0x125]){
  if(now<truncf(*(float*)(me+0x11d)*1024.0f)){
   *(float*)(me+0x121)=*(float*)(sys+0x48)+*(float*)(me+0x121);float r=ext_4de000(bitsf(0x3d4ccccd),0.25f);
   if(*(float*)(me+0x121)>r){u8 flag=!me[0x114];*(u32*)(me+0x121)=0;me[0x114]=flag;ext_5c3560(me,flag,0);}
  }else{me[0x114]=0;ext_5c3560(me,0,1);me[0x125]=0;*(float*)(me+0x119)=next(me,0x102);}
 }else{
  if(now<=truncf(*(float*)(me+0x119)*1024.0f))return;
  u8 flag=!me[0x114];me[0x114]=flag;ext_5c3560(me,flag,1);
  if(!me[0x114]){me[0x125]=1;*(float*)(me+0x11d)=next(me,0x106);}
  else *(float*)(me+0x119)=next(me,0xfe);
 }
}
PCREG(5c3140,toggle);
