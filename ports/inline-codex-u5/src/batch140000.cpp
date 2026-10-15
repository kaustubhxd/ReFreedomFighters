#include "ff.h"
extern "C" void FASTCALL ext_54f2b0(u32, u32);
template<class R, class... A> static R com(void* p,u32 off,A...a){return (*(R(STDCALL**)(void*,A...))(*(u8**)p+off))(p,a...);}
extern "C" u8 THISCALL sound_init(void* self){
 u8* p=(u8*)self; void* dev=*(void**)(p+0xa274); void** out=(void**)(p+0xa278);
 u32 desc[9]={0x24,0x91,0,0,0,0,0,0,0};
 u32 err=com<u32>(dev,0xc,desc,out,0u);
 if(err){
  ext_54f2b0(err,0x6a3afc);
  void* logger=vcall<void*>(G(void*,0x700390),0x20,0x6a38e0u,0x2eeu);
  (*(void(**)(void*,u32))(*(u8**)logger+0x2c))(logger,0x6a3b1cu);
  desc[1]=0x11;
  err=com<u32>(*(void**)(p+0xa274),0xc,desc,out,0u);
  if(err){ext_54f2b0(err,0x6a3afc);return 0;}
 }
 u8 fmt[18]={1,0,2,0,0x44,0xac,0,0,0x10,0xb1,2,0,4,0,0x10,0,0x12,0};
 err=com<u32>(*out,0x38,fmt);
 if(err){ext_54f2b0(err,0x6a3b4c);return 0;}
 err=com<u32>(*out,0x30,0u,0u,1u);
 if(err){ext_54f2b0(err,0x6a3b60);return 0;}
 return 1;
}
PCREG(54b4d0,sound_init);
