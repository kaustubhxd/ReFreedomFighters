import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,sysobj

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 me=rnd(c,0x20);node=rnd(c,0x100);e.w32(me+8,node);e.w32(node+0x6c,r.choice([0,r.getrandbits(32),r.getrandbits(32)]))
 info=[r.uniform(-3,3) for _ in range(15)];info[7]=r.choice([0.,1.,-1.,10.,r.uniform(-100,100)]);info[9]=r.choice([0.,0.5,1.,-1.,r.uniform(-1.5,1.5)])
 def fill(em,k):em.wbytes(em.arg32(1),struct.pack('<15f',*info))
 lookup=obj(c,0x20,{0x88:pystub(c,2,this=True,nullflag=[1],side=fill)})
 world=rnd(c,0x30);e.w32(world+0x18,lookup);so=sysobj(c);e.w32(so+0x1aa3,world)
 return [me]
S(0x448590,'GUESS refresh bounds from angular shape','thiscall',None,ret=None,gen=gen)
