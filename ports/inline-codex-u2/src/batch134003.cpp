#include "ff.h"
extern "C" void FASTCALL ext_4de420(float*,const float*);
extern "C" void FASTCALL ext_4dfd80(float*,const float*);
static void THISCALL fn4eed30(u8* self,void* viewport,u8* camera,const float* matrix,const float* input,float* out,float* scale,float* matrixout){
 ext_4de420(matrixout,matrix);for(int i=0;i<3;++i)out[i]=input[i];
 float rect[4];vcall<void>(camera,0x240,rect);
 float w=float(vcall<s32>(viewport,0))*rect[2];
 float h=float(vcall<s32>(viewport,4))*rect[3];
 out[0]=out[0]-w*G(float,0x67a6ac);out[1]=out[1]-h*G(float,0x67a6ac);out[2]=out[2]+G(float,0x685280);
 ext_4dfd80(out,(float*)(self+0x3e));
 float x=G(float,self+0x22),y=G(float,self+0x26);
 out[0]=(x==0)?0:(G(float,0x678858)/x)*out[0];out[1]=(y==0)?0:(G(float,0x678858)/y)*out[1];
 float z=G(float,camera+0x58)/out[2];float zw=z*w,zh=z*h;float aspect=(w/h)*zh;
 scale[0]=x/zw;scale[1]=bitsf(fbits(y/aspect)^0x80000000u);scale[2]=1;
}
PCREG(4eed30,fn4eed30);
