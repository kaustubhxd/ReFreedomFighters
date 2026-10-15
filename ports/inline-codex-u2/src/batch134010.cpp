#include "ff.h"
extern "C" void THISCALL ext_512590(u8*);
extern "C" float FASTCALL ext_4e0030(const float*,const float*);
extern "C" void THISCALL ext_4db7c0(void*,float*);
static void THISCALL fn515630(u8* s){
 ext_512590(s);float a[9],b[9],pa[3],pb[3];vcall<void>(s,0x80,a,pa);
 u8* source=s;if(G(u32,s+0x123))source=vcall<u8*>(G(void*,G(u8*,0x70039c)+0x9b),0x58,G(u32,s+0x123));
 vcall<void>(source,0x80,b,pb);
 bool warn=ext_4e0030(b+6,a+6)>G(float,0x69eb54);
 if(!warn)warn=ext_4e0030(b+3,a+3)>G(float,0x69eb54);
 if(!warn)warn=ext_4e0030(b,a)>G(float,0x69eb54);
 if(warn){
  void* log=vcall<void*>(G(void*,0x700390),0x20,0x69ea24u,0x8fu);
  u32 n1=G(u32,s+4),n2=G(u32,source+4);
  typedef void(*Print)(void*,u32,u32,u32);(*(Print*)(*(u8**)log+0x2c))(log,0x69eab8u,n1?n1:0x67c8e8u,n2?n2:0x67c8e8u);
 }
 ext_4db7c0(G(void*,source+8),(float*)(s+0x21b));
 G(float,s+0x227)=G(float,s+0x21b)+G(float,0x67cd40);
 G(float,s+0x22b)=G(float,s+0x21f)+G(float,0x69eb58);
 G(float,s+0x22f)=G(float,s+0x223)+G(float,0x67da2c);
}
PCREG(515630,fn515630);
