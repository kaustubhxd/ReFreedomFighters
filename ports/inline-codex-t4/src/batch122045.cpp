#include "ff.h"
extern "C" void THISCALL ext_4db2c0(u8*,float*,float*);
extern "C" void FASTCALL ext_4de440(float*,float*,float*);
extern "C" void FASTCALL ext_441970(float*,float*,float*);
extern "C" void FASTCALL ext_441940(float*,float*);
extern "C" void FASTCALL ext_4de420(float*,float*);
static void THISCALL fn461c40(u8* s){
 u8* link=*(u8**)(s+0x6c);*(u32*)(link+0x65)=0;*(u32*)(link+0x251)=0;
 if(!vcall<u8>(s,0x348))return;
 float base[9],position[3];u8* obj=vcall<u8*>(s,0x20);ext_4db2c0(*(u8**)(obj+8),base,position);
 float combined[9],v[3],matrix[9];ext_4de440(combined,(float*)(s+0x24),base);ext_441970(v,(float*)(s+0x48),base);ext_441940(v,position);ext_4de420(matrix,combined);
 float out[3]={v[0],v[1],v[2]};
 if(!vcall<u8>(s,0x1e0,(u32)0x2007d0)){obj=vcall<u8*>(s,0x20);vcall<void>(obj,0x74,matrix,out);return;}
 obj=vcall<u8*>(s,0x20);u8* group=vcall<u8*>(obj,0x20);vcall<void>(group,0x98,matrix,out);vcall<void>(s,0x7c,matrix,out);
}
PCREG(461c40,fn461c40);
