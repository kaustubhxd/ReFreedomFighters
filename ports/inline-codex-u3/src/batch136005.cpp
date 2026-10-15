#include "ff.h"
extern "C" void ext_634273(u32,u32);
static void THISCALL fn56aea0(u8*s){
 if(s[0x50]){
  vcall<void>(G(void*,0x70039c),0xc,*(u32*)(s+0x51),*(u32*)(s+0x55),*(u32*)(s+0x59),*(u32*)(s+0x5d));
  const u32 names[2]={0x6a78e8,0x6a78f4};
  for(int k=0;k<2;k++){
   u8*w=vcall<u8*>(*(void**)(s+0x44),0x25c,names[k],0u);if(!w)continue;
   char in[200],out[200];const char*src=*(char**)(w+0x97);u32 n=0;
   do{in[n]=src[n];}while(in[n++]);
   for(u32 i=0;in[i];i++)if(in[i]=='\n')in[i]=' ';
   u32 len=0;for(u32 i=0;in[i];i++)if(!(i>0 && in[i-1]==' ' && in[i]==' '))out[len++]=in[i];
   out[len]=0;vcall<void>(w,0x284,out);
  }
  s[0x50]=0;
 }
 ++*(u32*)(s+0x48);
 if(*(u32*)(s+0x48)>=3){
  vcall<void>(*(void**)(G(u8*,0x70039c)+0x9b),0xa4);
  vcall<void>(*(void**)(G(u8*,0x70039c)+0x9b),0xa0,*(u32*)(s+0x4c));
  ext_634273(*(u32*)(s+0x4c),1u);*(u32*)(s+0x4c)=0;
 }
}
PCREG(56aea0,fn56aea0);
