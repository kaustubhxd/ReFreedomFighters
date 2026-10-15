#include "ff.h"
extern "C" float FASTCALL ext_4e0870(u8*,u8*);
extern "C" void THISCALL ext_516040(u8*,float);
static void THISCALL update_two_record_groups(u8* self,float scale,u8* vector) {
  u32 local[3];
  u8* slot=self+0x85;
  if(slot!=(u8*)local) G(u32,slot)=G(u32,(u8*)g_pSysInterface+0x40)+0x1c00;
  u32 n=G(u32,self+0x8d);
  for(u32 i=0;i<n;i++) {
    u8* record=self+0xe91+i*0x133;
    float distance=ext_4e0870(record,vector);
    float factor=G(float,0x67cd40)/distance;
    float one=G(float,0x678858);
    if(one<factor) factor=one;
    ext_516040(self+0x95+i*0xde,factor*scale);
  }
  n=G(u32,self+0x91);
  for(u32 i=0;i<n;i++) {
    u8* record=self+0x1829+i*0x133;
    float distance=ext_4e0870(record,vector);
    float factor=G(float,0x67cd40)/distance;
    float one=G(float,0x678858);
    if(one<factor) factor=one;
    ext_516040(self+0x785+i*0xde,factor*scale);
  }
}
PCREG(5289d0,update_two_record_groups);
