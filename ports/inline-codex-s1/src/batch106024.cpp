#include "ff.h"
extern "C" void THISCALL ext_4de7a0(void*);
extern "C" void* THISCALL ext_5003d0(void*,u32);
extern "C" u32 THISCALL ext_5002f0(void*,u32);
extern "C" void ext_633654(u32);
static u32 THISCALL classify_up(u8* me,u8* arg){
 u8* actor=*(u8**)(me+0x1c);u32 mode=0;
 if(!vcall<u8>(*(void**)(actor+0x6c),0x34)){
  float matrix[9],pos[3]={0,0,0};ext_4de7a0(matrix);
  actor=*(u8**)(me+0x1c);u8* saved=*(u8**)actor;
  u32 id=vcall<u32>(actor,0x3a8,matrix,pos);
  actor=*(u8**)(me+0x1c);
  typedef void(THISCALL *Set)(void*,u32);(*(Set*)(saved+0x390))(actor,id);
  vcall<void>(*(void**)(me+0x1c),0x98,matrix,pos);
  float dot=(matrix[6]*0.0f+matrix[7])+matrix[8]*0.0f;
  mode=dot>0.0f?2:1;
 }
 u32 result=ext_5002f0(ext_5003d0(*(void**)(arg+8),0),mode);
 ext_633654(0);return result;
}
PCREG(5588e0,classify_up);
