#include "ff.h"
static bool floatRange(u8* s,u32 off,float lo,float hi){float v=*(float*)(s+off);return !(lo>v || v>hi);}
static u8 THISCALL validateParameters(u8* s){
 for(u32 off=0xc;off<=0x14;off+=4)if(*(s32*)(s+off)<-10000 || *(s32*)(s+off)>0)return 0;
 if(*(u32*)s>0x1a)return 0;
 if(!floatRange(s,4,G(float,0x678858),G(float,0x67cd40)))return 0;
 if(!floatRange(s,8,0,G(float,0x678858)))return 0;
 if(!floatRange(s,0x18,G(float,0x67a284),G(float,0x67da20)))return 0;
 if(!floatRange(s,0x1c,G(float,0x67a284),G(float,0x680a60)))return 0;
 if(!floatRange(s,0x20,G(float,0x67a284),G(float,0x680a60)))return 0;
 if(*(s32*)(s+0x24)<-10000 || *(s32*)(s+0x24)>1000)return 0;
 if(!floatRange(s,0x28,0,G(float,0x67c198)))return 0;
 if(*(s32*)(s+0x38)<-10000 || *(s32*)(s+0x38)>2000)return 0;
 if(!floatRange(s,0x3c,0,G(float,0x67a284)))return 0;
 if(!floatRange(s,0x4c,G(float,0x6a2af4),G(float,0x67a288)))return 0;
 if(!floatRange(s,0x50,0,G(float,0x678858)))return 0;
 if(!floatRange(s,0x54,G(float,0x686080),G(float,0x67da1c)))return 0;
 if(!floatRange(s,0x58,0,G(float,0x678858)))return 0;
 if(!floatRange(s,0x5c,G(float,0x6a24f4),0))return 0;
 if(!floatRange(s,0x60,G(float,0x67d164),G(float,0x6a2b00)))return 0;
 if(!floatRange(s,0x64,G(float,0x67da20),G(float,0x67d164)))return 0;
 if(!floatRange(s,0x68,0,G(float,0x680a70)))return 0;
 return (*(u32*)(s+0x6c)&0xffffff00u)==0;
}
PCREG(539ca0,validateParameters);
