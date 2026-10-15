#include "ff.h"
extern "C" void THISCALL ext_4e09b0(float*);
extern "C" void FASTCALL ext_4419f0(float*,float*);
extern "C" void FASTCALL ext_441940(float*,float*);
extern "C" void THISCALL ext_5cd7f0(u8*,float*,float*,float,u32);
static void THISCALL fn5d26c0(u8* s,u8* flag){
 if(*(u32*)(G(u8*,0x70039c)+0x1b5d)==1)return;
 float matrix[9],pos[3];vcall<void>(s,0x90,matrix,pos);
 for(u32 j=0;j<3;++j){*(float*)(s+0xddd+4*j)=pos[j];*(float*)(s+0xde9+4*j)=matrix[j];}
 *(u8**)(s+0xdd9)=flag;u8* owner=*(u8**)(flag+0x119);
 if(owner){float p[3];vcall<void>(owner,0x80,matrix,p);for(u32 j=0;j<3;++j){float t=matrix[j];matrix[j]=matrix[j+3];matrix[j+3]=t;}
  ext_4e09b0(matrix+6);pos[0]=0;pos[1]=0;pos[2]=bitsf(fbits(*(float*)(*(u8**)(s+0xb54)+0x479))^G(u32,0x67af40));ext_4419f0(pos,matrix);ext_441940(pos,p);
 }else pos[1]=pos[1]+G(float,0x694d10);
 float orientation[3]={matrix[0],matrix[1],matrix[2]};ext_4e09b0(orientation);ext_5cd7f0(s,pos,orientation,6.f,3);s[0xdd8]=1;
}
PCREG(5d26c0,fn5d26c0);
