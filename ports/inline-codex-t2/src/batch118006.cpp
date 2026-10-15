#include "ff.h"
extern "C" void THISCALL ext_527b30(void*);
extern "C" void THISCALL ext_529760(void*);
extern "C" void THISCALL ext_527710(void*);
extern "C" void FASTCALL ext_4de040(void*,void*,u32);
extern "C" void FASTCALL ext_4ddcb0(void*,void*,float);
extern "C" void FASTCALL ext_4de480(void*,void*);
extern "C" void THISCALL dynamics(u8* s){
 *(u32*)(s+0x21b5)=0x3ba3d70a;
 u32 ticks=G(u32,G(u32,0x70039c)+0x40)-(u32)_mm_cvttss_si32(_mm_set_ss(*(float*)(s+0x48)*G(float,0x678620)));
 float elapsed=(float)(s32)ticks*G(float,0x6785e4);
 s32 steps=_mm_cvttss_si32(_mm_set_ss(elapsed/G(float,0x69c69c)));
 if(steps>=10)steps=10;
 if(steps>0){
  for(s32 i=0;i<steps;++i)ext_527b30(s);
  if(steps>=10)*(float*)(s+0x48)=(float)G(s32,G(u32,0x70039c)+0x40)*G(float,0x6785e4);
  else *(float*)(s+0x48)=(float)steps**(float*)(s+0x21b5)+*(float*)(s+0x48);
 }
 ext_529760(s);ext_527710(s);
 float a=*(float*)(s+0x38),b=*(float*)(s+0x30);
 *(u32*)(s+0x50)=0;ext_4de040(s+0xc,s+0x4c,0);
 u32 mat1[9],mat2[9];ext_4ddcb0(mat1,s+0xc,a);ext_4ddcb0(mat2,s+0x24,b);
 ext_4de480(s+0xc,mat1);ext_4de480(s+0xc,mat2);
}
PCREG(527bd0,dynamics);
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" void FASTCALL ext_446ee0(void*,void*,void*);
extern "C" u8 THISCALL inside_tetra(void*,float* point,float* vertices){
 const u32 faces[12]={0,3,6,9,3,0,9,6,3,9,0,6};
 for(u32 i=0;i<4;++i){
  float origin[3],a[3],b[3],normal[3],offset[3];
  for(u32 k=0;k<3;++k)origin[k]=vertices[faces[3*i]+k];
  ext_43e920(a,vertices+faces[3*i+1],origin);
  ext_43e920(b,vertices+faces[3*i+2],origin);
  ext_446ee0(normal,b,a);
  ext_43e920(offset,point,origin);
  float dot=offset[0]*normal[0]+offset[1]*normal[1];dot=dot+offset[2]*normal[2];
  if(dot>0.0f)return 0;
 }
 return 1;
}
PCREG(451ba0,inside_tetra);
extern "C" u32 THISCALL ext_530e80(void*,void*,void*,u32,u32,float);
extern "C" u32 THISCALL end_cell(u8* s,u16* out,float* point,u8* exact){
 *exact=1;u8* grid=*(u8**)s;float extent[3];ext_43e920(extent,grid+0x12,grid+6);
 s32 x=_mm_cvttss_si32(_mm_set_ss(((point[0]-*(float*)(grid+6))/extent[0])*(float)*(s32*)(grid+0x3c)));
 s32 y=_mm_cvttss_si32(_mm_set_ss(((point[1]-*(float*)(grid+10))/extent[1])*(float)*(s32*)(grid+0x44)));
 s32 z=_mm_cvttss_si32(_mm_set_ss(((point[2]-*(float*)(grid+14))/extent[2])*(float)*(s32*)(grid+0x40)));
 u16 coord[3]={(u16)x,(u16)z,(u16)y};
 u32 ok=ext_530e80(*(void**)s,out,coord,10,3,1.0f);
 if(out[0]!=(u16)x || out[1]!=(u16)z)*exact=0;
 if(ok)return 1;
 *exact=0;return ext_530e80(*(void**)s,out,coord,15,15,0.1f)!=0;
}
PCREG(530ca0,end_cell);
extern "C" void THISCALL ext_52d750(void*,void*,u32,u32,u32,u32,u32,u32,u32,u32);
extern "C" u32 THISCALL nearest_cell(u8* grid,u16* out,u16* coord,u32 ryarg,u32 radiusarg,float epsilon){
 s32 x=coord[0],y=coord[1],z=coord[2],ry=(s16)ryarg,r=(s16)radiusarg;
 u32 box[7]={0x6a140c,(u32)(x-r),(u32)(y-r),(u32)(z-ry),(u32)(x+r),(u32)(y+r),(u32)z};
 u32 query[9]={0x6a1434,(u32)x,(u32)y,(u32)z,0,0,0,0x49742400,fbits(epsilon)};
 u32 context[5]={(u32)box,0,0,(u32)query,0xcccccc00};
 ext_52d750(grid,context,0x6e9034,*(u32*)(grid+0x38)-1,0,0,0,*(u32*)(grid+0x3c),*(u32*)(grid+0x40),*(u32*)(grid+0x44));
 out[0]=(u16)query[4];out[1]=(u16)query[5];out[2]=(u16)query[6];
 return G(float,0x6a1588)>=bitsf(query[7]);
}
PCREG(530e80,nearest_cell);
