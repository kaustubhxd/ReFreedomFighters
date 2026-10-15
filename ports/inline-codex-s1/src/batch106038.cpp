#include "ff.h"
static u32 convert38(float x){
 u32 result;void* helper=(void*)0x633910;
 asm volatile("movss %1,%%xmm0\n\tcall *%2":"=a"(result):"m"(x),"r"(helper):"ecx","edx","xmm0","xmm1","xmm2","xmm3","xmm4","xmm5","xmm6","xmm7","memory","cc");
 return result;
}
extern "C" u32 progress38(u8* me,u32 incoming){
 void* target=*(void**)(me+0x6d);if(!target)return incoming;
 u32 n=vcall<u32>(target,0x14);*(u32*)(me+0x91)=n;
 for(u32 i=0;i<*(u32*)(me+0x91);i++){
  void* table=*(void**)(G(u8*,0x70039c)+0x9b);u8* vt=*(u8**)table;
  u32 id=vcall<u32>(*(void**)(me+0x6d),0x30,i);
  table=*(void**)(G(u8*,0x70039c)+0x9b);
  typedef u8*(THISCALL *Lookup)(void*,u32);u8* record=(*(Lookup*)(vt+0x58))(table,id);
  if(record){
   float value=*(float*)(record+0x20)*G(float,0x67da00);value=value/(*(float*)(me+0x79));
   u32 base=*(u32*)(me+0x89);
   float basef=(float)((double)(s32)base+G(double,0x680aa0+8*(base>>31)));
   *(u32*)(me+0x89)=convert38(value+basef);
  }
 }
 u32 count=*(u32*)(me+0x89);*(u32*)(me+0x8d)=count;
 u32 shifted=count?count>>3:0;*(u32*)(me+0x69)=shifted;return shifted;
}
asm(".text\n.globl progress_entry38\nprogress_entry38:\npush %eax\npush %ecx\ncall progress38\nadd $8,%esp\nret\n");
extern "C" void progress_entry38();
PCREG(4c1f80,progress_entry38);
