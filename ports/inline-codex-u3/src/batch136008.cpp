#include "ff.h"
extern "C" void THISCALL ext_516b60(void*,u32,u32,void*);
extern "C" void THISCALL ext_516f40(void*,void*);
extern "C" void THISCALL ext_516fd0(void*,void*);
static void THISCALL fn529ae0(u8*s,void*g,void*o){
 float position[3]={0,20,0},direction[3]={0,1,0};u32 axes[3]={0x3f1c61aa,0,0x3f1c61aa};
 ext_516b60(s+0x3d,0,0x69f9b8,o);
 for(int i=0;i<3;i++)*(float*)(s+0x6a + 4*i)=position[i];
 ext_516f40(s+0x3d,direction);*(u32*)(s+0x9a)=0;*(float*)(s+0x9e)=250;ext_516fd0(s+0x3d,axes);
 direction[0]=0;direction[1]=0.5f;direction[2]=-1;
 *(float*)(s+0x76)=35;*(float*)(s+0x7a)=20;*(float*)(s+0x7e)=35;*(u32*)(s+0x51)=0x3ecccccd;
 axes[0]=0x3eb2b8c2;axes[1]=0x3e860a92;axes[2]=0;position[0]=0;position[1]=20;position[2]=0;
 vcall<void>(o,0x84,position);position[1]-=*(float*)(s+0x14);vcall<void>(g,0x8c,position);
 ext_516b60(s+0xb6,0,0x6a0be8,g);
 for(int i=0;i<3;i++)*(float*)(s+0xe3 + 4*i)=position[i];
 ext_516f40(s+0xb6,direction);*(float*)(s+0x117)=250;ext_516fd0(s+0xb6,axes);
}
PCREG(529ae0,fn529ae0);
