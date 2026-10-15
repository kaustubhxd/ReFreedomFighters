#include "ff.h"
extern "C" void THISCALL ext_516230(void*,float*);
extern "C" void FASTCALL ext_43e960(float*,void*);
extern "C" void FASTCALL ext_441a60(float*,void*);
extern "C" void THISCALL ext_52a220(void*,float);
extern "C" void THISCALL ext_52a270(void*,float);
static void THISCALL wheels(u8* me){
 for(s32 i=0;i<*(s32*)(me+0x8c);i++){
  float p[3];ext_516230(me+0xbd+i*0xde,p);ext_43e960(p,me);ext_441a60(p,me+0xc);ext_52a220(me+0x7ad+i*0x163,p[1]);
 }
 for(s32 i=0;i<*(s32*)(me+0x90);i++){
  float p[3];ext_516230(me+0x435+i*0xde,p);ext_43e960(p,me);ext_441a60(p,me+0xc);ext_52a270(me+0xd39+i*0x133,p[1]);
 }
}
PCREG(526cf0,wheels);
