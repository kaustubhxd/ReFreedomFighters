#include "ff.h"
extern "C" void ext_410470(void*);
extern "C" u32 ext_4104c0(void*,u32);
extern "C" u32 THISCALL ext_54e1f0(void*,u32,u32,u32*,u32);
extern "C" void ext_410540(void*,u32);
extern "C" s32 ext_4106b0(void*,void*);
extern "C" u32 ext_410220(void*);
extern "C" s32 ext_410280(void*,u32);
extern "C" void ext_401090(void*);
extern "C" void ext_401000(void*);
extern "C" s32 ext_4106f0(void*,void*);
extern "C" s32 ext_410a00(void*,void*);
extern "C" s32 ext_401220(void*,void*,void*);
extern "C" void ext_401ef0(void*,void*);
extern "C" void ext_4017c0(void*,void*);
static inline u32&w20(u8*p,u32 o){return *(u32*)(p+o);}
static void assert20(){((void(*)())G(u32,0x7003b0))();}
static void err20(u32 line,u32 msg,u32 slot=0x2c){void*l=vcall<void*>(G(void*,0x700390),0x20,0x6a34c4u,line);((void(*)(void*,u32))(*(u32*)(*(u8**)l+slot)))(l,msg);}
static u8 THISCALL start20(u8*self){
 if(self[0x2315])return 1;
 w20(*(u8**)(self+5),0x67)=0xb36;w20(self,0x2041)=w20(self,0x2316);
 w20(self,0x15)=w20(self,0xd)=w20(self,0x11)=w20(self,0x2311)=w20(self,9)=0;
 vcall<void>(self,0x14);u8*sync=self+0x2045;ext_410470(sync);w20(self,0x19)=0;
 w20(self,0x2309)=ext_4104c0(sync,w20(self,0x2316));u8*ctx=*(u8**)(self+5);u32 count=0xcccccccc;
 if(ext_54e1f0(ctx,w20(self,0x2309),w20(ctx,0x47),&count,0)!=1)assert20();
 w20(self,9)+=count;w20(self,0x230d)=count;ext_410540(sync,count);
 u8*page=self+0x21c9;
 if(ext_4106b0(sync,page)!=1){if((s32)w20(self,0x230d)<(s32)w20(self,0x2316))assert20();err20(0x36e,0x6a3530,0x30);return 0;}
 w20(self,0x2311)+=w20(self,0x21d5)+w20(self,0x21cd);self[0x2315]=1;
 u32 serial=ext_410220(page);u8*stream=self+0x2061;
 if(ext_410280(stream,serial)<0){err20(0x37c,0x6a3560);assert20();}
 ext_401090(self+0x21f9);ext_401000(self+0x2219);
 if(ext_4106f0(stream,page)<0){err20(0x38d,0x6a3588);assert20();}
 u8*packet=self+0x21d9;
 if(ext_410a00(stream,packet)!=1){err20(0x393,0x6a35bc);assert20();}
 if(ext_401220(self+0x21f9,self+0x2219,packet)<0){err20(0x399,0x6a35e4);assert20();}
 w20(self,0x1d)=0;
 while((s32)w20(self,0x1d)<2){
  s32 result=ext_4106b0(sync,self+0x21c9);w20(self,0x2311)+=w20(self,0x21d5)+w20(self,0x21cd);
  if(result!=1)continue;
  ext_4106f0(stream,self+0x21c9);
  while((s32)w20(self,0x1d)<2){
   result=ext_410a00(stream,packet);if(!result)break;
   if(result<0){err20(0x3b7,0x6a361c);assert20();}
   ext_401220(self+0x21f9,self+0x2219,packet);++w20(self,0x1d);
  }
 }
 w20(self,0x2041)=(s32)w20(self,0x2316)/(s32)w20(self,0x21fd);
 ext_401ef0(self+0x2229,self+0x21f9);ext_4017c0(self+0x2229,self+0x2299);self[4]=0;return 0;
}
PCREG(54a260,start20);
