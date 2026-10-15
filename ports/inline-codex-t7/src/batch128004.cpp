#include "ff.h"
extern "C" void ext_41e010(u32,...);
extern "C" void ext_41dd90();
extern "C" void ext_41dd70();
extern "C" u8* FASTCALL ext_41d500(u8*);
extern "C" u8* ext_41e170(u8*,u32);
template<class R,class...A> static R api4(u32 addr,A...args){return (*(R(STDCALL **)(A...))addr)(args...);}
static u32 l4(u8*p){u32 n=0;while(p[n])++n;return n;}
static void FASTCALL printSource(u32 address,u32 context){
 ext_41e010(0x677098);ext_41dd90();
 u32 line[5]={20,0,0,0,0};u8 scratch[4];
 if(!api4<u32>(0x6fcd5c,G(u32,0x6fcd80),address,scratch,line))return;
 u32 start=context>line[2]?1:line[2]-context,end=line[2]+context;
 u32 file=api4<u32>(0x676068,line[3],0x80000000u,1u,0u,3u,0x8000000u,0u);
 if(file==0xffffffff){
  u32 fallback[5]={20,0,0,0,0};u8 dummy[4];
  if(api4<u32>(0x6fcd5c,G(u32,0x6fcd80),0x41d7cau,dummy,fallback)){
   u8*source=(u8*)fallback[3];u8*p=source+l4(source);u32 separators=2;
   while(separators && (u32)p>=(u32)source){if(*p=='/'||*p=='\\')--separators;--p;}
   if(separators)return;
   ++p;
   u8 module[260];for(u32 i=0;i<260;++i)module[i]=0xcc;
   api4<u32>(0x67607c,G(u32,0x6fcd40),module,260u);
   u8*dest=ext_41d500(module);
   *(u32*)dest=G(u32,0x6770d8);*(u32*)(dest+4)=G(u32,0x6770dc);
   u32 off=l4(dest);for(u32 i=0;i<=l4(p);++i)dest[off+i]=p[i];
   file=api4<u32>(0x676068,module,0x80000000u,1u,0u,3u,0x8000000u,0u);
  }
  if(file==0xffffffff)return;
 }
 u32 size=api4<u32>(0x67608c,file,0u);
 if(size==0xffffffff){ext_41dd70();return;}
 u32 handle=api4<u32>(0x6760a8,0u,size);
 u8*buffer=api4<u8*>(0x6760a0,handle);
 if(buffer){
  u32 got=0xcccccccc;
  if(api4<u32>(0x676094,file,buffer,size,&got,0u)){
   u8*p=buffer;u32 i=1;
   for(;i<start;++i){p=ext_41e170(p,10);if(!p)goto cleanup; ++p;}
   ext_41e010(0x6770e0,line[3],start,end);
   if(*p==13)++p;
   for(;i<=end;++i){
    u8*next=ext_41e170(p,10);if(!next)break;
    u8*last=next;if(last[-1]==13)--last;
    u8 fmt[32];
    typedef u32(*Sprintf)(u8*,u32,u32);
    (*(Sprintf*)0x6761e4)(fmt,i==line[2]?0x6770f8u:0x67710cu,(u32)(last-p));
    ext_41e010((u32)fmt,p);p=next+1;
   }
  }
 cleanup:
  u32 h=api4<u32>(0x6760a8,0u,(u32)buffer);api4<u32>(0x6760a4,h);
 }
 api4<u32>(0x676070,file);ext_41dd70();
}
PCREG(41d6a0,printSource);
