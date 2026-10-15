import struct
from pilot import S
from recruits_util import rnd,obj,pystub,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 pos=[r.choice([0.,r.uniform(-10,10)]),r.choice([0.,r.uniform(-10,10)]),r.uniform(-10,10)]
 state=e.alloc(4);e.w32(state,r.randrange(8))
 def out(em,k):em.wbytes(em.arg32(0),struct.pack('<3f',*pos))
 def select(em,k):em.w32(state,em.arg32(0))
 actor=obj(c,0x40,{0x308:pystub(c,1,this=True,stackmark=(0,),side=out),0x2ec:pystub(c,1,this=True,side=select),0x2f0:pystub(c,0,this=True,ret=lambda em,k:em.r32(state))})
 s=obj(c,0x300,{0x84:pystub(c,0,this=True,ret=actor)})
 e.w8(s+0x88,r.choice([0,1,1,1]));e.w32(s+0xdc,r.choice([2,2,2,0,3]));e.w8(s+0x21b,r.choice([0,0,0,1]))
 e.w32(s+0x206,r.choice([e.r32(state),r.randrange(8)]))
 def fw(a,v):e.wbytes(a,struct.pack('<f',v))
 fw(s+0x21c,pos[0] if r.randrange(2) else pos[0]+1);fw(s+0x220,pos[1] if r.randrange(2) else pos[1]+1)
 for i in range(5):
  p=s+0x224+0x24*i;e.w32(p,r.randrange(8));fw(p+0xc,r.choice([0.,1.,2.,3.,float('nan')]))
  for axis in range(2):
   if r.randrange(2):lo=pos[axis]-1;hi=pos[axis]+1
   else:lo=pos[axis];hi=pos[axis]+r.choice([-2,0,2])
   fw(p+4+4*axis,lo);fw(p+0x10+4*axis,hi)
 hook_rec(c,0x562260,0,this=True)
 hook_rec(c,0x4f9680,1,this=True)
 hook_rec(c,0x575d00,0,this=True)
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [s]
S(0x574e70,'GUESS selectRegion','thiscall',None,ret=None,gen=gen)
