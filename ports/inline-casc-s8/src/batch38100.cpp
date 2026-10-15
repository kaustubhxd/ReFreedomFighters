#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define P(p,o) (*(u8 **)((u8 *)(p)+(o)))
extern "C" void FASTCALL ext_4e6a80(u8 *arr,u32 lo,u32 hi);
extern "C" u32 THISCALL ext_49c980(u8 *self,u8 *arr,u32 id);
extern "C" void THISCALL ext_49c6d0(u8 *out,u32 lo,u8 *start,u32 count);
extern "C" u8 THISCALL ext_49cbb0(u8 *self,u32 id,u8 *o,u32 flag);
extern "C" void THISCALL ext_49ccc0(u8 *self,u32 id,u8 *o,u32 flag);
extern "C" u32 THISCALL ext_49c310(u8 *self,u32 id,u8 *arr,u32 count);
typedef u32(THISCALL *logget)(u8 *,u32,u32);
typedef void (*logfn)(u32,u32);
static void logline(u32 line) {
  u8 *l=G(u8 *,0x700390);
  u32 x=((logget)U(P(l,0),0x20))(l,0x68ed40,line);
  ((logfn)U(P((u8 *)x,0),0x30))(x,0x68ed70);
}
static void link(u8 *s,u32 id,u8 *o) {
  if(ext_49cbb0(s,id,o,1)&1) ext_49ccc0(s,id,o,1);
}
static void THISCALL fn49b730(u8 *s,u32 n,u8 *target) {
  if(n>1) ext_4e6a80(P(s,0x35),0,n-1);
  u32 id=U(target,0x68);
  u32 packed=ext_49c980(s,P(s,0x39),id);
  u32 lo=packed&0xffff, count=packed>>16;
  if(count>1) ext_4e6a80(P(s,0x39),lo,lo+count-1);
  ext_49c6d0(P(s,0x3d),lo,P(s,0x39)+lo*4,count);
  u8 *cur=P(s,0x3d), *old=P(s,0x35);
  u32 endoff=(lo+count)*4;
  while((u32)cur<(u32)(P(s,0x3d)+endoff)) {
    u8 *x=P(cur,0);
    U(x,0x3c)|=0x1000000;
    if(old!=P(s,0x35)+n*4 && (u32)x>=U(old,0)) {
      if((u32)x==U(old,0)) { U(old,0)=0; cur+=4; }
      old+=4;
    } else {
      link(s,U(x,0x68),target);
      link(s,id,x);
      cur+=4;
    }
  }
  u32 keep=0;
  for(u32 i=0;i<n;++i) {
    u32 x=U(P(s,0x35),i*4);
    if(x) {
      if(i!=keep) U(P(s,0x35),keep*4)=x;
      ++keep;
    }
  }
  if(keep) {
    u32 got=ext_49c310(s,id,P(s,0x35),keep);
    if(got<keep) {
      logline(0x5d);
      for(u32 i=0;i<got;++i) {
        u8 *x=P(P(s,0x35),i*4);
        U(x,0x3c)|=0x1000000;
        link(s,id,x);
      }
      keep=0;
    }
  }
  for(u32 i=0;i<keep;++i) {
    u8 *tmp=target;
    u8 *x=P(P(s,0x35),i*4);
    u32 xid=U(x,0x68);
    u32 got=ext_49c310(s,xid,(u8 *)&tmp,1);
    U(x,0x3c)|=0x1000000;
    if(got!=1) {
      link(s,xid,target);
      link(s,id,x);
      logline(0x79);
    }
  }
  U(target,0x3c)|=0x1000000;
}
PCREG(49b730,fn49b730);
