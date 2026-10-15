#include "ff.h"
static void THISCALL serialize(u8* self,void* writer){
 vcall<void>(writer,8,2u);
 vcall<void>(writer,0x58,*(u64*)(self+0xc));
 vcall<void>(writer,0x58,*(u64*)(self+4));
 vcall<void>(writer,0x58,*(u64*)(self+0x14));
 vcall<void>(writer,0x54,*(u32*)(self+0x1c));
 vcall<void>(writer,0x4c,*(u32*)(self+0x20));
 vcall<void>(writer,0x54,*(u32*)(self+0x24));
 vcall<void>(writer,0x4c,*(u32*)(self+0x2c));
 vcall<void>(writer,0x54,*(u32*)(self+0x30));
 vcall<void>(writer,0x4c,*(u32*)(self+0x34));
 vcall<void>(writer,0x54,*(u32*)(self+0x38));
 vcall<void>(writer,0x3c,*(u32*)(self+0x3c));
 vcall<void>(writer,0x54,*(u32*)(self+0x40));
 vcall<void>(writer,0x54,*(u32*)(self+0x44));
 vcall<void>(writer,0x4c,*(u32*)(self+0x48));
 vcall<void>(writer,0x54,*(u32*)(self+0x4c));
 vcall<void>(writer,0x4c,*(u32*)(self+0x58));
 vcall<void>(writer,0x44,*(u32*)(self+0x1b49));
 vcall<void>(writer,0x60,(u32)self[0x1b59]);
}
PCREG(42f8c0,serialize);
