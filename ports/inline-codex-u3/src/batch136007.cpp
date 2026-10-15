#include "ff.h"
extern "C" void FASTCALL ext_4de420(void*,void*);
extern "C" void FASTCALL ext_4419f0(void*,void*);
extern "C" void THISCALL ext_4e73b0(void*,void*,void*,void*,float,float);
static void THISCALL fn4a71f0(u8*s){
 u8 data[0x88];data[0]=0;
 for(int i=0;i<3;i++){*(u32*)(s+0xd2 + 4*i)=*(u32*)(s+0x11b + 4*i);*(u32*)(s+0xde + 4*i)=*(u32*)(s+0x127 + 4*i);}
 void*o=*(void**)(s+0x44);vcall<void>(o,0x128,0x4004u,data,0u);
 float matrix[9],position[3];vcall<void>(*(void**)(s+0x44),0x80,matrix,position);
 if(data[0]){
  for(int i=0;i<3;i++)*(u32*)(s+0xd2 + 4*i)=*(u32*)(data+1+4*i);
  for(int i=0;i<6;i++)*(u32*)(s+0xba + 4*i)=*(u32*)(data+13+4*i);
  for(int i=0;i<3;i++)((u32*)position)[i]=*(u32*)(data+37+4*i);
  ext_4de420(matrix,data+49);
  void*sub=vcall<void*>(*(void**)(s+0x44),0x20);vcall<void>(sub,0x98,matrix,position);
  vcall<void>(*(void**)(s+0x44),0x7c,matrix,position);
 }
 ext_4419f0(s+0xd2,matrix);
 float scale=(float)*(s32*)(s+0xf6)*G(float,0x6785e4);
 ext_4e73b0(s+0x48,position,s+0xd2,s+0xde,*(float*)(s+0xea),scale);
}
PCREG(4a71f0,fn4a71f0);
