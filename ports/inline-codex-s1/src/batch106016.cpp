#include "ff.h"
extern "C" void THISCALL ext_6352f0(void*,u32*);
extern "C" float THISCALL ext_4e5e80(u32*);
extern "C" u32 THISCALL ext_4e5e40(u32*);
extern "C" u32 THISCALL ext_4e5e60(u32*);
static u8 THISCALL read_fields(u8* me,void* stream){
 u32 value=0;*(u32*)(me+4)&=~0x40u;
 ext_6352f0(me,&value);
 *(float*)(me+0x4a)=ext_4e5e80(&value);
 *(u16*)(me+0x52)=(u16)ext_4e5e40(&value);
 me[0x54]=ext_4e5e60(&value)!=0;
 *(float*)(me+0x4e)=ext_4e5e80(&value);
 void* original=stream;
 for(int i=0;i<4;i++){
  vcall<void>(original,0x40,&stream);
  *(u32*)(me+0x55+4*i)=vcall<u32>(*(void**)(G(u8*,0x70039c)+0x9b),0x58,stream);
 }
 return 1;
}
PCREG(5d3660,read_fields);
