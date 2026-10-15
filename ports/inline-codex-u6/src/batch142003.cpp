#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(void*,u32);
extern "C" void THISCALL ext_5002f0(void*,u32);
static void THISCALL apply(u8* me,u8* args){
 u8* value=ext_5003d0(*(void**)(args+4),0);
 if(value[4]!=0 && value[4]!=1){
  void* log=vcall<void*>(G(void*,0x700390),0x20,0x69c8e0u,0x104u);
  typedef void(*Print)(void*,u32,u32); (*(Print*)(*(u8**)log+0x2c))(log,0x69c6b0u,0x69c938u);
  typedef void(*Assert)(); G(Assert,0x7003b0)();
 }
 u32 target=*(u32*)value,current; float zero[3]={0,0,0};
 void* owner=*(void**)(me+0x1c); vcall<void>(owner,0x4c8,&current);
 u8* result=ext_5003d0(*(void**)(args+8),0); ext_5002f0(result,current);
 if(target){
  if(current && target!=current)vcall<void>(owner,0x4b4,0u,0u,0u,0u,0xffffffffu);
  result=ext_5003d0(*(void**)(args+4),0);
  vcall<void>(owner,0x4ac,*(u32*)result,zero,0x3f000000u,0u,0u,0u,0xffffffffu);
  vcall<void>(owner,0x724);
 }else vcall<void>(owner,0x4b4,0u,0u,0u,0u,0xffffffffu);
}
PCREG(557fa0,apply);
