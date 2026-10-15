#include "ff.h"
extern "C" void THISCALL ext_4db670(void*,float*);
extern "C" void THISCALL ext_4de7a0(float*);
extern "C" void THISCALL ext_4dcb50(void*,float*,float*);
extern "C" void THISCALL ext_662b70(void*,u32);
extern "C" void THISCALL ext_662b00(void*,float);
extern "C" void THISCALL ext_6627c0(void*,float*);
static float* STDCALL fn4110c2(float*out,float*in){
 long double x=in[0],y=in[1],z=in[2];long double len=(x*x+y*y)+z*z;
 long double delta=len-(long double)G(float,0x678858);
 if(delta>=G(float,0x6972cc)&&delta<=G(float,0x6970c4)){
  if(out!=in)for(int i=0;i<3;i++)((u32*)out)[i]=((u32*)in)[i];
 }else if(len>(long double)G(float,0x6be138)){
  long double inv=(long double)G(float,0x678858)/fsqrt_x87(len);
  float tmp[3]={(float)(inv*in[0]),(float)(inv*in[1]),(float)(inv*in[2])};
  for(int i=0;i<3;i++)out[i]=tmp[i];
 }else{for(int i=0;i<3;i++)((u32*)out)[i]=0;}
 return out;
}
PCREG(4110c2,fn4110c2);
static void THISCALL fn51c2e0(u8*s,u8**out,void*wing){
 for(int i=0;i<5;i++){
  out[i]=vcall<u8*>(s,0x328,*(u32*)(s+0x44d),s,0x484c5731u);
  float a=(float)i/G(float,0x679544);a+=a;a*=G(float,0x67da18);
  float p[3]={(float)(crt::cos((double)a)*G(double,0x693d50)),(float)(crt::sin((double)a)*G(double,0x693d50)),-100.f};
  ext_4db670(wing,p);vcall<void>(s,0x8c,p);
  float m[9];ext_4de7a0(m);ext_4dcb50(*(void**)(out[i]+8),m,p);
 }
}
PCREG(51c2e0,fn51c2e0);
static void THISCALL fn5cd890(u8*s){
 if(s[0xab6]||s[0xb45]||!s[0xad4])return;
 u8 moving=s[0xb19];
 if(moving){
  float pitch=*(float*)(s+0xaed);bool dec;
  if(!*(u32*)(s+0xe1c))dec=G(float,0x6a0bc8)>=pitch||pitch>=0.f;
  else dec=G(float,0x6a0bd0)>=pitch||pitch>=G(float,0x69f19c);
  if(dec){u8 *sys=G(u8*,0x70039c);*(float*)(s+0xb05)-=*(float*)(sys+0x48);}
 }else{s[0xbe1]=1;s[0xbfe]=1;}
 if(0.f>*(float*)(s+0xb05))*(u32*)(s+0xb05)=0;
 if(!moving)return;
 // COMISS 0,timer / JB exits only for greater timer or unordered.
 if(!(0.f>=*(float*)(s+0xb05)))return;
 ext_662b70(s+0xbd5,0x800);ext_662b00(s+0xbd5,bitsf(0xbeb2b8c2));ext_6627c0(s+0xbd5,(float*)(s+0xaed));
 ext_662b70(s+0xbf2,0x800);ext_662b00(s+0xbf2,bitsf(0xbeb2b8c2));ext_6627c0(s+0xbf2,(float*)(s+0xa5c));
}
PCREG(5cd890,fn5cd890);
