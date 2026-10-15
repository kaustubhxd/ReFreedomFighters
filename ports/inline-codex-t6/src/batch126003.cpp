#include "ff.h"
extern "C" void FASTCALL ext_60ff30(u32,u32,u32,u32);
extern "C" void FASTCALL ext_60feb0(u32,u32,u32,u32);
extern "C" void THISCALL ext_609a70(void*);
extern "C" float THISCALL ext_60d840(void*);
extern "C" float THISCALL ext_60d8e0(void*);
static void THISCALL render(u8* me,u8* input,u32 mode){
 u32 flags=G(u32,me+0x115f);void* device=(void*)G(u32,me+0x1377);
 if(flags&1){u32 state=(flags&2)?(4+((mode&255)!=0)):2;
 u32 texture=G(u32,input+0x38);if(G(u32,0x724848)!=texture){G(u32,0x724848)=texture;void* d=G(void*,0x724a00);typedef void(STDCALL *fn)(void*,u32,u32);(*(fn*)(*(u8**)d+0xf4))(d,0,texture);}
 ext_60ff30(0,state,2,0);ext_60feb0(0,state,2,0);
 float matrix[16];ext_609a70(matrix);matrix[8]=ext_60d840(input);matrix[9]=ext_60d8e0(input);
 typedef void(STDCALL *fn)(void*,u32,void*);(*(fn*)(*(u8**)device+0x94))(device,0x10,matrix);
 }
}
PCREG(612030,render);
