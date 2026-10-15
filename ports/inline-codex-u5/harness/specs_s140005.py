import struct
from pilot import S
from recruits_util import rnd,clear_hooks,pystub

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 n=r.randrange(0,35);a=rnd(c,max(53,53*n));mode=r.randrange(5)
 for i in range(n):
  f=r.choice([0.,-0.,1.,-1.,float('nan'),float('inf'),-float('inf'),r.uniform(-100,100)])
  if mode==0:f=float(i)
  if mode==1:f=float(n-i)
  if mode==2:f=1.
  e.wbytes(a+53*i,struct.pack('<f',f))
 return [a,a+53*n,r.getrandbits(32),r.getrandbits(32)]
S(0x4adf60,'GUESS build heap of packed 53-byte records','fastcall',None,ret=None,gen=gen)
