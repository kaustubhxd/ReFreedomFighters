#include "ff.h"
extern "C" u32 FASTCALL ext_4cc850(const char*,const char*);
extern "C" const char* THISCALL ext_4cc1d0(void*);
static const char* strchr_i(const char* p,int ch){typedef const char*(*Fn)(const char*,int);return (*(Fn*)0x676254)(p,ch);}
static const char* strrchr_i(const char* p,int ch){typedef const char*(*Fn)(const char*,int);return (*(Fn*)0x676258)(p,ch);}
static int stricmp_i(const char* a,const char* b){typedef int(*Fn)(const char*,const char*);return (*(Fn*)0x676414)(a,b);}
static int strnicmp_i(const char* a,const char* b,u32 n){typedef int(*Fn)(const char*,const char*,u32);return (*(Fn*)0x67640c)(a,b,n);}
static const char* THISCALL strip_path(u8* me,const char* path) {
 if(*(void**)(me+8)) {
  vcall<void>(me,0x6c,1);
  const char* ext=strrchr_i(path,'.');if(!ext)return nullptr;
  void* list=*(void**)(me+8);
  if(list){
   u32 it[3];vcall<void>(list,0x4c,it);
   const char* item=vcall<const char*>(list,0x5c,it);
   while(it[0]){
    if(strchr_i(item,'*')){if(!ext_4cc850(path,item))return nullptr;}
    else if(!stricmp_i(ext,item)){vcall<void>(me,0x6c,0);return nullptr;}
    list=*(void**)(me+8);item=vcall<const char*>(list,0x5c,it);
   }
  }
 }
 const char* prefix=ext_4cc1d0(G(u8*,0x70039c)+0x123);
 if(prefix && *prefix){
  u32 n=0,m=0;while(prefix[n])++n;while(path[m])++m;
  if(n<=m && !strnicmp_i(prefix,path,n)) {path+=n;if(*path=='\\')++path;}
 }
 return path;
}
PCREG(4351c0,strip_path);
