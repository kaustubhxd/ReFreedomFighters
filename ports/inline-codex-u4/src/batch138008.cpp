#include "ff.h"
static u8 THISCALL serializeSettings(u8* s,void* writer){
 vcall<void>(writer,0x64,*(u32*)s);
 vcall<void>(writer,0x3c,*(u32*)(s+4));
 vcall<void>(writer,0x3c,*(u32*)(s+8));
 for(int i=0;i<4;++i)vcall<void>(writer,0x4c,*(u32*)(s+0xc+4*i));
 vcall<void>(writer,0x60,(u32)s[0x1c]);
 vcall<void>(writer,0x68,s+0x1d);
 vcall<void>(writer,0x64,*(u32*)(s+0x29));
 const u32 offsets[]={0x2d,0x39,0x45,0x51};
 for(int i=0;i<4;++i)vcall<void>(writer,0x68,s+offsets[i]);
 vcall<void>(writer,0x4c,*(u32*)(s+0x5d));
 vcall<void>(writer,0x4c,*(u32*)(s+0x61));
 vcall<void>(writer,0x68,s+0x65);
 vcall<void>(writer,0x4c,*(u32*)(s+0x71));
 vcall<void>(writer,0x4c,*(u32*)(s+0x75));
 return 1;
}
PCREG(516e20,serializeSettings);
