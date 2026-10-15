from pilot import S
from recruits_util import rnd,clear_hooks,pystub,obj,sysobj,hook_rec

def aim(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 self=rnd(c,0xb0);e.wf32(self+0x84,r.choice([0.0,-0.0,-1.0,1.0,float('nan'),r.uniform(-2,2)]))
 delta=[[r.uniform(-10,10) for _ in range(3)] for _ in range(2)]
 def point(em,k):
  p=em.arg32(0)
  for i in range(3):em.wf32(p+4*i,em.rf32(p+4*i)+delta[k][i])
 target=obj(c,0x20,{0x84:pystub(c,1,this=True,deref={0:3},side=point),0x8c:pystub(c,1,this=True,deref={0:3})})
 sys=sysobj(c,slots={0x1c0:pystub(c,2,this=True,st0=r.choice([0.0,1.0,r.random()]))},table_slots={0x58:pystub(c,1,this=True,ret=target)})
 e.wf32(sys+0x48,r.uniform(-2,2))
 hook_rec(c,0x5c94a0,1,this=True,ret=(r.getrandbits(24)<<8)|r.choice([0,1]))
 hook_rec(c,0x5c82a0,1,this=True,deref={0:3},ret=r.getrandbits(32))
 return [self,r.getrandbits(32)]
S(0x5c8470,'CMachinegunControlGroup::AimWeaponRef','thiscall',None,ret='al',gen=aim,nan_heap=True)
