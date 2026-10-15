#include "ff.h"
extern "C" void FASTCALL ext_43e920(float*,u8*,u8*);
extern "C" void FASTCALL ext_441a60(float*,u8*);
extern "C" void FASTCALL ext_4de4b0(float*,u8*,u8*);
extern "C" void FASTCALL ext_4de420(float*,float*);
static u8 THISCALL fn4599e0(u8* s,u8* view,u8* draw){
 u8* a=vcall<u8*>(view,0x3c);u8* b=vcall<u8*>(view,0x40);
 float delta[3];ext_43e920(delta,a+0x24,b+0x24);ext_441a60(delta,b);
 float rel[9],matrix[9];ext_4de4b0(rel,a,b);ext_4de420(matrix,rel);
 float pos[3]={delta[0],delta[1],delta[2]};
 vcall<void>(s,0x80,matrix,pos);vcall<void>(draw,0x94,matrix,pos);vcall<void>(s,0xdc,view,draw,matrix,pos);return 0;
}
PCREG(4599e0,fn4599e0);
