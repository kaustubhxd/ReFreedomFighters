#include "ff.h"
static u8 THISCALL save(u8* me,void* stream){
 vcall<void>(stream,0x44,*(u32*)(me+0x28));u8* p=*(u8**)(me+0xf);
 for(int i=0;i<*(s32*)(me+0x28);i++,p+=0x34){
  vcall<void>(stream,0x68,p+0xc);vcall<void>(stream,0x68,p);vcall<void>(stream,0x68,p+0x18);vcall<void>(stream,0x68,p+0x24);
 }
 vcall<void>(stream,0x44,*(u32*)(me+0x2c));p=*(u8**)(me+0x13);
 for(int i=0;i<*(s32*)(me+0x2c);i++,p+=12){
  void* log=vcall<void*>(G(void*,0x700390),0x20,0x6a2e20u,0xb48u);
  typedef void(*Print)(void*,u32,u32,double,u32,u32);
  (*(Print*)(*(u8**)log+0x2c))(log,0x6a2e8cu,(u32)i,(double)*(float*)(p+8),*(u32*)p,*(u32*)(p+4));
  vcall<void>(stream,0x4c,*(u32*)(p+8));vcall<void>(stream,0x44,*(u32*)p);vcall<void>(stream,0x44,*(u32*)(p+4));
 }
 vcall<void>(stream,0x44,*(u32*)(me+0x30));p=*(u8**)(me+0x17);
 for(int i=0;i<*(s32*)(me+0x30);i++,p+=12){vcall<void>(stream,0x4c,*(u32*)(p+8));vcall<void>(stream,0x44,*(u32*)p);vcall<void>(stream,0x44,*(u32*)(p+4));}
 return 1;
}
PCREG(547520,save);
