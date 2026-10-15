#include "ff.h"
extern "C" float FASTCALL ext_4e0830(float*,float*);
static void THISCALL fn585200(u8* s,float* pos){
 u8* mgr=*(u8**)(G(u8*,0x7003b8)+0x2c11);float radius=*(float*)(s+0x51);float squared=radius*radius;s32 it=-1;
 u8* p=vcall<u8*>(mgr,0x84,pos,radius,&it,(u32)-1);
 while(p){float matrix[9],center[3];vcall<void>(p,0x384,matrix,center);
  float dist=ext_4e0830(center,pos);if(!(dist>squared))vcall<void>(p,0x128,(u32)G(u16,0x71428c),pos,(u32)0);
  p=vcall<u8*>(mgr,0x84,pos,*(float*)(s+0x51),&it,(u32)-1);
 }
}
PCREG(585200,fn585200);
