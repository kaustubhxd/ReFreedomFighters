#include "ff.h"
extern "C" void THISCALL ext_4db2a0(u8*,float*);
extern "C" void FASTCALL ext_4ddcb0(float*,float*,float);
extern "C" void FASTCALL ext_4de480(float*,float*);
extern "C" void THISCALL ext_4dcb90(u8*,float*);
extern "C" void THISCALL ext_5168b0(u8*);
static void THISCALL fn529e30(u8* s,float speed,float force){
 float axis[3]={1.f,0.f,0.f};float angle=*(float*)(G(u8*,0x70039c)+0x48)*speed;angle=angle/(*(float*)(s+0x14));
 if(*(float*)(s+0x2d)>=force){angle=0;*(u32*)(s+0x10)=2;}
 else if(force>=*(float*)(s+0x29)&&s[0x28]){float scale=force/(*(float*)(s+0x29));scale=scale+G(float,0x678858);angle=scale*angle;*(u32*)(s+0x10)=1;}
 else *(u32*)(s+0x10)=0;
 float matrix[9],rotation[9];ext_4db2a0(*(u8**)(*(u8**)(s+0x18)+8),matrix);
 ext_4ddcb0(rotation,axis,angle);ext_4de480(matrix,rotation);ext_4dcb90(*(u8**)(*(u8**)(s+0x18)+8),matrix);
 if(!G(u8*,0x7003b8)[0xab8])ext_5168b0(s+0x3d);ext_5168b0(s+0xb6);
}
PCREG(529e30,fn529e30);
