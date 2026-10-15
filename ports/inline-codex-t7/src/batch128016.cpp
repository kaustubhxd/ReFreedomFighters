#include "ff.h"
extern "C" void THISCALL ext_4e4960(void*,void*);
extern "C" void THISCALL ext_4e4900(void*,void*);
extern "C" void THISCALL ext_4e42a0(void*,void*);
extern "C" u8* THISCALL ext_4e6b80(void*,u16*);
extern "C" void THISCALL ext_4e4a50(void*,void*,void*);
extern "C" void THISCALL ext_4e4890(void*,void*);
extern "C" u32 THISCALL ext_4e4990(void*,u32);
extern "C" void THISCALL ext_4e3f60(void*,void*);
static inline u32&w17(u8*p,u32 o){return *(u32*)(p+o);}
static inline u16&h17(u8*p,u32 o){return *(u16*)(p+o);}
static void unlink17(u8*item,u8*node){
 u8*prev=*(u8**)(item+4),*next=*(u8**)item;
 if(prev)w17(prev,0)=(u32)next;else w17(node,12)=(u32)next;
 if(next)w17(next,4)=(u32)prev;
}
static void THISCALL move17(u8*self,u8*item,s32*lo,s32*hi){
 for(u32 i=0;i<3;++i)if(lo[i]<0)lo[i]=0;
 for(u32 i=0;i<3;++i)if(hi[i]>=65536)hi[i]=65535;
 s32 dx=(u32)hi[0]-lo[0]+1,dy=(u32)hi[1]-lo[1]+1,dz=(u32)hi[2]-lo[2]+1;
 s32 oldx=((s32)h17(item,18)-h17(item,12)+1)>>1;oldx+=h17(item,12);
 s32 oldz=((s32)h17(item,22)-h17(item,16)+1)>>1;oldz+=h17(item,16);
 for(u32 i=0;i<3;++i){h17(item,12+i*2)=(u16)lo[i];h17(item,18+i*2)=(u16)hi[i];}
 s32 max=dx>dy?(dx>dz?dx:dz):(dy>dz?dy:dz);
 s32 x=(dx>>1)+h17(item,12),z=(dz>>1)+h17(item,16);u8*node=*(u8**)(item+24);
 s32 cell=65536>>(node[10]&31);u32 level;
 if(max<=cell && max>=(cell>>1)){
  s32 ax=oldx&~(cell-1),az=oldz&~(cell-1);
  if(x>=ax && x<(s32)((u32)ax+cell) && z>=az && z<(s32)((u32)az+cell))return;
  u8*pool=self+4;u8*parent=(u8*)w17(pool,0)+h17(node,8)*w17(pool,12);
  ax=oldx&~(cell*2-1);az=oldz&~(cell*2-1);
  if(x>=ax && x<(s32)((u32)ax+cell*2) && z>=az && z<(s32)((u32)az+cell*2)){
   u32 quadrant=((x&cell)!=0)+2*((z&cell)!=0);
   ext_4e4960(self,item);ext_4e4900(*(void**)(item+24),pool);
   u16*slot=(u16*)(parent+quadrant*2);u8*dst;
   if(*slot){dst=(u8*)w17(pool,0)+*slot*w17(pool,12);ext_4e42a0(dst,item);}
   else{u16 index;dst=ext_4e6b80(pool,&index);*slot=index;ext_4e4a50(dst,pool,parent);ext_4e42a0(dst,item);}
   return;
  }
  unlink17(item,node);ext_4e4890(*(void**)(item+24),pool);level=ext_4e4990(self,max);
 }else{
  unlink17(item,node);ext_4e4890(*(void**)(item+24),self+4);
  level=max>1?15-(31-__builtin_clz((u32)max)):15;
 }
 u32 args[7]={(u32)(self+4),(u32)item,0,level,(u32)x,0,(u32)z};ext_4e3f60(*(void**)self,args);
}
PCREG(4e4bd0,move17);
