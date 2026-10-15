#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define H(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define P(p,o) (*(u8 **)((u8 *)(p)+(o)))
extern "C" u8 *THISCALL ext_659000(u8 *p);
extern "C" u32 STDCALL ext_6496e0(u8 *p);
typedef void (*qsortfn)(void *,u32,u32,u32);
typedef u32 (*assertfn)();
struct Entry {u32 key; u8 *p;};
static void THISCALL fn64ead0(u8 *s) {
  Entry tmp[8192];
  Entry *base=(Entry *)(s+0x28);
  u32 n=U(s,0x20),i=0;
  while(i<n && (base[i].p[5]&1) && !(base[i].p[5]&8)) ++i;
  u32 keep=i;
  for(;i<n;++i) {
    u8 *p=base[i].p;
    u8 flags=p[5];
    if(flags&1) {
      if(flags&8) {
        H(p,0x12)=0xffff;
        u8 *queue=P(s,0x181c5);
        u32 count=U(queue,0);
        if(count+1>0x2000) G(assertfn,0x7003b0)();
        P(queue,4+count*4)=p;
        ++U(queue,0);
      } else {
        base[keep]=base[i];
        H(p,0x12)=(u16)keep;
        ++keep;
      }
    } else H(p,0x12)=0xffff;
  }
  U(s,0x20)=keep;
  u8 *queue=P(s,0x181c5);
  u32 total=U(queue,0),add=0;
  for(u32 j=0;j<total;++j) {
    u8 *p=P(P(s,0x181c5),4+j*4);
    if(!(p[5]&1)) continue;
    u8 *a=P(p,8), *d=P(a,0x10), *obj=P(d,8);
    u32 id=0;
    u8 *res=H(a,0xa) ? ext_659000(a) : P(d,0x10);
    if(res) id=H(P(res,0xc),0);
    u8 *material=P(P(p,0x14),0x20);
    u32 b=material ? material[0x70] : 0;
    u32 part=p[0x10];
    u32 code=ext_6496e0(obj);
    u32 key=(((b<<8)|part)<<4)|code;
    key=(key<<11)|(id&0x7ff);
    key=(key<<4)|H(obj,2);
    tmp[add++]={key,p};
  }
  if(!add) return;
  G(qsortfn,0x676450)(tmp,add,8,0x64a6d0);
  u32 old=U(s,0x20);
  U(s,0x20)=old+add;
  u32 remain=add;
  if(old) {
    u32 dst=old+add-1;
    do {
      Entry ent;
      if(tmp[remain-1].key>base[old-1].key) ent=tmp[--remain];
      else ent=base[--old];
      base[dst]=ent;
      H(ent.p,0x12)=(u16)dst;
      if(!remain || !old) break;
      --dst;
    } while(true);
  }
  for(u32 j=0;j<remain;++j) {
    base[j]=tmp[j];
    H(tmp[j].p,0x12)=(u16)j;
  }
}
PCREG(64ead0,fn64ead0);
