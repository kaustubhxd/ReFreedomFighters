from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 n=r.randrange(33);p=rnd(c,max(0x24*n,0x24))
 for i in range(n):
  if r.random()<0.4:e.w32(p+0x18+0x24*i,r.choice([0,0xffffffff,0xff000000,0x00ffffff,0x01020304,0x80000000]))
 for base in [0x812440,0x812640]:e.wbytes(base,bytes(r.getrandbits(8) for _ in range(0x200)))
 flags=r.getrandbits(32)
 return [p,n,flags]
S(0x61ab70,'GUESS expand packed vertex colors','stdcall',None,ret=None,gen=gen)
