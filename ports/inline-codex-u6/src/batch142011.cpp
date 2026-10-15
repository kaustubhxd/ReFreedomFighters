#include "ff.h"
extern "C" void* ext_41e290(u32);
static void init(){
 G(u32*,0x6ff978)=(u32*)ext_41e290(0x808);G(float*,0x6ff97c)=(float*)ext_41e290(0x1818);
 for(u32 i=0;i<256;i++){
  G(u32*,0x6ff978)[i]=i;
  for(int j=0;j<3;j++)G(float*,0x6ff97c)[3*i+j]=vcall<float>(G(void*,0x70039c),0x1c0,0x681348u,0x669u);
  float* p=G(float*,0x6ff97c)+3*i;
  if(p[0]!=0 || p[1]!=0 || p[2]!=0){
   long double x=p[0],y=p[1],z=p[2];long double length=fsqrt_x87(x*x+y*y+z*z);long double inv=1.0L/length;
   p[0]=(float)(x*inv);p[1]=(float)(y*inv);p[2]=(float)(z*inv);
  }
 }
 typedef u32(*Rand)();Rand random=G(Rand,0x67644c);
 for(u32 i=0;i<256;i++){u32 k=(u8)random();u32* tab=G(u32*,0x6ff978);u32 old=tab[i];tab[i]=tab[k];G(u32*,0x6ff978)[k]=old;}
 for(int i=0;i<258;i++){
  u32* tab=G(u32*,0x6ff978);tab[i+256]=tab[i];float* p=G(float*,0x6ff97c);
  for(int j=0;j<3;j++)p[3*i+j+768]=p[3*i+j];
 }
 G(u8,0x6ff980)=1;
}
PCREG(4513e0,init);
