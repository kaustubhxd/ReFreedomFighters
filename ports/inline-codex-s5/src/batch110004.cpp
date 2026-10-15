#include "ff.h"
extern "C" void FASTCALL ext_4de420(float*,float*);
extern "C" void FASTCALL ext_451890(float*,float*,float);
extern "C" u32 THISCALL ext_43ec00(void*);
#define A(T,p,o) (*(T*)((u8*)(p)+(o)))
static u32 THISCALL foot(u8*t,u32 right){
 u8*sys=G(u8*,0x70039c);void*dll=A(void*,sys,0x1a9f);
 if(!dll||!A(u32,t,0x14f))return 0;
 float m[9],p[3];
 if(A(u8,t,0x146)) {u32 x=vcall<u32>(t,(u8)right?0x3b8:0x3b4,m,p);vcall<void>(t,0x390,x);}
 else{u8*root=A(u8*,t,8);ext_4de420(m,(float*)root);for(int i=0;i<3;i++)p[i]=A(float,root,0x24+4*i);}
 ext_451890(p,m,10.f);
 u32 ground=A(u32,t,0x14b);if(!ground)ground=A(u32,t,0x147);
 u32 sound=vcall<u32>(dll,0x58,ground,A(u32,t,0x14f));
 if(!sound){u32 def=vcall<u32>(dll,0x5c,0x686078u);sound=vcall<u32>(dll,0x58,def,A(u32,t,0x14f));if(!sound)return 0;}
 u32 flag=12,ref=0;if(A(u8,t,0x144)){flag=4;ref=vcall<u32>(A(void*,sys,0x9b),0x4c,t);}
 void*handle=vcall<void*>(t,0x20,m,p,sound,flag,ref,0u);
 return ext_43ec00(handle);
}
PCREG(4670b0,foot);
