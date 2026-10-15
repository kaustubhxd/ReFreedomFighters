#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
extern "C" u32 ext_62c270(void *,u32,u32,u32 *,u32 *,u32 *,u32 *);
extern "C" s32 ext_62c600(void *,u32,u32);
extern "C" u32 ext_628ee0(s32);
typedef u32 (*Compare628)(void *,u32,u32,u32);
typedef u32 (*Convert628)(void *,u32,u32);
static u32 parse628810(Convert628 convert,u32 mode,u8 *s,u32 pos,u32 end,u32 *err,u32 *o0,u32 *o1,u32 *o2,u32 *o3,u32 *o4) {
 u32 start=0,len=0,tok=0;pos+=U(s,0x44)*5;end-=U(s,0x44)*2;
 u32 edi; s32 ch;
 if(!ext_62c270(s,pos,end,&tok,&len,&start,&pos)||!tok)goto fail;
 edi=tok;
 if(!((Compare628)U(s,0x1c))(s,edi,len,0x6bf6f8)) {if(!mode)goto tokenfail;goto second;}
 if(o0)*o0=start;if(o1)*o1=pos;
 if(!ext_62c270(s,pos,end,&tok,&len,&start,&pos))goto fail;
 edi=tok;if(!edi){if(!mode)return 1;goto fail;}
second:
 if(((Compare628)U(s,0x1c))(s,edi,len,0x6bf700)) {
  edi=start;ch=ext_62c600(s,edi,end);
  if(!((ch>=97&&ch<=122)||((u32)(ch-65)<=25)))goto tokenfail;
  if(o2)*o2=edi;
  if(o3)*o3=convert(s,edi,pos-U(s,0x44));
  if(!ext_62c270(s,pos,end,&tok,&len,&start,&pos))goto fail;
  edi=tok;if(!edi)return 1;
 }
 if(!((Compare628)U(s,0x1c))(s,edi,len,0x6bf70c)||mode)goto tokenfail;
 edi=pos;
 if(((Compare628)U(s,0x1c))(s,start,edi-U(s,0x44),0x6bf718)) {if(o4)*o4=1;}
 else if(((Compare628)U(s,0x1c))(s,start,edi-U(s,0x44),0x6bf71c)) {if(o4)*o4=0;}
 else {*err=start;return 0;}
 if(ext_628ee0(ext_62c600(s,edi,end))) {
  do {edi+=U(s,0x44);}while(ext_628ee0(ext_62c600(s,edi,end)));
 }
 if(edi==end)return 1;
 *err=edi;return 0;
tokenfail:*err=edi;return 0;
fail:*err=pos;return 0;
}
PCREG(628810,parse628810);
