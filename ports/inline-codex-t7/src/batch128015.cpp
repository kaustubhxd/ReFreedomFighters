#include "ff.h"
extern "C" void THISCALL ext_563610(void*,u32);
extern "C" u8* THISCALL ext_4db520(void*);
extern "C" u32 THISCALL ext_573b20(void*,u32,u32);
extern "C" u32 THISCALL ext_5747e0(void*);
static inline u32&w16(u8*p,u32 o){return *(u32*)(p+o);}
static inline void*tb16(){return *(void**)(G(u8*,0x70039c)+0x9b);}
static u32 res16(u32 name){void*res=vcall<void*>(tb16(),0x138);u32 ref=0;vcall<void>(res,0x88,name,&ref);return ref;}
static u8*lookup16(u32 id){return vcall<u8*>(tb16(),0x58,id);}
static u32 THISCALL init16(u8*self){
 ext_563610(self,0);
 const u32 names[]={0x6a8f58,0x6a8a74,0x6a8f60,0x6a8f6c,0x6a8f78,0x6a8f8c};
 const u32 offs[]={0x180,0x184,0x188,0x18c,0x1cc,0x1d0};
 for(u32 i=0;i<6;++i)w16(self,offs[i])=(u32)lookup16(res16(names[i]));
 const u32 children[]={0x6a8fa4,0x6a8fac,0x6a8fb8};
 for(u32 i=0;i<3;++i)w16(self,0x1e0+i*4)=vcall<u32>((void*)w16(self,0x1cc),0x25c,children[i],0u);
 vcall<void>((void*)w16(self,0x18c),0xbc,1u);
 const u32 refs[]={0x6a8fbc,0x6a8fc4,0x6a8fcc,0x6a8fd8};for(u32 i=0;i<4;++i)w16(self,0x1b8+i*4)=res16(refs[i]);
 u8*widget=lookup16(w16(self,0x1bc));void*parent=vcall<void*>(widget,0x20);u8*list=vcall<u8*>(parent,0x25c,0x6a8fe8u,0u);
 widget=lookup16(w16(self,0x1c4));parent=vcall<void*>(widget,0x20);w16(self,0x1d4)=vcall<u32>(parent,0x25c,0x6a8ff4u,0u);
 parent=vcall<void*>(widget,0x20);w16(self,0x1d8)=vcall<u32>(parent,0x25c,0x6a9000u,0u);
 u8*item=*(u8**)(list+0x54);
 while(item){
  u8*desc=*(u8**)(item+0x54);u32 type=desc?w16(*(u8**)(desc+12),0x23):0x200002;
  if(type&0x100000)break;
  u32 n=w16(self,0x1fe);if(n<8){w16(self,0x190+n*4)=(u32)desc;++w16(self,0x1fe);}
  item=ext_4db520(item);
 }
 w16(self,0x1ec)=ext_573b20(self,w16(self,0x1d4),0x6a9010);
 widget=lookup16(w16(self,0x1bc));
 if(widget){parent=vcall<void*>(widget,0x20);u8*target=vcall<u8*>(parent,0x25c,0x6a912cu,0u);u32 i=0;while(i<4 && w16(target,24+i*4))++i;if(i<4)w16(target,24+i*4)=(u32)self;w16(target,40)=1;}
 return ext_5747e0(self);
}
PCREG(573dd0,init16);
