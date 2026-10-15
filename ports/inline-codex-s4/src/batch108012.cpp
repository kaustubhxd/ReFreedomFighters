#include "s4_mem.h"
extern "C" u8 THISCALL f4a43f0(void* self,void* reader){
 s4w(self,4,s4r(self,4)&~0x40u);
 vcall<void>(reader,0x44,(u8*)self+0x58);vcall<void>(reader,0x44,(u8*)self+0x5a);
 vcall<void>(reader,0x50,(u8*)self+0x1b4);vcall<void>(reader,0x50,(u8*)self+0x1b8);vcall<void>(reader,0x50,(u8*)self+0x1bc);
 vcall<void>(reader,0x68,(u8*)self+0x1d8);vcall<void>(reader,0x68,(u8*)self+0x1da);vcall<void>(reader,0x68,(u8*)self+0x1d9);
 vcall<void>(reader,0x68,(u8*)self+0x1db);vcall<void>(reader,0x68,(u8*)self+0x1dc);
 vcall<void>(reader,0x50,(u8*)self+0x1c0);vcall<void>(reader,0x50,(u8*)self+0x1c4);
 vcall<void>(reader,0x70,(u8*)self+0x5c);vcall<void>(reader,0x70,(u8*)self+0x108);
 return 1;
}
PCREG(4a43f0,f4a43f0);
extern "C" u8 THISCALL f4b5be0(void* self,void* reader){
 s4w(self,4,s4r(self,4)&~0x40u);
 typedef void(*Assert)();((Assert)G(u32,0x7003b0))();
 vcall<void>(self,0x98,0u);
 vcall<void>(reader,0x48,(u8*)self+0x48);vcall<void>(reader,0x58,(u8*)self+0x50);
 vcall<void>(reader,0x50,(u8*)self+0x58);vcall<void>(reader,0x50,(u8*)self+0x5c);
 vcall<void>(reader,0x48,(u8*)self+0x68);vcall<void>(reader,0x48,(u8*)self+0x6c);
 vcall<void>(reader,0x40,(u8*)self+0x8d);vcall<void>(reader,0x50,(u8*)self+0x60);
 vcall<void>(reader,0x48,(u8*)self+0x64);vcall<void>(reader,0x48,(u8*)self+0x70);vcall<void>(reader,0x48,(u8*)self+0x74);
 vcall<void>(reader,0x40,(u8*)self+0x7c);
 return 1;
}
PCREG(4b5be0,f4b5be0);
