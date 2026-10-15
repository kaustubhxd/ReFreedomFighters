#include "ff.h"
extern "C" void THISCALL ext_64a700(void*,void*,void*,void*);
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" void FASTCALL ext_441a60(void*,void*);
extern "C" void FASTCALL ext_4de4b0(void*,void*,void*);
extern "C" void FASTCALL ext_4de420(void*,void*);
extern "C" void FASTCALL ext_660c00(void*,u32,u32,u32,u32,void*,void*,void*);
extern "C" void THISCALL ext_648fb0(void*,void*,void*,u32,void*);
extern "C" void* ext_634d10(void*,u32,u32);
static void THISCALL fn64a280(u8*s,u8**begin,u8**end,u32 arg,u8*opt){
 s32 count=((u32)end-(u32)begin)/4;if(!count)return;
 u8*base=*(u8**)(opt+8);u8 records[512*64];u32 kept=0;
 for(s32 i=0;i<count;i++){
  u8*p=begin[i];if(!(*(u32*)(p+0x3c)&0x10402c00u)){
   begin[kept]=p;ext_64a700(s,records+64*kept,p,base+8);++kept;
  }
 }
 float delta[3];ext_43e920(delta,base+0x2c,s+0x1821d);ext_441a60(delta,s+0x181f9);
 float temp[9],matrix[9];ext_4de4b0(temp,base+8,s+0x181f9);ext_4de420(matrix,temp);
 float position[3]={delta[0],delta[1],delta[2]};u8 mask[128];ext_634d10(mask,0xff,128);
 ext_660c00(records,kept,arg,*(u32*)(opt+0x14),*(u16*)(opt+0x1e),mask,matrix,position);
 ext_648fb0(s,mask,begin,kept,opt);
}
PCREG(64a280,fn64a280);
