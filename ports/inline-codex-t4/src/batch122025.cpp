#include "ff.h"
extern "C" void THISCALL ext_5165d0(u8*,float,u32,float,u32);
static void THISCALL fn526470(u8* s){
 s32 n=*(s32*)(s+0x8c);*(s32*)(s+0x40)=((s32)(*(u32*)(s+0x40)+1))%n;
 *(s32*)(s+0x44)=((s32)(*(u32*)(s+0x44)+1))%(*(s32*)(s+0x90));
 float height=*(float*)(s+0x64)+G(float,0x67da2c);
 for(s32 i=0;i<*(s32*)(s+0x8c);++i)ext_5165d0(s+0xbd+222*i,*(float*)(s+0x68),(u32)(*(s32*)(s+0x40)==i),height,0);
 for(s32 i=0;i<*(s32*)(s+0x90);++i)ext_5165d0(s+0x435+222*i,*(float*)(s+0x68),(u32)(*(s32*)(s+0x44)==i),height,0);
}
PCREG(526470,fn526470);
