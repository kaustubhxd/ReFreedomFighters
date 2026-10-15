from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 s=rnd(c,0x160);p=rnd(c,0x20);node=rnd(c,0x60);a=rnd(c,12)
 e.w32(s+0x44,p);e.w32(p+8,node);e.w32(s+0xcf,rnd(c,0x20))
 for j in range(3):
  f=r.choice([0.,r.uniform(-10,10),r.uniform(-10000,10000)])
  e.wbytes(a+4*j,struct.pack('<f',f));e.wbytes(node+0x24+4*j,struct.pack('<f',f if r.randrange(2) else 0.))
 hook_rec(c,0x543810,2,this=True,deref={0:3})
 hook_rec(c,0x634e90,1,this=True)
 return [s,a]
S(0x53efd0,'GUESS trigger nearby rigid body motion','thiscall',None,ret=None,gen=gen)
