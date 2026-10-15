from pilot import S
from recruits_util import rnd,sysobj,clear_hooks,pystub
import struct

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;me=rnd(c,0x400);sys=sysobj(c);now=r.randrange(10000);e.w32(sys+0x30,now)
 for ty in range(1,12):
  for ch in range(2):
   p=me+ty*58+0x91+ch*29
   vals=[r.choice([0,0.01,0.1,0.5,1.,2.]) for _ in range(4)]+[r.uniform(-10,10) for _ in range(3)]
   e.wbytes(p,struct.pack('<7f',*vals));e.w8(p+28,r.choice([0,1,2,255]))
 n=r.choice([-1,0,1,2,3,4]);e.w32(me+0x80,n)
 for i in range(max(n,0)):
  e.w32(me+i*24+8,r.choice([0,1,2,3,11,12,0xffffffff]));e.w32(me+i*24+12,now-r.choice([-1,0,1,10,100,500,1000,2000,5000,10000]))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x43d0f0,'GUESS update paired timed envelopes','thiscall',None,ret=None,gen=gen)
