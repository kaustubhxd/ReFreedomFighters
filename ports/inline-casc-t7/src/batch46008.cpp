#include "ff.h"
extern "C" u8 *THISCALL ext_5003d0(u8 *, u32);
extern "C" u8 THISCALL ext_4db9a0(u8 *, u32);
static inline u32 w(u8 *p,u32 o=0){return *(u32*)(p+o);}
static inline u8 *p(u8 *a,u32 o=0){return *(u8**)(a+o);}
static inline u8 *tab(){return p(*(u8**)0x70039c,0x9b);}
static inline u8 *get(u32 id){return vcall<u8*>(tab(),0x58,id);}
static void logmsg(u32 line,u32 file,u32 msg,bool assertion){
 u8 *l=vcall<u8*>(*(u8**)0x700390,0x20,file,line);
 typedef void(*Print2)(u8*,u32);
 typedef void(*Print3)(u8*,u32,u32);
 if(assertion){ (*(Print3*)(p(l)+0x2c))(l,0x69c6b0,msg); (*(void(**)())0x7003b0)(); }
 else (*(Print2*)(p(l)+0x2c))(l,msg);
}
static void STDCALL fn556a80(u8 *args){
 u8 *a=ext_5003d0(p(args,4),0);
 u32 name;
 if(a[4]==3) name=w(a);
 else if(a[4]==4) name=vcall<u32>(p(a),0x34);
 else {logmsg(0x111,0x69c8e0,0x69c9b0,true);name=0;}
 u32 v[3];
 for(u32 i=0;i<3;i++){
  u8 *a=ext_5003d0(p(args,4),i+1);
  if(a[4]!=0 && a[4]!=1) logmsg(0x104,0x69c8e0,0x69c938,true);
  v[i]=w(a);
 }
 u32 dst=v[0],src=v[1],param=v[2];
 if(!dst || (!vcall<u8>(get(dst),0x1e0,(u32)0x800001a) && !vcall<u8>(get(dst),0x1e0,(u32)0x100001))){
  logmsg(0x4bf,0x6a57fc,0x6a5d00,false);return;
 }
 u32 single=0;
 if(!vcall<u8>(get(src),0x1e0,(u32)0x800001a)){
  if(!vcall<u8>(get(src),0x1e0,(u32)0)) {logmsg(0x4ca,0x6a57fc,0x6a5d3c,false);return;}
  single=src;
 }
 u8 *source=get(src);
 u32 token=(u16)vcall<u32>(tab(),0x114,name,(u32)0,(u32)0x6a57fc,(u32)0x4d1);
 s32 count=single?0x186a0:vcall<s32>(p(source,0x18),0x14);
 if(vcall<u8>(get(dst),0x1e0,(u32)0x800001a)){
  u8 *dest=get(dst);
  s32 n=vcall<s32>(p(dest,0x18),0x14);
  if(n<count)count=n;
  for(s32 i=0;i<count;i++){
   u32 pair[2];
   pair[0]=single?single:vcall<u32>(p(source,0x18),0x30,(u32)i);
   pair[1]=param;
   u32 id=vcall<u32>(p(dest,0x18),0x30,(u32)i);
   vcall<void>(get(id),0x128,token,pair,(u32)0);
  }
 }else{
  u8 *dest=get(dst),*node=p(dest,8);
  s32 i=0;
  while(node){
   if(ext_4db9a0(node,0x2007f9)){
    u32 pair[2];
    if(single)pair[0]=single;
    else{
     if(i>=vcall<s32>(p(source,0x18),0x14))return;
     pair[0]=vcall<u32>(p(source,0x18),0x30,(u32)i);++i;
    }
    pair[1]=param;
    if(p(node,0x54))vcall<void>(p(node,0x54),0x128,token,pair,(u32)0);
   }
   vcall<void>(dest,0x50,&node);
  }
 }
}
PCREG(556a80,fn556a80);
