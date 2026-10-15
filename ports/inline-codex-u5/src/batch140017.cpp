#include "ff.h"
extern "C" u32 THISCALL ext_4e68e0(void*,u32);
extern "C" u32 THISCALL ext_4e6900(void*,u32);
extern "C" u8* THISCALL hash_find(u8* me,void* key){
 u32 a,b;vcall<void>(me,0x10,key,&a,&b);
 u32 index=ext_4e68e0(me,a),step=ext_4e6900(me,b),probes=0;
 for(;;){
  u32 bits=*(u32*)(*(u8**)(me+4)+(index>>5)*4);
  if((bits&(1u<<(index&31))) && vcall<u8>(me,0x14,*(u8**)(me+0x18)+8*index,key))break;
  index=(index+step)&(*(u32*)(me+8)-1);
  if(probes>*(u32*)(me+0x14))return 0;
  ++probes;
 }
 if(!(*(u32*)(*(u8**)(me+4)+(index>>5)*4)&(1u<<(index&31))))return 0;
 float n=(float)probes*G(float,0x67a284);
 float old=*(float*)(me+0x1c)*G(float,0x683768);
 *(float*)(me+0x1c)=n+old;
 return *(u8**)(me+0x18)+index*8;
}
PCREG(48f880,hash_find);
