#include "ff.h"
extern "C" void THISCALL ext_516470(void*,void*);
extern "C" void THISCALL ext_529d70(void*,void*);
extern "C" void THISCALL ext_516d10(void*,void*);
static void read24(void*stream,u32 slot,u8*self,u32 off){vcall<void>(stream,slot,self+off);}
static void ref24(void*stream,u8*self,u32 off,u32 &id){vcall<void>(stream,0x40,&id);void*tab=*(void**)(G(u8*,0x70039c)+0x9b);*(u32*)(self+off)=vcall<u32>(tab,0x58,id);}
static u8 THISCALL load24(u8*self,void*stream){
 read24(stream,0x6c,self,0);read24(stream,0x74,self,12);
 const u32 a[]={0x30,0x34,0x38,0x3c};for(u32 i=0;i<4;++i)read24(stream,0x50,self,a[i]);
 read24(stream,0x48,self,0x40);read24(stream,0x48,self,0x44);read24(stream,0x50,self,0x48);
 read24(stream,0x6c,self,0x4c);read24(stream,0x6c,self,0x58);
 for(u32 off=0x64;off<=0x78;off+=4)read24(stream,0x50,self,off);
 u32 id=(u32)stream;ref24(stream,self,0x89,id);
 read24(stream,0x48,self,0x8d);read24(stream,0x48,self,0x91);
 for(u32 i=0;i<8;++i)ext_516470(self+0x95+i*0xde,stream);
 for(u32 i=0;i<8;++i)ext_516470(self+0x785+i*0xde,stream);
 for(u32 i=0;i<8;++i)ext_529d70(self+0xe75+i*0x133,stream);
 for(u32 i=0;i<8;++i)ext_529d70(self+0x180d+i*0x133,stream);
 ref24(stream,self,0x21a5,id);ref24(stream,self,0x21a9,id);
 for(u32 off=0x21ad;off<=0x21bd;off+=4)read24(stream,0x50,self,off);
 read24(stream,0x6c,self,0x21c1);read24(stream,0x68,self,0x21cd);
 ext_516d10(self+0x21ce,stream);ext_516d10(self+0x2247,stream);
 read24(stream,0x48,self,0x22c0);read24(stream,0x50,self,0x22c4);read24(stream,0x50,self,0x22c8);read24(stream,0x68,self,0x84);
 return 1;
}
PCREG(528740,load24);
