from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 hook_rec(c,0x5165d0,4,this=True)
 s=rnd(c,0xc00)
 for off in [0x8c,0x90]:e.w32(s+off,r.randrange(1,5))
 for off in [0x40,0x44]:e.w32(s+off,r.choice([0,1,3,0xffffffff,0x7fffffff,0x80000000]))
 for off in [0x64,0x68]:e.wbytes(s+off,struct.pack('<f',r.uniform(-100,100)))
 return [s]
S(0x526470,'GUESS cycle ground probes','thiscall',None,ret=None,gen=gen)
