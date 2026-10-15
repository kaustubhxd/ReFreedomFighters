#include "ff.h"
extern "C" void FASTCALL ext_4e0d40(void*,void*,float);
extern "C" void FASTCALL ext_43e8e0(void*,void*,void*);
static void THISCALL randomTransform(u8* me){
 float offset[6];for(int i=0;i<6;++i){long double random=vcall<long double>(G(void*,0x70039c),0x1c0,0x695494,0x1ad+i);offset[i]=(float)(random*(long double)G(float,me+0x48+4*i));}
 float matrix[9],pos[3];float s=offset[3]/G(float,0x67cd40);s=s+G(float,0x678858);ext_4e0d40(matrix+6,me+0x84,s);
 s=offset[4]/G(float,0x67cd40);s=s+G(float,0x678858);ext_4e0d40(matrix+3,me+0x78,s);
 s=offset[5]/G(float,0x67cd40);s=s+G(float,0x678858);ext_4e0d40(matrix,me+0x6c,s);
 ext_43e8e0(pos,offset,me+0x60);vcall<void>(G(void*,me+0x44),0x7c,(void*)matrix,(void*)pos);
}
PCREG(4c9a00,randomTransform);
