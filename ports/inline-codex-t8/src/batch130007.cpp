#include "ff.h"
extern "C" u32 THISCALL ext_658f50(void*);
extern "C" u8* THISCALL ext_658f10(void*,u32);
extern "C" void THISCALL ext_63ef00(void*,void*);
extern "C" s32 ext_410de0(void*,u32);
extern "C" void* ext_634df4(u32,u32);
extern "C" void ext_401320(void*,void*,u32);
extern "C" void ext_401020(void*);
static void enqueue(u8*s,u8*p){p[5]&=0xfe;G(u32,p)=G(u32,G(u8*,0x70039c)+0x3c);u8*ring=G(u8*,s+0x1005d)+0x268;G(u32,p)=G(u32,G(u8*,0x70039c)+0x3c);u8*w=G(u8*,ring);u16 idx=(u16)((s32)(w-ring-8)>>2);G(u8*,w)=p;w+=4;if(w==ring+0x8008)w=ring+8;G(u8*,ring)=w;G(u16,p+6)=idx;}
static void THISCALL fn64d6b0(u8*s,u8*p){enqueue(s,p);void*list=G(void*,p+8);u32 count=ext_658f50(list);for(u32 i=0;i<count;i++){u8*e=ext_658f10(list,i);if(!e)continue;u32 idx=G(u16,e+0x40)&0xfff;u8*child=G(u8*,G(u8*,s+0x10071)+4*idx);G(u32,child+0xc)--;if(G(u32,child+0xc))continue;enqueue(s,child);u8*o=G(u8*,child+8);o[8]--;if(!o[8])ext_63ef00(G(void*,s+0x1005d),o);}}
PCREG(64d6b0,fn64d6b0);
static s32 fn401430(u8*out,void*reader){s32 len=ext_410de0(reader,32);if(len<0)goto fail;{void*data=ext_634df4((u32)len+1,1);G(void*,out+0xc)=data;ext_401320(reader,data,len);s32 count=ext_410de0(reader,32);G(s32,out+8)=count;if(count<0)goto fail;G(void*,out)=ext_634df4((u32)count+1,4);G(void*,out+4)=ext_634df4((u32)G(s32,out+8)+1,4);
 for(s32 i=0;i<G(s32,out+8);i++){s32 n=ext_410de0(reader,32);if(n<0)goto fail;G(u32,G(u8*,out+4)+4*i)=n;void*p=ext_634df4((u32)n+1,1);G(void*,G(u8*,out)+4*i)=p;ext_401320(reader,p,n);}if(ext_410de0(reader,1)==1)return 0;}
fail:ext_401020(out);return -133;}
PCREG(401430,fn401430);
static u8 THISCALL fn437c90(u8*s,u8*name){void*t=G(void*,s+0x19);if(!t)return 0;u32 it[3];vcall<void>(t,0x4c,it);u8*p=vcall<u8*>(G(void*,s+0x19),0x5c,it);while(it[0]){if(p){typedef s32(*cmp_t)(u8*,u8*);if(G(cmp_t,0x676414)(name,G(u8*,p+4))==0){u32 type=G(u32,p);if(type==1)return (u8)vcall<u32>(G(void*,s+0x11),0x30,p,0u);if(type==0)return (u8)vcall<u32>(G(void*,s+0x11),0x34,p-4,0u);return 0;}}p=vcall<u8*>(G(void*,s+0x19),0x5c,it);}return 0;}
PCREG(437c90,fn437c90);
static void THISCALL fn4d1140(u8*s,u8*ptr){if(!ptr)return;u8*start=ptr-4;u32 size=G(u32,start);u8*first=0;for(u32 i=0;i<G(u32,s+8);i++){u8*slot=G(u8*,s)+8*i;bool merge=false;if(start+size==G(u8*,slot)){G(u8*,slot)=start;merge=true;}else if(G(u8*,slot)+G(u32,slot+4)==start){start=G(u8*,slot);merge=true;}
 if(merge){size+=G(u32,slot+4);G(u32,slot+4)=size;if(first){u32 n=--G(u32,s+8);u8*last=G(u8*,s)+8*n;if(first!=last){G(u32,first)=G(u32,last);G(u32,first+4)=G(u32,last+4);}return;}first=slot;}}
 if(first)return;u32 n=G(u32,s+8);if(n<G(u32,s+4)){u8*slot=G(u8*,s)+8*n;G(u32,s+8)=n+1;if(slot){G(u8*,slot)=start;G(u32,slot+4)=size;return;}}
 void*l=vcall<void*>(G(void*,0x700390),0x20,0x695ec0u,0xecu);typedef void(*print_t)(void*,u32);(*(print_t*)(*(u8**)l+0x2c))(l,0x695f3c);}
PCREG(4d1140,fn4d1140);
