#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
extern "C" void THISCALL ext_564b50(void *);
extern "C" void THISCALL ext_57fa80(void *,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32);
static void basic56(u8 *p,u32 name,u32 x=0,u32 y=0,u32 z=0,u32 fn=0,u32 obj=0,u32 scale=0x3f800000){ext_57fa80(p,name,0,x,y,z,fn,obj,0,0,scale,0);}
static void THISCALL init56ba10(u8 *s) {
 ext_564b50(s);u32 mode=U(s,0xcee);
 if(mode==1||mode==5||mode==2) {
  basic56(s+0x330,0x6a7bf0);s[0x359]=1;basic56(s+0x402,0x6a7bfc);s[0x42b]=1;basic56(s+0x456,0x6a7c08);s[0x47f]=1;basic56(s+0x3d8,0x6a7c18);s[0x401]=1;
  basic56(s+0x4d4,0x6a7c2c,0x6a7c28,0x6a7c24,0,0,U(s,0x94)+0x3b9);
  basic56(s+0x57c,0x6a7c40,0x6a7c28,0x6a7c24);return;
 }
 void *object=(void *)U(s,0xc5e);u32 first=vcall<u32>(object,0x1c),second=vcall<u32>(object,0x28);
 ext_57fa80(s+0x480,0x6a7c6c,0x6a7c5c,0,0,0x6a7c58,second,0,first,0,0x3f800000,0);
 basic56(s+0x2dc,0x6a7c7c,0x6a7c28,0x6a7c24,0,vcall<u32>((void *)U(s,0xc5e),0x14));
 basic56(s+0x42c,0x6a7c8c,0,0,0,0,U(s,0x94)+0x3b9,0x40000000);
 basic56(s+0x306,0x6a7c9c,0,0,0x6a7c58);
 basic56(s+0x42c,0x6a7c8c,0x6a7c28,0x6a7c24,0,0,U(s,0x94)+0x3b9);
 basic56(s+0x552,0x6a7ca8,0x6a7c28,0x6a7c24);
 basic56(s+0x2dc,0x6a7cb4,0,0,0x6a7c58,vcall<u32>((void *)U(s,0xc5e),0x14));
 if(U(s,0xcee)==4){basic56(s+0x4fe,0x6a7cc0,0x6a7c28,0x6a7c24);basic56(s+0x552,0x6a7cd8,0x6a7c28,0x6a7c24);}
}
PCREG(56ba10,init56ba10);
