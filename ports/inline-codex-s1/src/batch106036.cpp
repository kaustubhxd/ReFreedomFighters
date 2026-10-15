#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(void*,u32);
extern "C" long double STDCALL ext_4dda90(float,float);
extern "C" void THISCALL ext_4db6c0(void*,void*,void*);
extern "C" u32 THISCALL ext_500360(void*,float);
extern "C" void ext_633654(u32);
static u32 THISCALL angle_difference(u8* me,u8* event){
 u8* cell=ext_5003d0(*(void**)(event+4),0);
 if(cell[4]!=0 && cell[4]!=1){
  void* sink=vcall<void*>(G(void*,0x700390),0x20,0x69c8e0,0x104);
  typedef void(*Print)(void*,u32,u32);(*(Print*)(*(u8**)sink+0x2c))(sink,0x69c6b0,0x69c938);
  ((void(*)())G(void*,0x7003b0))();
 }
 u32 id=*(u32*)cell;float result=0;
 if(id){
  u32 matrix[9],pos[3];vcall<void>(*(void**)(me+0xc),0x80,matrix,pos);
  float first=(float)ext_4dda90(bitsf(matrix[8]^G(u32,0x67af40)),bitsf(matrix[6]^G(u32,0x67af40)));
  void* target=vcall<void*>(*(void**)(G(u8*,0x70039c)+0x9b),0x54,id);
  ext_4db6c0(target,matrix,pos);
  long double second=ext_4dda90(bitsf(matrix[8]^G(u32,0x67af40)),bitsf(matrix[6]^G(u32,0x67af40)));
  result=(float)((second-(long double)first)*(long double)G(float,0x685274));
  G(float,0x700f74)=result;
  if(0.0f>result){result=result+G(float,0x690990);G(float,0x700f74)=result;}
 }
 u32 ret=ext_500360(ext_5003d0(*(void**)(event+8),0),result);
 ext_633654(0);return ret;
}
PCREG(500ee0,angle_difference);
