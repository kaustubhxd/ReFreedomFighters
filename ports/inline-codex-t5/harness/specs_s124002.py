from pilot import S
from recruits_util import rnd,clear_hooks,pystub
import struct

def g(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 ps=[rnd(c,12) for _ in range(5)]
 special=[0.,1.,-1.,1e-8,1e8,float('inf'),float('-inf'),float('nan')]
 # Mix exact axis-aligned planes/rays and general inputs; include positive and negative intersections.
 if r.random()<.5:
  vals=[[0.,1.,0.],[r.uniform(-10,10),r.choice([-5.,0.,5.]),0.],[1.,r.choice([-1.,0.,1.]),0.],[r.uniform(-10,10),r.choice([-5.,0.,5.]),0.]]
 else:vals=[[r.choice(special) if r.random()<.25 else r.uniform(-10,10) for _ in range(3)] for _ in range(4)]
 # args: normal(ECX), plane point(EDX), origin(stack), direction(stack), output(stack), two-sided(stack).
 for p,vs in zip(ps[:4],vals):e.wbytes(p,struct.pack('<3f',*vs))
 return [ps[0],ps[1],ps[3],ps[2],ps[4],r.choice([0,1,2,0x100])]
S(0x4e1b80,'GUESS ray plane intersection','fastcall',None,ret='st0',gen=g,nan_heap=True,note='batch124002')
