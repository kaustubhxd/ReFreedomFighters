#include "ff.h"
extern "C" void* ext_634d22(void*,const void*,u32);
extern "C" void THISCALL ext_5f2c60(void*,void*,void*);
extern "C" void* assign_tail_body(u8* me,u8* start,u8* end,u8* growend,u8* frame){
 u32 n=(u32)(end-start);*(u32*)(frame+12)=n;
 u8* dst=*(u8**)me;u32 cap=(u32)(*(u8**)(me+4)-dst);
 if(n<=cap){
  ext_634d22(dst,start,n);
  u8* next=*(u8**)me+*(u32*)(frame+12);u8* old=*(u8**)(me+4);
  if(next!=old){
   typedef void*(*Move)(void*,void*,u32);(*(Move*)0x676278)(next,old,1);
   *(u8**)(me+4)+=(next-old);
  }
 }else{
  ext_634d22(dst,start,cap);
  u32 used=(u32)(*(u8**)(me+4)-*(u8**)me);
  ext_5f2c60(me,start+used,growend);
 }
 return me;
}
asm(".text\n.globl assign_partial\nassign_partial:\n"
 "push %esi\npush %edi\npush %ebp\npush %ebx\npush %eax\npush 8(%ebp)\npush %ecx\ncall assign_tail_body\nadd $20,%esp\n"
 "pop %edi\npop %esi\npop %ebx\npop %ebp\nret $8\n");
extern "C" void assign_partial();
PCREG(5f2d69,assign_partial);
