from pilot import S
from recruits_util import rnd,clear_hooks,pystub,obj,sysobj,hook_rec

def wind(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 self=rnd(c,0x80);geom=rnd(c,0x80)
 e.wf32(self+0x58,r.choice([0.0,1.0,-1.0,r.uniform(-10,10)]))
 vals=[r.uniform(-20,20) for _ in range(3)]
 def vec(em,k):
  for i,v in enumerate(vals):em.wf32(em.arg32(0)+4*i,v)
 hook_rec(c,0x4db500,1,this=True,deref={0:3},side=vec)
 base=r.getrandbits(32);flags=r.choice([0,1,3,0xffffffff,r.getrandbits(32)])
 def params(em,k):
  for i,v in enumerate((base,r.getrandbits(32),flags)):em.w32(em.arg32(i+1),v)
 ctl=obj(c,0x20,{0xd4:pystub(c,4,this=True,stackmark=(1,2,3),side=params),0xd8:pystub(c,2,this=True)})
 outer=rnd(c,0x20);e.w32(outer+0x18,ctl);sys=sysobj(c);e.w32(sys+0x1aa3,outer)
 return [self,geom]
S(0x4c3740,'GUESS_apply_sinusoidal_wind','thiscall',None,ret=None,gen=wind)
