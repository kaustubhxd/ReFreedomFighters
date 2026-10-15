from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,ret=r.getrandbits(32),pop=0)
 rec=e.alloc(7*4*8,4)
 def save(em,k):
  p=em.arg32(2)
  for j,off in enumerate([0,4,8,16,20,24,40]):em.w32(rec+k*28+j*4,em.r32(p+off))
 s=obj(c,0x300,{0x130:pystub(c,3,this=True,stackmark=(2,),side=save)})
 found=obj(c,0x20,{0x330:pystub(c,0,this=True,ret=r.choice([7,7,0,6,8]))})
 tab=obj(c,0x20,{0x58:pystub(c,1,this=True,ret=found if r.randrange(3) else 0)})
 sys=rnd(c,0x100);e.w32(0x70039c,sys);e.w32(sys+0x9b,tab)
 a=rnd(c,0x20);e.w32(a,rnd(c,0x40))
 return [s,a]
S(0x515ab0,'GUESS dispatch typed event payload','thiscall',None,ret=None,gen=gen)
