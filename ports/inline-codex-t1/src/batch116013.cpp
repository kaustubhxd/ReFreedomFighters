#include "ff.h"
extern "C" long double FASTCALL ext_4e0870(void*,void*);
extern "C" void FASTCALL ext_451890(void*,void*,float);
static void THISCALL fn47a500(u8*s,u32 arg){
 if(!s[0x74e]){vcall<void>(s,0x128,(u32)G(u16,0x6ffa24),arg,0u);return;}
 float p[3]={0,0,0};vcall<void>(s,0x84,p);
 float distance=(float)ext_4e0870(s+0x742,p);
 if(!(distance>G(float,0x680a8c))){s[0x74e]=0;return;}
 float speed=distance>G(float,0x68af1c)?bitsf(0x3f99999a):G(float,0x67da2c)>distance?bitsf(0x3f666666):1.f;
 vcall<void>(s,0x624,speed);
 if(distance>G(float,0x68af14)){vcall<void>(s,0x634,s+0x742,0u);vcall<void>(s,0x5e8,0u);}
}
PCREG(47a500,fn47a500);
static void THISCALL fn5d4e80(void*self,u8*object,float*matrix,float*out){
 u8 *config=*(u8**)(object+8);float spread[3];for(int i=0;i<3;i++)spread[i]=*(float*)(config+0x40+4*i);
 u32 axes[3][3];for(int i=0;i<3;i++)for(int j=0;j<3;j++)axes[i][j]=((u32*)matrix)[(2-i)*3+j];
 float offsets[3];
 for(int i=0;i<3;i++){
  long double r=vcall<long double>(G(void*,0x70039c),0x1c0,0x6b53acu,(u32)(0x39+i));
  offsets[i]=(float)((r-(long double)G(float,0x67a6ac))*(long double)spread[i]);
 }
 for(int i=0;i<3;i++){float scale=offsets[i]+offsets[i];ext_451890(out,axes[i],scale);}
}
PCREG(5d4e80,fn5d4e80);
