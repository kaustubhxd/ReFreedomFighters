from pilot import S
from recruits_util import clear_hooks,rnd,obj,pystub,hook_rec,sysobj

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 sys=sysobj(c,slots={0x1c0:pystub(c,2,this=True,st0=r.choice([0.,.25,.5,1.,r.uniform(0,1)]))},table_slots={0x114:pystub(c,6,this=True,ret=r.getrandbits(32))});e.w32(sys+0x40,r.randrange(1<<24))
 def shift(em,n):
  p=em.arg32(0)
  for i in range(3):em.wf32(p+4*i,em.rf32(p+4*i)+offset[i])
 offset=[r.uniform(-10,10) for _ in range(3)]
 anim=rnd(c,0x20)
 actor=obj(c,0x40,{0x4cc:pystub(c,1,this=True,deref={0:3},side=shift),0x228:pystub(c,5,this=True,ret=r.choice([0,anim,anim])),0x128:pystub(c,1,this=True)})
 item=rnd(c,0x80);e.w32(item+0x60,r.randrange(500));e.w32(item+0x64,r.randrange(1000));e.w32(item+0x6c,r.choice([1,2,5,25,50,100]))
 t=rnd(c,0x40);e.w32(t+8,actor);e.w32(t+0xc,item)
 hook_rec(c,0x461570,3,this=True)
 return [t]
S(0x5eb380,'ZFFActorActionThrow Execute','thiscall',None,ret='al',gen=gen)
