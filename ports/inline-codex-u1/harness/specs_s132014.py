from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,obj,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 p=rnd(c,0x200);sub=rnd(c,0x40);e.w32(p+0x6d,sub)
 def writesize(n):
  vals=[bytes(r.getrandbits(8) for _ in range(n)) for _ in range(8)]
  def side(e,k):e.wbytes(e.arg32(0),vals[min(k,7)])
  return side
 s1=obj(c,16,{0x50:pystub(c,1,this=True,side=writesize(4))})
 s2=obj(c,16,{0x40:pystub(c,1,this=True,side=writesize(4))})
 load=obj(c,16,{0x50:pystub(c,1,this=True,ret=lambda e,k:s1 if k==1 else 0,side=writesize(4)),0x40:pystub(c,1,this=True,ret=lambda e,k:s2 if k==0 else 0,side=writesize(4)),0x6c:pystub(c,1,this=True,side=writesize(12))})
 hook_rec(c,0x4e7480,1,this=True)
 db=r.getrandbits(32)
 hook_rec(c,0x6352f0,1,this=True,stackmark=(0,),side=lambda e,k:e.w32(e.arg32(0),db))
 seq=[r.getrandbits(32),r.choice([0,1,0x100,0xffffffff]),r.getrandbits(32)]
 hook_rec(c,0x4e5e60,0,this='mark',ret=lambda e,k:seq[min(k,2)])
 hook_rec(c,0x4e5e80,0,this='mark',st0=r.uniform(-100,100))
 hook_rec(c,0x4e5ef0,0,this='mark',ret=r.choice([0,1,0x100,0x101,0xffffffff]))
 return [p,load]
S(0x4ba200,'GUESS projectile load state','thiscall',None,ret='al',gen=gen)
