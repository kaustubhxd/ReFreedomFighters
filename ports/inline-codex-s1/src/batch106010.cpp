#include "ff.h"
extern "C" void* THISCALL ext_5003d0(void*,u32);
extern "C" void ext_633654(u32);
static void* slot4c(void* obj) {
 void* result;void* fn=*(void**)(*(u8**)obj+0x4c);
 asm volatile("push $0\n\tcall *%2\n\tadd $4,%%esp":"=a"(result),"+c"(obj):"r"(fn):"edx","memory","cc");
 return result;
}
static void* STDCALL translate(void* obj,u32 key,u32 id) {
 void* result=vcall<void*>(obj,0x18,key);
 if(result){
  void* found=vcall<void*>(*(void**)(G(u8*,0x70039c)+0x9b),0x58,id);
  const char* text;
  char fallback[25];
  if(found)text=*(const char**)((u8*)found+4);
  else {for(int i=0;i<25;i++)fallback[i]=G(char,0x69c948+i);text=fallback;}
  void* list=slot4c(result);
  void* cell=ext_5003d0(list,0);
  vcall<void>(*(void**)cell,0x30,text);
 }
 ext_633654(0);
 return result;
}
PCREG(5007e0,translate);
