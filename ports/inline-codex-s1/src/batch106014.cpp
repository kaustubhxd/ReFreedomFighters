#include "ff.h"
extern "C" void FASTCALL ext_4e0390(void*,void*,void*,float,float);
extern "C" float THISCALL ext_44c840(void*);
extern "C" void FASTCALL ext_446ee0(void*,void*,void*);
extern "C" void interpolate_body(u8* dst,u8* src,void* a,void* d,void* c,float weight,u8* frame){
 ext_4e0390(c,d,a,weight,weight);
 float n=ext_44c840(dst);*(float*)(frame-4)=n;
 bool fallback=G(float,0x679540)>n;
 if(!fallback){
  u8* b=*(u8**)(frame+8);float t=*(float*)(frame+12);
  for(int i=0;i<3;i++){float x=*(float*)(src+12+4*i);*(float*)(dst+12+4*i)=(*(float*)(b+12+4*i)-x)*t+x;}
  n=ext_44c840(dst+12);*(float*)(frame+8)=n;fallback=G(float,0x679540)>n;
  if(!fallback){
   ext_446ee0(dst+24,dst+12,dst);
   n=ext_44c840(dst+24);*(float*)(frame+8)=n;fallback=G(float,0x679540)>n;
   if(!fallback)ext_446ee0(dst+12,dst,dst+24);
  }
 }
 if(fallback){
  _mm_storeu_ps((float*)dst,_mm_loadu_ps((float*)src));
  _mm_storeu_ps((float*)(dst+16),_mm_loadu_ps((float*)(src+16)));
  *(u32*)(dst+32)=*(u32*)(src+32);
 }
}
asm(".text\n.globl partial_interpolate\npartial_interpolate:\n"
 "push %ebp\nsub $4,%esp\nmovss %xmm2,(%esp)\npush %ecx\npush %edx\npush %eax\npush %esi\npush %ebx\ncall interpolate_body\nadd $28,%esp\n"
 "pop %edi\npop %esi\npop %ebx\nmov %ebp,%esp\npop %ebp\nret $8\n");
extern "C" void partial_interpolate();
PCREG(4de6a3,partial_interpolate);
