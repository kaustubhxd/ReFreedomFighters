from pilot import S
from recruits_util import clear_hooks,rnd,obj,pystub,sysobj,hook_rec

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 geom=r.getrandbits(32);hit=r.choice([geom,r.getrandbits(32)])
 def add(vals):
  def side(em,n):
   p=em.arg32(0)
   for i,v in enumerate(vals):em.wf32(p+4*i,em.rf32(p+4*i)+v)
  return side
 target=obj(c,0x40,{0x84:pystub(c,1,this=True,nullflag=(0,),deref={0:3},side=add([r.uniform(-50,50) for _ in range(3)]))})
 def cast(em,n):em.w32(em.arg32(0)+0x44,hit)
 world=obj(c,0x40,{0x2e0:pystub(c,6,this=True,deref={0:6},side=cast,ret=r.randrange(2))})
 so=sysobj(c,table_size=0xb00,table_slots={0x58:pystub(c,1,this=True,ret=r.choice([0,target,target,target]))});e.w32(e.r32(so+0x9b)+0xadc,world)
 root=rnd(c,0x40)
 for i in range(3):e.wf32(root+0x24+4*i,r.uniform(-100,100))
 muzzle=rnd(c,0x20);e.w32(muzzle+8,root)
 weapon=obj(c,0x400,{0x32c:pystub(c,1,this=True,deref={0:3}),0x348:pystub(c,0,this=True,ret=r.choice([0,muzzle,muzzle,muzzle])),0x84:pystub(c,1,this=True,nullflag=(0,),deref={0:3},side=add([r.uniform(-5,5) for _ in range(3)]))})
 t=obj(c,0x600,{0x84:pystub(c,1,this=True,deref={0:3},side=add([r.uniform(-5,5) for _ in range(3)])),0x50c:pystub(c,0,this=True,ret=r.choice([0,weapon,weapon,weapon]))})
 e.w32(t+0x26a+0x39,geom);e.w8(t+0x3a4,r.choice([0,1,1,1]))
 pos=[r.uniform(-100,100) for _ in range(3)]
 def targetpos(em,n):
  for i,v in enumerate(pos):em.wf32(em.arg32(0)+4*i,v)
 hook_rec(c,0x4669c0,1,this=True,nullflag=(0,),ret=r.choice([0,1,256,257]),side=targetpos)
 return [t]
S(0x4744f0,'ZLNKWHANDS GetRHandFireTarget','thiscall',None,ret='eax',gen=gen)
