#include "ff.h"
extern "C" u32 THISCALL ext_54db90(u8*,u8*);
typedef u8 *(THISCALL *console65002)(u8*);
typedef void (*printf65002)(u8*,u32,u32,u32,...);
static u8 *getconsole65002(){u8 *eng=G(u8*,0x70039c);return (*(console65002**)eng)[0x190/4](eng);}
static void THISCALL fn549e80(u8 *self){
  u8 *out=getconsole65002();
  (*(printf65002**)out)[0x184/4](out,0x50,0x46,0x6a3408,*(u32*)(self+0x8025));
  out=getconsole65002();
  (*(printf65002**)out)[0x184/4](out,0x50,0x47,0x6a3428);
  for(int i=0;i<*(s32*)(self+0x805d);++i){
    u8 *item=(*(u8***)(self+0x803d))[i];
    if(!item)continue;
    char text[22];
    for(int k=0;k<22;++k)text[k]=G(char,0x6a3430+k);
    char *active=text+(item[0x7d]?0:8);
    u8 *ref=*(u8**)(item+0x5d);
    char pcm[4]={'p','c','m',0},na[4]={'n','/','a',0};
    char *status=!ref?na:((*(u32*)(ref+8)&0x7fffffffu)==1?pcm:text+16);
    out=getconsole65002();
    if(ref){
      u32 extra=ext_54db90(self,ref);
      (*(printf65002**)out)[0x184/4](out,0x50,0x48+i,0x6a3448,status,(double)*(float*)(item+0x63d7),*(u32*)(ref+0xc),*(u32*)(ref+0x1c),active,extra);
    }else{
      (*(printf65002**)out)[0x184/4](out,0x50,0x48+i,0x6a3460);
    }
  }
}
PCREG(549e80,fn549e80);
