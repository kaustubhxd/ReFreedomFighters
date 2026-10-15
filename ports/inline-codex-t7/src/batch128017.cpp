#include "ff.h"
template<class R,class...A> static R a18(u32 at,A...v){return (*(R(STDCALL **)(A...))at)(v...);}
static inline u32&w18(u8*p,u32 o){return *(u32*)(p+o);}
static inline u8*sy18(){return G(u8*,0x70039c);}
static void log18(u32 line,u32 fmt,u32 a,u32 b){void*l=vcall<void*>(G(void*,0x700390),0x20,0x6c3a98u,line);((void(*)(void*,u32,u32,u32))(*(u32*)(*(u8**)l+0x2c)))(l,fmt,a,b);}
static void THISCALL window18(u8*self,u32 arg){
 s32 sw=a18<s32>(0x6761b4,16u),sh=a18<s32>(0x6761b4,17u),vw=a18<s32>(0x6761b4,78u),vh=a18<s32>(0x6761b4,79u);
 if(vw>sw)sw=vw;if(vh>sh)sh=vh;
 w18(sy18(),0x77)=w18(sy18(),0x6f);w18(sy18(),0x7b)=w18(sy18(),0x73);
 log18(0x977,0x6c3b64,w18(sy18(),0x6f),w18(sy18(),0x73));
 u8*sys=sy18();
 if(w18(sys,0x87)==0xffffffff){w18(sys,0x87)=sw/2-(s32)w18(sys,0x6f)/2;sys=sy18();w18(sys,0x8b)=sh/2-(s32)w18(sys,0x73)/2;sys=sy18();}
 u32 rect[4];u32 ex;
 if(sys[0x63]){ex=8;rect[0]=rect[1]=0;rect[2]=w18(sys,0x6f);rect[3]=w18(sys,0x73);}
 else{ex=512;rect[0]=w18(sys,0x87);rect[1]=w18(sys,0x8b);rect[2]=rect[0]+w18(sys,0x6f);rect[3]=rect[1]+w18(sys,0x73);}
 u32 mapping=a18<u32>(0x676044,0xffffffffu,0u,4u,0u,4u,0x6c3b78u);
 u32*view=a18<u32*>(0x67604c,mapping,2u,0u,0u,4u);
 if(view){u32 delta=w18(sy18(),0x6f)*(*view);rect[0]+=delta;rect[2]+=delta;++*view;a18<u32>(0x676048,view);}
 a18<u32>(0x676218,rect,0x86000000u,0u,ex);
 a18<u32>(0x6761fc,w18(self,0x133),0xfffffff0u,0x86000000u);a18<u32>(0x6761fc,w18(self,0x133),0xffffffecu,ex);
 a18<u32>(0x676208,w18(self,0x133),rect[0],rect[1],rect[2]-rect[0],rect[3]-rect[1],1u);
 a18<u32>(0x676210,w18(self,0x133),rect);
 sys=sy18();
 if((*(u8**)(sys+0x1aa3))[0x76]){
  void*l=vcall<void*>(G(void*,0x700390),0x20,0x6c3a98u,0x9b9u);
  ((void(*)(void*,u32,u32,u32,u32,u32))(*(u32*)(*(u8**)l+0x2c)))(l,0x6c3b84,rect[0],rect[1],rect[2],rect[3]);sys=sy18();
 }
 if(sys[0x63])vcall<void>(self,0xe0,w18(sys,0x6f),w18(sys,0x73));else vcall<void>(self,0xe0,rect[2]-rect[0],rect[3]-rect[1]);
 a18<u32>(0x6761b8,w18(self,0x133),arg);a18<u32>(0x676198,w18(self,0x133),5u);a18<u32>(0x6761f4,w18(self,0x133));
 a18<u32>(0x676214,w18(self,0x133),rect);
 s32 x=(s32)(rect[0]+rect[2])>>1,y=(s32)(rect[1]+rect[3])>>1;
 a18<u32>(0x676228,x,y);w18(self,0x68)=(u32)x;w18(self,0x6c)=(u32)y;vcall<void>(self,0x88,1u);
}
PCREG(6519a0,window18);
