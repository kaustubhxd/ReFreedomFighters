import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0x140);sys=rnd(c,0x80);e.w32(0x70039c,sys)
 now=r.randrange(-10000,10000);e.w32(sys+0x40,now&0xffffffff);e.wbytes(sys+0x48,struct.pack('<f',r.uniform(-0.1,0.3)))
 for off in [0xfa,0xfe,0x102,0x106,0x115,0x119,0x11d,0x121]:e.wbytes(me+off,struct.pack('<f',r.uniform(-10,10)))
 # Exact timer boundary cases in addition to random branches.
 if c.case%5==0:e.wbytes(me+0x115,struct.pack('<f',now/1024));e.w32(me+0xfa,0)
 e.wbytes(me+0x114,bytes([r.choice([0,1,2])]))
 e.wbytes(me+0x125,bytes([r.choice([0,1,2])]))
 hook_rec(c,0x4de000,2,st0=r.uniform(-1,1))
 rec=e.alloc(12,4)
 def boolean_args(em,k):
  em.w32(rec,em.arg32(0)&255);em.w32(rec+4,em.arg32(1)&255)
 hook_rec(c,0x5c3560,2,this=True,stackmark=(0,1),side=boolean_args)
 return [me]
S(0x5c3140,'GUESS timed alternating visibility toggle','thiscall',None,ret=None,gen=gen)
