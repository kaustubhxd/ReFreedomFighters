#include "ff.h"
extern "C" void THISCALL ext_4e0d00(float*,float);
extern "C" void THISCALL ext_4de7a0(float*);
extern "C" void FASTCALL ext_4de7e0(float*,float*);
static void THISCALL fn4a93b0(u8* s){
  float delta[3]={G(float,s+0x8b),bitsf(fbits(G(float,s+0x8f))^0x80000000u),0};
  void* a=G(void*,s+0x44);
  if(vcall<u8>(a,0x1e0,0x10002eu)){
    u8* b=vcall<u8*>(a,0x2c4);
    float q[4]; vcall<void>(G(void*,b+0x6f),0x240,q);
    u8* sys=G(u8*,0x70039c);
    q[0]=float(G(s32,sys+0x6f))*q[0];
    q[2]=float(G(s32,sys+0x6f))*q[2];
    q[1]=float(G(s32,sys+0x73))*q[1];
    float x=q[2]*G(float,s+0x8b)+q[2]*G(float,0x67a6ac);
    q[3]=float(G(s32,sys+0x73))*q[3];
    float y=G(float,s+0x8f)*q[3]+q[3]*G(float,0x67a6ac);
    float out[3]={x,y,0}; vcall<void>(a,0x70,out);
  }else{
    void* b=G(void*,s+0x56); float pos[3];
    vcall<void>(b,0x278,delta,pos);
    ext_4e0d00(pos,G(float,0x690424)/G(float,(u8*)b+0x5c));
    vcall<void>(b,0x84,pos);
    float zero[3]={0,0,0}, mat[9]; ext_4de7a0(mat); ext_4de7e0(mat,zero);
    vcall<void>(b,0x88,mat+6); vcall<void>(b,0x88,mat+3); vcall<void>(b,0x88,mat);
    vcall<void>(G(void*,s+0x4e),0x7c,mat,pos);
  }
}
PCREG(4a93b0,fn4a93b0);
