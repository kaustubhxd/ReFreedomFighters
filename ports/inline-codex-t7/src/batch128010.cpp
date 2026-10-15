#include "ff.h"
extern "C" u8* ext_634df4(u32,u32);
extern "C" u8* ext_634d58(u32);
extern "C" u32 ext_407ed0(u32);
extern "C" void ext_406590(void*,u32);
extern "C" u32 ext_406470(u32,s32,s32,s32);
extern "C" void ext_405710(void*,u32);
extern "C" void ext_4057b0(void*,u32);
static inline u32 &w11(u8*p,u32 off){return *(u32*)(p+off);}
static u32 init11(u8*out,u8*arg,u32 flag){
 u8*src=*(u8**)(arg+0x1c);for(u32 i=0;i<0x70;++i)out[i]=0;
 u8*s=ext_634df4(1,200);w11(out,0x68)=(u32)s;w11(out,4)=(u32)arg;
 w11(s,0x34)=ext_407ed0(w11(src,8));
 w11(s,0x24)=(u32)ext_634df4(1,4);w11(s,0x28)=(u32)ext_634df4(1,4);
 w11((u8*)w11(s,0x24),0)=(u32)ext_634df4(1,20);w11((u8*)w11(s,0x28),0)=(u32)ext_634df4(1,20);
 ext_406590((void*)w11((u8*)w11(s,0x24),0),w11(src,0));ext_406590((void*)w11((u8*)w11(s,0x28),0),w11(src,4));
 u32 one=(u32)ext_634df4(1,4);w11(s,4)=w11(s,8)=w11(s,12)=w11(s,16)=one;
 for(u32 off=20;off<=32;off+=4)w11(s,off)=(u32)ext_634df4(1,4);
 s32 a=(s32)w11(src,0),b=(s32)w11(src,4);
 w11((u8*)w11(s,4),0)=ext_406470(0,a,a/2,a/2);
 w11((u8*)w11(s,20),0)=ext_406470(0,b,a/2,a/2);
 w11((u8*)w11(s,24),0)=ext_406470(0,b,a/2,b/2);
 w11((u8*)w11(s,28),0)=ext_406470(0,b,b/2,a/2);
 w11((u8*)w11(s,32),0)=ext_406470(0,b,b/2,b/2);
 w11(s,44)=(u32)ext_634df4(w11(src,28),28);
 for(s32 i=0;i<(s32)w11(src,28);++i){void*dst=(u8*)w11(s,44)+i*28;u32 value=w11(src,0x924+i*4);if(flag)ext_405710(dst,value);else ext_4057b0(dst,value);}
 if(flag)w11(out,0)=1;
 w11(out,16)=0x2000;
 w11(out,8)=(u32)ext_634d58(w11(arg,4)*4);w11(out,12)=(u32)ext_634d58(w11(arg,4)*4);
 for(s32 i=0;i<(s32)w11(arg,4);++i)((u32*)w11(out,8))[i]=(u32)ext_634df4(w11(out,16),4);
 w11(out,36)=0;w11(out,40)=0;w11(out,48)=w11(out,20)=(s32)w11(src,4)/2;
 w11(s,56)=(u32)ext_634df4(w11(src,8),4);
 for(s32 i=0;i<(s32)w11(src,8);++i){
  u8*item=(u8*)w11(src,36+i*4);u32 type=w11(item,12);
  u32 table=G(u32,0x6f1dd8+4*w11(src,0x124+type*4));
  typedef u32(*Factory)(u8*,u8*,u32);
  ((u32*)w11(s,56))[i]=(*(Factory*)(table+8))(out,item,w11(src,0x224+type*4));
 }
 return 0;
}
PCREG(401970,init11);
