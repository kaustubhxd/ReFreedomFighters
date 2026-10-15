#include "ff.h"
extern "C" u32* THISCALL ext_5003d0(void*,u32);
extern "C" void THISCALL ext_4db2c0(void*,void*,void*);
extern "C" void FASTCALL ext_4dfd10(void*,void*);
extern "C" void FASTCALL ext_4de420(void*,void*);
extern "C" void FASTCALL ext_4de480(void*,void*);
extern "C" void FASTCALL ext_4419f0(void*,void*);
extern "C" void FASTCALL ext_43e960(void*,void*);
extern "C" void ext_633654(u32);
static void log_missing(u32 line,u32 text) {
 void* logger=G(void*,0x700390);
 void* sink=vcall<void*>(logger,0x20,0x69db34,line);
 typedef void (*Print)(void*,u32);
 (*(Print*)(*(u8**)sink+0x2c))(sink,text);
}
static void STDCALL transform_link(u8* args) {
 void* list=*(void**)(args+4);
 void* dst=vcall<void*>(*(void**)(G(u8*,0x70039c)+0x9b),0x58,*ext_5003d0(list,0));
 void* parent=vcall<void*>(*(void**)(G(u8*,0x70039c)+0x9b),0x58,*ext_5003d0(list,2));
 void* src=vcall<void*>(*(void**)(G(u8*,0x70039c)+0x9b),0x58,*ext_5003d0(list,1));
 if(dst && src && parent) {
  u32 basis[9],position[3],poscopy[3],pbase[3],matrix[9],inverse[9];
  vcall<void>(src,0x80,basis,position);
  for(int i=0;i<3;i++)poscopy[i]=position[i];
  ext_4db2c0(*(void**)((u8*)parent+8),matrix,pbase);
  ext_4dfd10(inverse,matrix);
  ext_4de420(matrix,basis);
  ext_4de480(inverse,matrix);
  ext_4419f0(pbase,inverse);
  ext_43e960(poscopy,pbase);
  vcall<void>(dst,0x74,inverse,poscopy);
 }else{
  if(!dst){log_missing(0x1b7,0x69dbbc);log_missing(0x1b8,0x69dc04);}
  if(!src)log_missing(0x1b9,0x69dbe0);
 }
 ext_633654(0);
}
PCREG(50f850,transform_link);
