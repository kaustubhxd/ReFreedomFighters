#include "ff.h"
extern "C" long double FASTCALL ext_4e0030(void*,void*);
extern "C" void FASTCALL ext_4e0130(void*,void*,void*,float);
static void THISCALL updateDir(u8* me){
 vcall<void>(me,0x378);float* direction=(float*)(me+0x216);float* target=(float*)(me+0x222);
 double angle=(double)ext_4e0030(target,direction);double sine=crt::sin(angle);
 u64 bits=__builtin_bit_cast(u64,sine)&0x7fffffffffffffffULL;float scale=(float)__builtin_bit_cast(double,bits);
 float dt=G(float,G(u32,0x70039c)+0x48);ext_4e0130(direction,direction,target,dt*scale);
 if(direction[0]!=0||direction[1]!=0||direction[2]!=0){
 long double norm=(long double)direction[0]*direction[0];norm=norm+(long double)direction[1]*direction[1];norm=norm+(long double)direction[2]*direction[2];
 long double reciprocal=1.0L/fsqrt_x87(norm);direction[0]=(long double)direction[0]*reciprocal;direction[1]=(long double)direction[1]*reciprocal;direction[2]=(long double)direction[2]*reciprocal;
 }
}
PCREG(51da80,updateDir);
