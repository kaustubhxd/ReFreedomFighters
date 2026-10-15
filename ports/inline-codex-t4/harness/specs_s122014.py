from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 # Exact x87 remainder loop for CRT _CIfmod; st0 divisor, st1 dividend.
 code=bytes.fromhex('d9c9d9f8dfe066a9000475f6ddd9c3')
 a=e.alloc(len(code)+16,16);e.wbytes(a,code);e.mu.ctl_flush_tb();e.w32(0x676358,a)
 period=r.choice([1,2,100,65535,0x80000000,0xffffffff])
 def fill(em,k):em.w32(em.arg32(1),period)
 cb=obj(c,0x20,{0xdc:pystub(c,2,this=True,stackmark=(1,),side=fill,ret=r.choice([0,1,1,0x100,0x101])),0xe0:pystub(c,2,this=True)})
 s=obj(c,0x60,{0x58:pystub(c,0,this=True)})
 cfg=rnd(c,0x30);sys=rnd(c,0x1b00);parent=rnd(c,0x20);child=rnd(c,0x80)
 e.w32(s+0x44,parent);e.w32(parent+8,child);e.w32(0x70039c,sys);e.w32(sys+0x1aa3,cfg);e.w32(cfg+0x18,cb)
 for addr in [sys+0x48,s+0x48,s+0x4c]:e.wbytes(addr,struct.pack('<f',r.uniform(-10000,10000)))
 return [s]
S(0x4cbd00,'GUESS advance wrapping animation timer','thiscall',None,ret=None,gen=gen)
