import struct
from pilot import S,EDGE_F
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 init=[r.uniform(-10,10) for _ in range(9)];basis=[r.choice(EDGE_F+[r.uniform(-10,10)]) for _ in range(9)]
 def construct(em,k):em.wbytes(em.reg('ecx'),struct.pack('<9f',*init))
 hook_rec(c,0x4de7a0,0,this='mark',side=construct)
 def fill(em,k):em.wbytes(em.arg32(0),struct.pack('<9f',*basis))
 actor=obj(c,0x80,{0x3a8:pystub(c,2,this=True,deref={0:9,1:3},ret=r.getrandbits(32)),0x390:pystub(c,1,this=True),0x98:pystub(c,2,this=True,nullflag=(0,1),side=fill)})
 state=obj(c,16,{0x34:pystub(c,0,this=True,ret=r.choice([0,1,0x100,0x101]))});e.w32(actor+0x6c,state)
 me=rnd(c,0x30);e.w32(me+0x1c,actor);arg=rnd(c,16);e.w32(arg+8,rnd(c,16))
 cell=rnd(c,8);hook_rec(c,0x5003d0,1,this=True,ret=cell)
 hook_rec(c,0x5002f0,1,this=True,ret=r.getrandbits(32));hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('eax'))
 e.w32(0x7003b0,pystub(c,0))
 return [me,arg]
S(0x5588e0,'classify actor up direction','thiscall',None,ret='eax',gen=gen)
