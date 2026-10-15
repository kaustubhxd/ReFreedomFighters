#include "ff.h"
static void THISCALL fn515ab0(u8* s,u8* arg){
 u8* sys=G(u8*,0x70039c);
 vcall<u8*>(*(u8**)(sys+0x9b),0x58,*(u32*)(arg+8));
 sys=G(u8*,0x70039c);
 u8* found=vcall<u8*>(*(u8**)(sys+0x9b),0x58,*(u32*)(arg+16));
 if(!found||vcall<u32>(found,0x330)!=7)return;
 u32 payload[12];payload[0]=*(u32*)(arg+12);payload[1]=0;payload[2]=0;payload[10]=0x43fa0000;
 u8* pos=*(u8**)arg;
 payload[4]=*(u32*)(pos+0x28);payload[5]=*(u32*)(pos+0x2c);payload[6]=*(u32*)(pos+0x30);
 vcall<void>(s,0x130,s,(u32)*(u16*)(s+0x2d0),payload);
}
PCREG(515ab0,fn515ab0);
