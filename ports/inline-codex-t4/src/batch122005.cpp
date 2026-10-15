#include "ff.h"
static float THISCALL fn5377d0(u8* s,u32 off){
 u8* base=*(u8**)(s+0x5302);if(!base)return 0.f;
 u8* p=base+off;u32 tag=*(u32*)p;
 if(tag==1||tag==2){if(tag==2)p=base+*(u32*)(p+8);return vcall<float>(s,0x1e0,p);}
 u8* log=vcall<u8*>(G(u8*,0x700390),0x20,(u32)0x6a1e2c,(u32)0x3ed);
 u32 desc=vcall<u32>(s,0x1e8,p);
 typedef void(*Log)(u8*,u32,u32);
 (*(Log*)(*(u8**)log+0x2c))(log,0x6a2090,desc);
 return 0.f;
}
PCREG(5377d0,fn5377d0);
