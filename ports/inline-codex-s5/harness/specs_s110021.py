from pilot import S
from recruits_util import clear_hooks,rnd,obj,pystub,hook_rec

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 sys=rnd(c,0x80);e.w32(0x70039c,sys);e.w32(sys+0x40,r.getrandbits(32))
 t=rnd(c,0x100)
 group=obj(c,0x20,{0x7c:pystub(c,2,this=True,deref={0:9,1:3})});e.w32(t+0x88,group)
 for a in [0x5254c0,0x526df0,0x526cf0,0x5255d0]:hook_rec(c,a,0,this=True)
 roll,tilt=r.uniform(-1,1),r.uniform(-1,1)
 def rt(em,n):em.wf32(em.reg('ecx')+0x38,roll);em.wf32(em.reg('ecx')+0x30,tilt)
 hook_rec(c,0x524b00,0,this=True,side=rt)
 p,d=rnd(c,0x10),rnd(c,0x10)
 for i in range(3):e.wf32(p+4*i,r.uniform(-100,100));e.wf32(d+4*i,r.uniform(-1,1))
 return [t,p,d]
S(0x525640,'CUnderCarriageCar InitPosDir','thiscall',None,ret=None,gen=gen)
