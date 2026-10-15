#pragma once
#include "ff.h"
static inline u32 s4r(const void* p,u32 o){const u8* b=(const u8*)p+o;return (u32)b[0]|((u32)b[1]<<8)|((u32)b[2]<<16)|((u32)b[3]<<24);}
static inline void* s4p(const void* p,u32 o){return (void*)s4r(p,o);}
static inline void s4w(void* p,u32 o,u32 v){u8* b=(u8*)p+o;for(u32 i=0;i<4;i++)b[i]=(u8)(v>>(8*i));}
static inline void s4w16(void* p,u32 o,u32 v){u8* b=(u8*)p+o;b[0]=(u8)v;b[1]=(u8)(v>>8);}
static inline u16 s4r16(const void* p,u32 o){const u8* b=(const u8*)p+o;return (u16)(b[0]|((u16)b[1]<<8));}
