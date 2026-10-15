#include "ff.h"
static void block22(void*stream,void*data,u32 size){vcall<void>(stream,0x10,data,size);}
static void count22(void*stream,void*table){u32 n=vcall<u32>(table,0x14);block22(stream,&n,4);}
static u8 THISCALL save22(u8*self,void*stream){
 *(u32*)(self+4)&=0xffffffbf;
 void*table=*(void**)(self+0x48);if(!table)return 1;
 count22(stream,table);table=*(void**)(self+0x48);if(!table)return 1;
 u32 outer[3]={0xcccccccc,0xcccccccc,0xcccccccc};vcall<void>(table,0x4c,outer);u8*formation=vcall<u8*>(*(void**)(self+0x48),0x64,outer);
 while(formation){
  const u32 offsets[]={0,0x3c,0x64,0x4c,0x58,0x40,0xc,0x88,0x8c,0x90};
  const u32 sizes[]={4,4,0x24,12,12,12,0x30,4,4,1};
  for(u32 i=0;i<10;++i)block22(stream,formation+offsets[i],sizes[i]);
  table=*(void**)(formation+4);count22(stream,table);table=*(void**)(formation+4);
  if(table){u32 iter[3]={0xcccccccc,0xcccccccc,0xcccccccc};vcall<void>(table,0x4c,iter);u8*member=vcall<u8*>(*(void**)(formation+4),0x64,iter);
   while(member){const u32 off[]={0,4,8,12,16,17,21},sz[]={4,4,4,4,1,4,12};for(u32 i=0;i<7;++i)block22(stream,member+off[i],sz[i]);member=vcall<u8*>(*(void**)(formation+4),0x64,iter);}
  }
  table=*(void**)(formation+8);count22(stream,table);table=*(void**)(formation+8);
  if(table){u32 iter[3]={0xcccccccc,0xcccccccc,0xcccccccc};vcall<void>(table,0x4c,iter);u8*record=vcall<u8*>(*(void**)(formation+8),0x64,iter);
   while(record){const u32 off[]={0,4,16,32,28},sz[]={4,12,12,4,4};for(u32 i=0;i<5;++i)block22(stream,record+off[i],sz[i]);record=vcall<u8*>(*(void**)(formation+8),0x64,iter);}
  }
  formation=vcall<u8*>(*(void**)(self+0x48),0x64,outer);
 }
 return 1;
}
PCREG(5b7100,save22);
