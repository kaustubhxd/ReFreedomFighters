#include "ff.h"
extern "C" void ext_421870(u32,...);
extern "C" u32 FASTCALL ext_421500(u32);
static inline u32 w15(u8*p,u32 o){return *(u32*)(p+o);}
static void dump15(u32 unused,u8*arg){
 u32 time=0xcccccccc;(*(u32(**)(u32*))0x676438)(&time);u32 date=(*(u32(**)(u32*))0x676440)(&time);
 ext_421870(0x677a70,date);u8*rec=*(u8**)arg;ext_421870(0x677ac4,(u32)rec);
 u32 name=0x677a44;
 for(u32 i=0;G(u32,0x6e40d8+i*8);++i)if(G(u32,0x6e40d8+i*8)==w15(rec,0)){name=G(u32,0x6e40dc+i*8);break;}
 ext_421870(0x677ae0,w15(rec,0),name);
 ext_421870(0x677b2c,w15(rec,4),w15(rec,4)?0x677af8:0x677b14);
 u32 described=ext_421500(w15(rec,12));ext_421870(0x677b44,w15(rec,12),described);
 ext_421870(0x677b64,w15(rec,16)?0x677b5a:0x677b5c);
 for(u32 i=0;i<w15(rec,16);++i)ext_421870(0x677b74,w15(rec,20+i*4));
 ext_421870(0x677bb0,w15(rec,8),w15(rec,8)?0x677b88:0x677ba0);
 ext_421870(0x677bc8);ext_421870(0x677bcc);u8*ctx=*(u8**)(arg+4);ext_421870(0x677be0,w15(ctx,0));
 if(w15(ctx,0)&0x10002){
  ext_421870(0x677bf8);const u32 offs[]={0xb0,0xa4,0xac,0xa8,0xa0,0x9c};const u32 fmt[]={0x677c14,0x677c2c,0x677c44,0x677c5c,0x677c74,0x677c8c};
  for(u32 i=0;i<6;++i)ext_421870(fmt[i],w15(ctx,offs[i]));
 }
 if(w15(ctx,0)&0x10001){
  ext_421870(0x677ca4);ext_421870(0x677cc0,w15(ctx,0xb4));u32 query[7];for(u32 i=0;i<7;++i)query[i]=0xcccccccc;
  (*(u32(STDCALL **)(u32,void*,u32))0x6760e8)(w15(ctx,0xb8),query,28);
  u32 module=0x677a4c;
  if(query[4]==0x1000 && query[1]){
   (*(u32(STDCALL **)(u32,u32,u32))0x67607c)(query[1],0x6fd448,1000);
   u8*last=(*(u8* (**)(u32,u32))0x676258)(0x6fd448,92);
   module=last?(u32)(last+1):0x6fd448;
  }
  ext_421870(0x677cd8,w15(ctx,0xb8),module);
  const u32 offs[]={0xc4,0xc0,0xbc,0xc8},fmt[]={0x677cf8,0x677d10,0x677d28,0x677d40};
  for(u32 i=0;i<4;++i)ext_421870(fmt[i],w15(ctx,offs[i]));
 }
 if(w15(ctx,0)&0x10004){ext_421870(0x677d58);for(u32 i=0;i<4;++i)ext_421870(0x677d6c+i*24,w15(ctx,0x8c+i*4));}
 if(w15(ctx,0)&0x10010){ext_421870(0x677dcc);const u32 fmt[]={0x677de8,0x677e00,0x677e18,0x677e30,0x677e48,0x677e48};for(u32 i=0;i<6;++i)ext_421870(fmt[i],w15(ctx,4+i*4));}
 if(w15(ctx,0)&0x10008){ext_421870(0x677e60);for(u32 i=0;i<7;++i)ext_421870(0x677e7c+i*28,w15(ctx,0x1c+i*4));}
}
PCREG(424910,dump15);
