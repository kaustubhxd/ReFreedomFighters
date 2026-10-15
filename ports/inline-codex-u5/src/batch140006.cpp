#include "ff.h"
extern "C" void THISCALL ext_4e2aa0(void*);
extern "C" void FASTCALL ext_4df1e0(void*,void*);
extern "C" void FASTCALL ext_4de440(void*,void*,void*);
extern "C" void FASTCALL ext_441970(void*,void*,void*);
extern "C" void FASTCALL ext_441940(void*,void*);
extern "C" void FASTCALL ext_4de420(void*,void*);
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" void FASTCALL ext_441a60(void*,void*);
extern "C" void FASTCALL ext_4de4b0(void*,void*,void*);
extern "C" u8 THISCALL start_motion(u8* me,void* rotation,void* position,float duration){
 u8* state=*(u8**)(me+0x1c);if(!(state[4]&1))return 0;
 *(u32*)(*(u8**)(state+0x14)+0x14)&=0xfffffdff;
 *(u32*)(state+4)|=2;
 float t=*(float*)(*(u8**)(state+0x14)+4);
 *(float*)(me+0x116)=t;*(float*)(me+0x112)=t+duration;
 vcall<void>(me,0x80,me+0xb2,me+0xd6);ext_4e2aa0(me+0xb2);
 float orient[4],pos[3],matrix[9],result[9],delta[3];
 state=*(u8**)(me+0x1c);
 vcall<void>(*(void**)(me+0x5c),0xc,*(u32*)(state+0x10),0u,pos,orient,*(float*)(me+0x112));
 ext_4df1e0(matrix,orient);ext_4de440(result,matrix,me+0xb2);
 ext_441970(delta,pos,me+0xb2);ext_441940(delta,me+0xd6);
 ext_4de420(matrix,result);
 for(int i=0;i<3;++i)pos[i]=delta[i];
 ext_43e920(delta,position,pos);ext_441a60(delta,matrix);
 ext_4de4b0(result,rotation,matrix);ext_4de420(me+0xe2,result);
 for(int i=0;i<3;++i)*(float*)(me+0x106+4*i)=delta[i];
 return 1;
}
PCREG(464270,start_motion);
