from pilot import S
from recruits_util import clear_hooks,rnd,obj,pystub

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 p=[r.uniform(-100,100) for _ in range(3)];shift=[r.uniform(-10,10) for _ in range(3)]
 def origin(em,n):
  for i,v in enumerate(p):em.wf32(em.arg32(0)+4*i,v)
 def transform(em,n):
  for i,v in enumerate(shift):em.wf32(em.arg32(0)+4*i,em.rf32(em.arg32(0)+4*i)+v)
 hero=obj(c,0x430,{0x378:pystub(c,1,this=True,nullflag=(0,),side=origin),0x84:pystub(c,1,this=True,nullflag=(0,),deref={0:3},side=transform)})
 e.w32(hero+0x417,r.choice([0,0x400,0x20000000,0x20000400]))
 t=rnd(c,0xe40);e.w32(t+0x44,hero);cam=rnd(c,0x500);e.w32(t+0xb54,cam);e.wf32(cam+0x4aa,r.uniform(-100,300))
 for off in range(0xc71,0xcad,4):e.wf32(t+off,r.uniform(-1,1) if off>=0xc89 else r.uniform(-500,500))
 e.wf32(t+0xae9,r.uniform(-3.2,3.2));e.wf32(t+0xaed,r.choice([0.,r.uniform(-1.3,1.3)]))
 return [t]
S(0x5d1ea0,'ZCamHelper SetFocusSystemMouse','thiscall',None,ret=None,gen=gen)
