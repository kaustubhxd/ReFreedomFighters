#include "ff.h"
extern "C" u8 *ext_41e290(u32);
extern "C" u32 ext_42ac56(u8*,u32,...);
extern "C" u32 THISCALL ext_4cc1d0(u8*);
extern "C" u32 THISCALL ext_4cc5f0(u8*);
extern "C" void ext_634273(void*,u32);
static inline u8 *ptr(u8 *p,u32 off=0){return *(u8**)(p+off);}
static inline u32 word(u8 *p,u32 off=0){return *(u32*)(p+off);}
static inline u8 *fs(){return *(u8**)0x700394;}
static inline u32 len(u8 *p){u32 n=0;while(p[n])++n;return n;}
static inline u8 *findch(u8 *p,u32 ch){typedef u8*(*Fn)(u8*,u32);return (*(Fn*)0x676254)(p,ch);}
static inline s32 cmp(u8 *p,u8*q,u32 n){typedef s32(*Fn)(u8*,u8*,u32);return (*(Fn*)0x67640c)(p,q,n);}
static inline void writeout(u32 f,u8 *p,u32 n){vcall<void>(fs(),0x38,f,p,n);}
static u8 THISCALL fn4338c0(u8 *self,u32 path){
 if((*(u8**)0x70039c)[0x6b])return 1;
 if(!vcall<u8>(fs(),0x34,path,(u32)0))return 0;
 u32 size=vcall<u32>(fs(),0x30,path,(u32)0);
 u8 *data=ext_41e290(size+1);
 vcall<void>(fs(),0x60,path,data,size,(u32)0,(u32)0);data[size]=0;
 u8 *log=vcall<u8*>(*(u8**)0x700390,0x20,(u32)0x679f78,(u32)0x342);
 typedef void(*Print)(u8*,u32,u32);(*(Print*)(ptr(log)+0x2c))(log,0x67a1c8,path);
 u32 file=vcall<u32>(fs(),0x14,path);
 u8 *lst=self+0xac;
 u32 cnt=vcall<u32>(lst,0x14)+1;
 u64 bytes=(u64)cnt*8;
 u32 *snap=(u32*)ext_41e290(bytes>0xffffffff?0xffffffff:(u32)bytes);
 u32 it[3]={0xcccccccc,0xcccccccc,0xcccccccc};
 vcall<void>(lst,0x4c,it);u8 *rec=vcall<u8*>(lst,0x64,it);u32 n=0;
 while(rec){snap[n*2]=word(rec);snap[n*2+1]=ext_4cc1d0(ptr(rec,4));++n;rec=vcall<u8*>(lst,0x64,it);}
 snap[n*2]=0;snap[n*2+1]=0;
 u8 *cur=data;
 while(data && *cur){
  u8 *next=findch(cur,10);
  if(!next)next=findch(cur,13);
  if(next)++next;else next=cur+len(cur);
  bool matched=false,skip=false;
  u32 iter[3]={0xcccccccc,0xcccccccc,0xcccccccc};
  u8 *ignore=self+0xc8;
  vcall<void>(ignore,0x4c,iter);
  u8 *prefix=vcall<u8*>(ignore,0x5c,iter);
  while(iter[0]){
   if(!cmp(cur,prefix,len(prefix))){skip=true;break;}
   prefix=vcall<u8*>(ignore,0x5c,iter);
  }
  if(!skip){
   for(u32 i=0;snap[i*2];++i){
    u8 *name=(u8*)snap[i*2];
    if(!cmp(cur,name,len(name))){
     matched=true;
     if(snap[i*2+1]){
      u8 buf[0x100];u32 l;
      if(snap[i*2+1])l=ext_42ac56(buf,0x6784f8,name,snap[i*2+1]);
      else l=ext_42ac56(buf,0x678500,name);
      writeout(file,buf,l);snap[i*2+1]=0;skip=true;break;
     }
    }
   }
   if(!matched){
    writeout(file,cur,(u32)(next-cur));
    if(next[-1]!=10){u32 extra=ext_4cc5f0(self+4);u32 str=ext_4cc1d0(self+4);writeout(file,(u8*)str,extra);}
   }
  }
  cur=next;
 }
 for(u32 i=0;snap[i*2];i++)if(snap[i*2+1]){
  u8 buf[0x100];u32 l=ext_42ac56(buf,0x6784f8,snap[i*2],snap[i*2+1]);writeout(file,buf,l);snap[i*2+1]=0;
 }
 vcall<void>(fs(),0x1c,file);
 ext_634273(snap,8);ext_634273(data,1);return 1;
}
PCREG(4338c0,fn4338c0);
