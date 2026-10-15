#include "ff.h"
extern "C" void THISCALL ext_4de7a0(float*);
extern "C" void THISCALL ext_4daf90(void*,float*);
extern "C" void THISCALL ext_4db600(void*,float*,float*);
extern "C" void THISCALL ext_4db7c0(void*,float*);
extern "C" void FASTCALL ext_4e2c60(float*,float*);
extern "C" void THISCALL ext_4e41e0(void*,float*,float*,u32);
static u8 THISCALL fn4bc150(u8*s,void*stream){
 *(u32*)(s+4)&=0xffffffbf;
 vcall<void>(stream,0x44,*(u32*)(s+0x48));
 const u32 first[]={0x4c,0x79,0x50,0x54,0x58,0x5c,0x60};
 for(u32 off:first)vcall<void>(stream,0x4c,*(u32*)(s+off));
 vcall<void>(stream,0x44,*(u32*)(s+0x64));vcall<void>(stream,0x44,*(u32*)(s+0x68));
 for(u32 off=0x6c;off<=0x74;off+=4)vcall<void>(stream,0x4c,*(u32*)(s+off));
 vcall<void>(stream,0x60,(u32)s[0x78]);return 1;
}
PCREG(4bc150,fn4bc150);
static void THISCALL fn441f40(void*s,void*geometry){
 void *tree=vcall<void*>(s,0x314);if(!tree)return;
 float matrix[9],position[3],extent[3];ext_4de7a0(matrix);
 ext_4daf90(geometry,position);ext_4db600(geometry,matrix,position);ext_4db7c0(geometry,extent);
 vcall<void>(s,0x94,matrix,position);ext_4e2c60(matrix,extent);
 float low[3],high[3];for(int i=0;i<3;i++){low[i]=position[i]-extent[i];high[i]=position[i]+extent[i];}
 u8 *sys=G(u8*,0x70039c);u32 id=vcall<u32>(*(void**)(sys+0x9b),0x50,geometry);
 ext_4e41e0(tree,low,high,id);
}
PCREG(441f40,fn441f40);
