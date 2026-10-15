#include "ff.h"
extern "C" void THISCALL ext_45f960(u8*,u8*);
static u8 THISCALL fn4550f0(u8* s,u8* stream){
 ext_45f960(s,stream);
 u32 offs[]={0x18,0x1c,0x20,0x34,0x28};
 for(u32 off:offs)vcall<void>(stream,0x3c,*(u32*)(s+off));
 vcall<void>(stream,0x4c,*(float*)(s+0x30));
 vcall<void>(stream,0x44,*(u32*)(s+0x2c));
 u32 tail[]={0x24,0x3c,0x40,0x44,0x48};
 for(u32 off:tail)vcall<void>(stream,0x3c,*(u32*)(s+off));
 return 1;
}
PCREG(4550f0,fn4550f0);
