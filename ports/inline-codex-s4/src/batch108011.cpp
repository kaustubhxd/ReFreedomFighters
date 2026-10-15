#include "s4_mem.h"
extern "C" s32 f62cac0(void* state,u32 code,u32 a,u32 b,void* matcher){
 if(code==15)return 0;
 if(code==23){s4w(state,0,0x62cb80);return 0;}
 if(code==18){
  typedef u32(*Match)(void*,u32,u32,u32);
  for(u32 i=0;i<8;i++){
   if(((Match)s4r(matcher,0x1c))(matcher,a,b,G(u32,0x6f4458+4*i))){s4w(state,0,0x62cd30);return i+20;}
  }
  if(((Match)s4r(matcher,0x1c))(matcher,a,b,0x6c01e0)){s4w(state,0,0x62cc50);return 0;}
 }
 if(!s4r(state,0xc)&&code==28)return 52;
 s4w(state,0,0x51f230);return -1;
}
PCREG(62cac0,f62cac0);
extern "C" void* THISCALL f46e9e0(void* self,const char* name){
 if(!s4p(self,0x70))return 0;
 u32 it[3];vcall<void>(s4p(self,0x70),0x4c,it);
 void* entry=vcall<void*>(s4p(self,0x70),0x64,it);
 while(entry){
  void* geom=vcall<void*>(s4p(G(void*,0x70039c),0x9b),0x58,s4r(entry,0));
  if(!geom)vcall<void>(s4p(self,0x70),0x44,it);
  else{
   typedef s32(*Compare)(const char*,const char*);
   const char* stored=(const char*)s4p(geom,4);
   if(!stored)stored=(const char*)0x67c8e8;
   if(((Compare)G(u32,0x676414))(stored,name)==0){
    vcall<void>(s4p(self,0x6c),0x40,s4r(entry,0));
    vcall<void>(s4p(self,0x74),0x40,s4r(entry,0));
    vcall<void>(s4p(self,0x70),0x44,it);
    return geom;
   }
  }
  entry=vcall<void*>(s4p(self,0x70),0x64,it);
 }
 return 0;
}
PCREG(46e9e0,f46e9e0);
