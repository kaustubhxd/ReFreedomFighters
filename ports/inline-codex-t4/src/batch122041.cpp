#include "ff.h"
extern "C" void THISCALL ext_529e30(u8*,float,float);
extern "C" void THISCALL ext_52a0b0(u8*,float);
static void THISCALL fn525f30(u8* s){
 float h=*(float*)(s+0xa8)**(float*)(s+0x74);h=h*G(float,0x67a6ac);float mid=*(float*)(s+0x68)**(float*)(s+0x7c);float low=mid-h,high=h+mid;
 for(s32 i=0;i<*(s32*)(s+0x8c);i+=2){u8* p=s+0x940+355*i;
  ext_529e30(p-0x163,mid,*(float*)(s+0x6c));ext_529e30(p,mid,*(float*)(s+0x6c));
  ext_52a0b0(p-0x193,*(float*)(s+0x78)**(float*)(s+0x7c));ext_52a0b0(p-0x30,*(float*)(s+0x78)**(float*)(s+0x7c));
 }
 for(s32 i=0;i<*(s32*)(s+0x90);i+=2){u8* p=s+0xe6c+307*i;ext_529e30(p-0x133,high,*(float*)(s+0x6c));ext_529e30(p,low,*(float*)(s+0x6c));}
}
PCREG(525f30,fn525f30);
