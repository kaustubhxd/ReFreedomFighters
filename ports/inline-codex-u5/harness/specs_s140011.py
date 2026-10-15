from pilot import S
from recruits_util import rnd,clear_hooks,pystub,hook_rec,sysobj

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 me=rnd(c,0x500);out=rnd(c,0x400);e.wbytes(me+2,bytes([r.choice([0x38,0x38,0,0x37,0x39])]))
 count=r.choice([0,1,3]);e.w32(out+0x24,count)
 scratch=[r.getrandbits(32) for _ in range(8)]
 def first(em,k):
  for i,x in enumerate(scratch):em.w32(em.arg32(1)+i*4,x)
 hook_rec(c,0x5b0cc0,2,this=True,nullflag=[1],side=first)
 hook_rec(c,0x5b10f0,0,this=True)
 hook_rec(c,0x5ade30,0,this=True,ret=r.getrandbits(32))
 hook_rec(c,0x5acfa0,0,this=True,ret=r.getrandbits(32))
 words=[r.getrandbits(32) for _ in range(3)]
 returns=[r.choice([0,1,1,255]) for _ in range(8)]
 def fill(em,k):
  for i,x in enumerate(words):em.w32(em.arg32(1)+i*4,(x+k)&0xffffffff)
  em.w32(em.arg32(2),k+99)
 hook_rec(c,0x5c2d90,3,this=True,nullflag=[1,2],side=fill,ret=lambda em,k:returns[k%8])
 sysobj(c,rand=r.choice([-2.,-1.,0.,0.25,0.5,0.75,1.]))
 return [me,out]
S(0x5adef0,'GUESS choose inventory entries','thiscall',None,ret=None,gen=gen)
