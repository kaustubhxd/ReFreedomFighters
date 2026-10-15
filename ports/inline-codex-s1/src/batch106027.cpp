#include "ff.h"
extern "C" long double THISCALL ext_5162d0(void*);
extern "C" void THISCALL ext_525640(void*,void*,void*);
static void THISCALL average_height(u8* me){
 *(float*)(me+4)=0.0f;
 for(int i=0;i<*(s32*)(me+0x8c);i++)*(float*)(me+4)=(float)(ext_5162d0(me+0xbd+0xde*i)+(long double)*(float*)(me+4));
 for(int i=0;i<*(s32*)(me+0x90);i++)*(float*)(me+4)=(float)(ext_5162d0(me+0x435+0xde*i)+(long double)*(float*)(me+4));
 s32 total=(s32)(*(u32*)(me+0x90)+*(u32*)(me+0x8c));
 float avg=*(float*)(me+4)/(float)total;*(float*)(me+4)=avg;
 if(avg>*(float*)(me+0x64)+G(float,0x69eb5c)){
  void* sink=vcall<void*>(G(void*,0x700390),0x20,0x6a0918,0x386);
  typedef void(*Print)(void*,u32);(*(Print*)(*(u8**)sink+0x30))(sink,0x6a09a8);
  u32 v[3]={*(u32*)me,*(u32*)(me+0x64),*(u32*)(me+8)};
  ext_525640(me,v,me+0x4c);
 }
}
PCREG(526df0,average_height);
