from pilot import S
from recruits_util import clear_hooks,rnd,obj,pystub,sysobj

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 inner=rnd(c,0x20);geom=rnd(c,0x80)
 owner=obj(c,0x20,{0x40:pystub(c,0,this=True),0x3c:pystub(c,1,this=True)});e.w32(owner+0x10,inner);e.w32(owner+8,geom)
 width=r.choice([0,1,0x7fffffff,0x80000000,0xffffffff,r.getrandbits(32)])
 def dims(em,n):
  for i,v in enumerate([width,123,456]):em.w32(em.arg32(1+i),v)
 mgr=obj(c,0x20,{0xd4:pystub(c,4,this=True,nullflag=(1,2,3),side=dims,ret=r.choice([0,1,256,257]))})
 sys=sysobj(c);base=rnd(c,0x30);e.w32(base+0x18,mgr);e.w32(sys+0x1aa3,base)
 t=obj(c,0x80,{0x68:pystub(c,2,this=True),0x58:pystub(c,0,this=True)});e.w32(t+0x44,owner)
 src=rnd(c,0x70)
 for off in [0x5e,0x64]:e.w8(src+off,r.randrange(2))
 return [t,src]
S(0x4a49c0,'GUESS apply component configuration','thiscall',None,ret=None,gen=gen)
