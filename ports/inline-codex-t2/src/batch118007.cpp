#include "ff.h"
extern "C" void THISCALL ext_4e3180(void*);
extern "C" void FASTCALL ext_4de420(void*,void*);
extern "C" void FASTCALL ext_4e2c60(void*,void*);
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" void FASTCALL ext_43e8e0(void*,void*,void*);
extern "C" u32 THISCALL rooms_in_box(void*,void** out,u32 capacity,u8* table,u32* matrix,u32* center,u32* extent){
 u32 state[54];for(u32 i=0;i<54;++i)state[i]=0xcccccccc;
 ext_4e3180(state);state[1]=0x4ed840;state[23]=*(u32*)(table+0x14);state[24]=(u32)out;state[25]=capacity;state[26]=0;
 ext_4de420(state+27,matrix);
 for(u32 i=0;i<3;++i){state[36+i]=center[i];state[39+i]=extent[i];state[51+i]=extent[i];}
 ext_4e2c60(matrix,state+51);
 for(u32 i=0;i<3;++i)state[42+i]=state[51+i];
 ext_43e920(state+45,center,state+51);ext_43e8e0(state+48,center,state+51);
 vcall<void>(table,0x1c,state,state+45,state+48);
 for(u32 i=0;i!=state[26];++i)vcall<void>(out[i],0x378,0u,1u);
 return state[26];
}
PCREG(4ed390,rooms_in_box);
