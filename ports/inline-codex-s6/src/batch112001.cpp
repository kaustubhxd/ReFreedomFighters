#include "ff.h"
extern "C" {
 u8 THISCALL ext_4db9a0(void*,u32);
 void FASTCALL ext_43e920(void*,void*,void*);
 void FASTCALL ext_43e8e0(void*,void*,void*);
 void FASTCALL ext_4dfd80(void*,void*);
 void FASTCALL ext_441940(void*,void*);
 void FASTCALL ext_4e0900(void*,void*);
 void FASTCALL ext_4e08d0(void*,void*);
 void THISCALL ext_4e0d00(void*,u32);
}
static void THISCALL bounds(u8*me,void*sum,void*diff){
 u32 low[3]={0x7e967699,0x7e967699,0x7e967699},high[3]={0xfe967699,0xfe967699,0xfe967699};
 for(u8*p=*(u8**)(me+0x50);p;p=*(u8**)(p+0x60)){
 if(*(u32*)(p+0x3c)&0xc00)continue;
 u32 a[3],b[3];
 if(ext_4db9a0(p,0x10002e)){
 u32 x[3],y[3];vcall<void>(*(void**)(p+0x54),0x2d4,x,y);
 ext_43e920(a,x,y);ext_43e8e0(b,x,y);
 }else{
 ext_43e920(a,p+0x30,p+0x40);ext_43e8e0(b,p+0x30,p+0x40);
 if(ext_4db9a0(p,0x20002c)){
 auto o=*(void**)(p+0x54);ext_4dfd80(a,vcall<void*>(o,0x268));ext_4dfd80(b,vcall<void*>(o,0x268));
 }}
 ext_441940(a,p+0x24);ext_441940(b,p+0x24);ext_4e0900(low,a);ext_4e08d0(high,b);
 }
 ext_43e8e0(sum,high,low);ext_43e920(diff,high,low);ext_4e0d00(sum,0x3f000000);ext_4e0d00(diff,0x3f000000);
}
PCREG(4eeed0,bounds);
