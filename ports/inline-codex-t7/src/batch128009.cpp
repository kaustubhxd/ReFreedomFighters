#include "ff.h"
extern "C" void* THISCALL ext_4dc130(void*);
extern "C" void THISCALL ext_4dc030(void*);
extern "C" u32 FASTCALL ext_4daf20(u32,u32);
extern "C" void THISCALL ext_4dcd00(void*,void*);
extern "C" u8* THISCALL ext_4db520(void*);
extern "C" void THISCALL ext_4dcda0(void*,void*);
extern "C" void THISCALL ext_4db860(void*,u32);
extern "C" void THISCALL ext_4690b0(void*);
extern "C" void* THISCALL ext_4db7e0(void*);
extern "C" void* THISCALL ext_4daff0(void*);
extern "C" void* THISCALL ext_4dafb0(void*);
extern "C" void THISCALL ext_4dc840(void*,void*);
extern "C" void THISCALL ext_4d9ce0(void*);
extern "C" void THISCALL ext_4d9bf0(void*);
extern "C" u32 THISCALL ext_4d9d20(void*,u32);
static inline u32 &w10(u8*p,u32 off){return *(u32*)(p+off);}
static inline u8 *p10(u8*p,u32 off){return *(u8**)(p+off);}
static inline u32 type10(u8*p){u8*data=p10(p,0x54);return data?w10(p10(data,12),0x23):0x200002;}
static inline void*tab10(){return *(void**)(G(u8*,0x70039c)+0x9b);}
static void prepend10(u8*self,u8*child){
 ext_4dcda0(child,p10(self,0x54));w10(child,0x60)=0;
 u8*head=p10(self,0x54);if(head)w10(head,0x60)=(u32)child;else w10(self,0x50)=(u32)child;
 w10(self,0x54)=(u32)child;
}
static void append10(u8*self,u8*child){
 w10(child,0x60)=w10(self,0x50);ext_4dcda0(child,0);
 if(p10(self,0x50))ext_4dcda0(p10(self,0x50),child);else w10(self,0x54)=(u32)child;
 w10(self,0x50)=(u32)child;
}
static u32 THISCALL attach10(u8*self,u8*child,u32 ordered,u32 activate){
 ext_4dc130(child);
 if(w10(child,0x50)){void*parent=ext_4dc130(child);vcall<void>(parent,0x290,child,0u);}
 if((w10(p10(self,8),0x3c)&0x400) && !(w10(child,0x3c)&0x400))ext_4dc030(child);
 if(ext_4daf20(type10(child),w10(child,0x3c))==2){
  void*map=*(void**)((u8*)tab10()+8);w10(self,0x48)=vcall<u32>(map,0x38,w10(self,0x48),child,child);
 }
 ext_4dcd00(child,p10(self,8));
 if((u8)ordered && !(type10(child)&0x100000)){
  u8*cur=p10(self,0x54),*last=0;
  while(cur){if(type10(cur)&0x100000)break;last=cur;cur=ext_4db520(cur);}
  if(last){
   ext_4dcda0(child,ext_4db520(last));w10(child,0x60)=(u32)last;
   if(ext_4db520(child)){u8*next=ext_4db520(child);w10(next,0x60)=(u32)child;ext_4dcda0(last,child);}
   else {w10(self,0x50)=(u32)child;ext_4dcda0(last,child);}
  }else prepend10(self,child);
 }else if(type10(child)&0x100000)append10(self,child);
 else prepend10(self,child);
 ++w10(self,0x4c);
 if(w10(p10(self,8),0x3c)&0x800)ext_4db860(child,1);
 if(vcall<u8>(tab10(),0x178) && !(w10(child,0x3c)&0x40000) && (u8)activate)ext_4690b0(child);
 if(p10(child,0x54) && type10(child)==0x20001c){u32 id=vcall<u32>(tab10(),0x50,child);vcall<void>(self,0x268,id);}
 void*parent=ext_4db7e0(p10(self,8));if(parent)vcall<void>(parent,0x2f8,child);
 parent=ext_4daff0(p10(self,8));if(parent)vcall<void>(parent,0x2f0,child);
 u8*data=p10(child,0x54);
 if((w10(child,0x3c)&0x40000) || ((type10(child)&0x100000) && (w10(data,0x30)&0x8000)))vcall<void>(self,0x284);
 data=p10(child,0x54);
 if((type10(child)&0x800000) || ((type10(child)&0x100000) && (w10(data,0x30)&0x10000))){
  u8*cur=self;do{w10(cur,0x30)|=0x10000;cur=vcall<u8*>(cur,0x20);}while(cur);
 }
 u8*root=p10(self,8);u32 flags=w10(root,0x3c);
 if(flags&0x40040000){void*owner=(flags&0x40000)?root:ext_4dafb0(root);ext_4dc840(child,owner);}
 flags=w10(child,0x3c);
 if(!(flags&0x200c00) && (flags&0x40000)){if(!w10(child,0x64))ext_4d9ce0(child);ext_4d9bf0(child);}
 return ext_4d9d20(child,0);
}
PCREG(43ef30,attach10);
