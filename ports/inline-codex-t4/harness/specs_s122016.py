from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 n=r.randrange(13)
 for i in range(n*4):
  bits=r.choice([0,0x80000000,0x3f800000,0xbf800000,0x7fc00000,0x7f800000,0x40000000,0x3f000000,0x3f400000,0x3f200000,0x3f600000,r.getrandbits(32)])
  e.w32(0x812640+4*i,bits)
 return [rnd(c,4*max(1,n)),r.getrandbits(32),n]
S(0x61a700,'GUESS pack global float colors','stdcall',None,ret=None,gen=gen)
