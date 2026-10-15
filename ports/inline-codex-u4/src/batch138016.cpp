#include "ff.h"
static u8 THISCALL serializeMaterial(u8* s,void* writer){
 *(u32*)(s+4)&=0xffffffbfu;
 for(int i=0;i<4;++i)vcall<void>(writer,0x44,*(u32*)(s+0x48+4*i));
 for(int i=0;i<6;++i)vcall<void>(writer,0x4c,*(u32*)(s+0x5c+4*i));
 vcall<void>(writer,0x44,*(u32*)(s+0x74));vcall<void>(writer,0x44,*(u32*)(s+0x78));
 vcall<void>(writer,0x4c,*(u32*)(s+0x80));vcall<void>(writer,0x4c,*(u32*)(s+0x84));vcall<void>(writer,0x4c,*(u32*)(s+0x7c));
 return 1;
}
PCREG(4bd7f0,serializeMaterial);
