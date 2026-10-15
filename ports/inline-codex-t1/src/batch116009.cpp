#include "ff.h"
extern "C" long double THISCALL ext_5162d0(void*);
extern "C" void THISCALL ext_525640(void*,void*,void*);
extern "C" void THISCALL ext_516360(void*,void*);
extern "C" long double FASTCALL ext_4e0870(void*,void*);
extern "C" float THISCALL ext_58b9c0(void*,float,void*,u32);
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
static void THISCALL fn5254c0(u8*s){
 for(s32 i=0;i<*(s32*)(s+0x8c);i++){
  u32 *src=(u32*)(s+0x7c9+0x163*i);u32 p[3]={src[0],src[1],src[2]};
  vcall<void>(*(void**)(s+0x88),0x84,p);ext_516360(s+0xbd+0xde*i,p);
 }
 for(s32 i=0;i<*(s32*)(s+0x90);i++){
  u32 *src=(u32*)(s+0xd55+0x133*i);u32 p[3]={src[0],src[1],src[2]};
  vcall<void>(*(void**)(s+0x88),0x84,p);ext_516360(s+0x435+0xde*i,p);
 }
}
PCREG(5254c0,fn5254c0);
static void THISCALL fn5935a0(u8*s,u8*event){
 if(!(*(float*)(event+5)>G(float,0x680a84)))return;
 long double distance=ext_4e0870(event+0x69,event+0x39);
 u8 *sys=G(u8*,0x70039c);float speed=(float)(distance/(long double)*(float*)(sys+0x48));
 if(G(float,0x68af1c)>speed)speed=0;
 float damage=speed* *(float*)(event+5);damage/=G(float,0x689060);
 void *other=vcall<void*>(*(void**)(sys+0x9b),0x4c,*(u32*)(event+1));
 ext_58b9c0(s,bitsf(fbits(damage)^G(u32,0x67af40)),other,1);
 if(G(float,0x679540)>*(float*)(s+0x7ff)){
  float delta[3];u32 zero[3]={0,0,0};ext_43e920(delta,event+0x69,event+0x39);
  vcall<void>(s,0x5bc,zero,delta,speed);
 }
}
PCREG(5935a0,fn5935a0);
