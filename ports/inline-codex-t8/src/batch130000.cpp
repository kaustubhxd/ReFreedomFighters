#include "ff.h"
extern "C" void THISCALL ext_4e7d90(u8*);
extern "C" void THISCALL ext_4cfb30(u8*,u32,u32);
extern "C" void* ext_634d10(void*,u32,u32);
extern "C" u8* THISCALL ext_5003d0(void*,u32);
static u8* THISCALL fn4cf940(u8* s,u32 a,u32 b,u32 d){
 ext_4e7d90(s+0x1cc); G(u32,s+0x1cc)=0x695d94; ext_4e7d90(s+0x1ea);
 G(u32,s+0x12138)=a;G(u32,s+0x1213c)=b;G(u32,s+0x12140)=d;
 G(u32,s+0x20b)=0;G(u32,s+0x821c)=~0u;G(u32,s+0x8220)=0;G(u32,s+0x8224)=0;s[0x821b]=0;
 G(u32,s)=0;G(u32,s+4)=b;G(u32,s+0x1c8)=0;s[0x1e9]=0;G(u32,s+0x1c4)=0;G(u32,s+0x207)=0;G(u32,s+0x20f)=~0u;
 for(u32 i=0;i<0x400;i++) G(u8*,s+0xc628+4*i)=s+0x8228+0x11*i;
 G(u32,s+0xd628)=0;G(u32,s+0xd62c)=0x400;
 for(u32 i=0;i<0x300;i++) G(u8*,s+0x11530+4*i)=s+0xd630+0x15*i;
 G(u32,s+0x12130)=0;G(u32,s+0x12134)=0x300;ext_634d10(s+0x217,0,0x8000);G(u32,s+0x213)=0x4210;
 if(b!=~0u){u32 q=(s32)(b+0x1fff)/8192;G(u32,s+0x8217)=q;
 if(d){if(q<=d)G(u32,s+0x8217)=d;else{void* l=vcall<void*>(G(void*,0x700390),0x20,0x695dc0u,0x6cu);typedef void(*log_t)(void*,u32);(*(log_t*)(*(u8**)l+0x2c))(l,0x695de8);}}
 G(u32,s+0x20f)=a;ext_4cfb30(s,a,b);}
 return s;
}
PCREG(4cf940,fn4cf940);
static u32 decode(u8* e){if(e[4]==3)return G(u32,e);if(e[4]==4)return vcall<u32>(G(void*,e),0x34);
 void* l=vcall<void*>(G(void*,0x700390),0x20,0x69c8e0u,0x111u);typedef void(*log_t)(void*,u32,u32);(*(log_t*)(*(u8**)l+0x2c))(l,0x69c6b0,0x69c9b0);typedef void(*assert_t)();G(assert_t,0x7003b0)();return 0;}
static u32 THISCALL fn5030f0(u8*s,u8*p){void*t=G(void*,p+4);u32 key=G(u32,ext_5003d0(t,0));u32 id=decode(ext_5003d0(t,1));u32 vals[4];for(u32 i=0;i<4;i++)vals[i]=G(u32,ext_5003d0(t,i+2));
 void*tab=G(void*,G(u8*,0x70039c)+0x9b);u32 h=vcall<u32>(tab,0x114,id,0u,0x69ca10u,0xf4u,vals);return vcall<u32>(G(void*,s+0xc),0x12c,key,h&0xffff);}
PCREG(5030f0,fn5030f0);
static u32 THISCALL fn5028e0(u8*s,u8*p){void*t=G(void*,p+4);u32 id=decode(ext_5003d0(t,1));void*tab=G(void*,G(u8*,0x70039c)+0x9b);u32 h=vcall<u32>(tab,0x114,id,0u,0x69ca10u,0x2a6u);u32 other=decode(ext_5003d0(t,2));u32 key=G(u32,ext_5003d0(t,0));return vcall<u32>(G(void*,s+0xc),0x12c,key,h&0xffff,other);}
PCREG(5028e0,fn5028e0);
