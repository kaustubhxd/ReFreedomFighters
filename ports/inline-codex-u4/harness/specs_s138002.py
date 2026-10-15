from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub,sysobj,reftab_vt

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 s=rnd(c,0x5400)
 enabled=r.choice([0,1,2,255]);e.w8(s+0x50a9,r.choice([enabled,0,1,255]))
 ids=[r.getrandbits(32) for _ in range(r.randrange(8))]
 actors={}
 for idx in ids:
  a=rnd(c,0x80) if r.randrange(4) else 0
  if a:
   e.w32(a+0x40,r.getrandbits(32));e.w32(a+0x6c,r.choice([0,1,0xffffffff,0x7fffffff,0x80000000,r.getrandbits(32)]))
  actors[idx]=a
 sys=sysobj(c,table_slots={0x60:pystub(c,1,this=True,ret=lambda em,k:actors.get(em.arg32(0),0))})
 e.w32(sys+0x1c,r.getrandbits(32))
 e.w32(s+0x53b2,reftab_vt(c,ids))
 hook_rec(c,0x534010,1,this=True)
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [s,enabled]
S(0x5380a0,'GUESS togglePause','thiscall',None,ret=None,gen=gen)
