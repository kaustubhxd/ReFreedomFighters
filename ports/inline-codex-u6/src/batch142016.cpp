#include "ff.h"
static u8 THISCALL save(u8* me,void* stream){
 *(u32*)(me+4)&=0xffffffbf;
 vcall<void>(stream,0x44,*(u32*)(me+0x48));
 vcall<void>(stream,0x40,(u32)*(u16*)(me+0x4c));vcall<void>(stream,0x40,(u32)*(u16*)(me+0x4e));
 for(int i=0;i<5;i++)vcall<void>(stream,0x60,(u32)me[0x50+i]);
 for(int i=0;i<7;i++)vcall<void>(stream,0x4c,*(u32*)(me+0x55+4*i));
 for(int i=0;i<3;i++)vcall<void>(stream,0x60,(u32)me[0x71+i]);
 return 1;
}
PCREG(4c27c0,save);
