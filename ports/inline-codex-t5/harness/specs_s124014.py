from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu;e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 hook_rec(c,0x633654,0,pop=0)
 vals=[r.getrandbits(32) for _ in range(r.randrange(7))]
 def modify(em,k):
  em.w32(em.arg32(0),r.getrandbits(32));em.w32(em.arg32(1)+4,r.getrandbits(32))
 me=obj(c,0x20,{0x98:pystub(c,2,this=True,deref={0:9,1:3},side=modify)})
 dest=obj(c,0x20,{0x14:pystub(c,0,this=True),4:pystub(c,1,this=True)})
 def query(em,k):
  for i,v in enumerate(vals):em.w32(em.arg32(0)+i*4,v)
 finder=obj(c,0x20,{0x38:pystub(c,10,this=True,stackmark=[0],deref={1:9,3:9,4:3},side=query,ret=len(vals))})
 wrapper=rnd(c,0x20);e.w32(wrapper+0x1c,finder)
 table=obj(c,0x20,{0x50:pystub(c,1,this=True,ret=r.getrandbits(32))})
 sys=rnd(c,0x1ac0);e.w32(0x70039c,sys);e.w32(sys+0x1aa3,wrapper);e.w32(sys+0x9b,table)
 return [me,r.getrandbits(32),dest,rnd(c,36),rnd(c,12),r.getrandbits(32),r.getrandbits(32),r.getrandbits(32),r.getrandbits(32)]
S(0x442150,'GUESS collect geometry box query','thiscall',None,ret=None,gen=g,note='batch124014')
