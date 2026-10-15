from pilot import S
from recruits_util import rnd,clear_hooks,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0x2200)
 def wf(a,v):e.wbytes(a,struct.pack('<f',v))
 e.w32(me+0x8d,r.choice([0,1,2,3,4,5,6,0xffffffff]));e.w32(me+0x91,r.choice([0,1,2,3,4,5,6,0xffffffff]))
 for off in [0x6c,0x74,0x78]:wf(me+off,r.choice([0,-0.0,-1,1,r.uniform(-100,100)]))
 for off in [0x21ad,0x21b1]:wf(me+off,r.choice([0.5,1,10,-1,100]))
 for base in [0xa1,0x791]:
  for i in range(8):wf(me+base+0xde*i,r.uniform(-5,5))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x529450,'GUESS tank track weight transfer','thiscall',None,ret=None,gen=gen)
