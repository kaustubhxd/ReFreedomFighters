from pilot import S
from recruits_util import clear_hooks,rnd,obj,pystub,hook_rec

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 t=rnd(c,0x80);owner=obj(c,0x20,{0xc:pystub(c,0,this=True)});e.w32(t+0x14,owner)
 p=rnd(c,0x10);m=rnd(c,0x30);h=rnd(c,0x10)
 identity=[1.,0.,0.,0.,1.,0.,0.,0.,1.]
 for i,v in enumerate(identity):e.wf32(t+0x29+4*i,v);e.wf32(m+4*i,v if r.random()<.7 else r.uniform(-1,1))
 for i in range(3):
  old=r.uniform(-20,20);e.wf32(t+0x1d+4*i,old);e.wf32(p+4*i,r.choice([old,old+r.uniform(-10,10)]));e.wf32(h+4*i,r.uniform(0,5));e.wf32(t+0x4d+4*i,r.uniform(5,12))
 e.wf32(t+0x66,r.uniform(0,3))
 hook_rec(c,0x6359d0,0,this=True)
 return [t,p,m,h,r.choice([0,0,0,1,256,257])]
S(0x635eb0,'GUESS update cached bounds','thiscall',None,ret=None,gen=gen)
