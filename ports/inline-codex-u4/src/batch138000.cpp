#include "ff.h"
extern "C" void THISCALL ext_5f0280(u8*,u32*);
extern "C" void THISCALL ext_5af2a0(u8*,u32,u32);
extern "C" void THISCALL ext_5aee20(u8*,u32,u32);
static u8 THISCALL readSettings(u8* self,u8* stream) {
  ext_5f0280(stream,(u32*)(self+4));
  if (*(u32*)(self+4)!=1) {
    void* log=vcall<void*>(G(void*,0x700390),0x20,0x6b1150u,0x8du);
    typedef void (*Print)(void*,u32);
    (*(Print*)(*(u8**)log+0x2c))(log,0x6b1188u);
  } else {
    u32 v;
    ext_5f0280(stream,&v); *(u32*)(self+8)=v;
    ext_5f0280(stream,(u32*)(self+0x10));
    ext_5f0280(stream,&v); *(u32*)(self+0xc)=v;
    ext_5f0280(stream,(u32*)(self+0x14));
    u32 values[4];
    for(int i=0;i<4;++i) ext_5f0280(stream,&values[i]);
    const u32 ids[4]={0xd,0xc,0xe,0x10};
    for(int i=0;i<4;++i) ext_5af2a0(self+0x18,ids[i],values[i]);
    const u32* keys=(const u32*)0x6a7400;
    for(int i=0; i<8; ++i) {
      u32 enabled,value;
      ext_5f0280(stream,&enabled); ext_5f0280(stream,&value);
      if(enabled!=0) ext_5aee20(self+0x2c,keys[i],value);
    }
    ext_5f0280(stream,&v); ext_5af2a0(self+0x18,0xf,v);
  }
  return stream[0xc]==0;
}
PCREG(5b0810,readSettings);
