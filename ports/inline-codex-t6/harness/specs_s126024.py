from pilot import S
from recruits_util import rnd,clear_hooks,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;weights=rnd(c,8);a=rnd(c,12);b=rnd(c,12);normal=rnd(c,12)
 e.wbytes(weights,struct.pack('<2f',r.uniform(0.1,10),r.uniform(0.1,10)))
 for p in [a,b,normal]:e.wbytes(p,struct.pack('<3f',*[r.uniform(-10,10) for _ in range(3)]))
 if r.random()<0.2:e.wbytes(normal,bytes(12))
 if r.random()<0.2:b=a
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [weights,a,b,normal,r.getrandbits(32)]
S(0x4e64b0,'GUESS weighted normal projection','thiscall',None,ret=None,gen=gen)
