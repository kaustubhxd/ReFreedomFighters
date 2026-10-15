from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def base(c):
 clear_hooks(c)
 c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))

def gcae0(c):
 base(c);e=c.emu;r=c.rng
 me=obj(c,0x600,{0x130:pystub(c,3,this=True)})
 e.w16(me+0x5d3,r.getrandbits(16));e.w16(me+0x5d5,r.getrandbits(16))
 target=obj(c,0x20,{0x8c:pystub(c,1,this=True,deref={0:3}),0x184:pystub(c,1,this=True,deref={0:3},ret=r.choice([0,1,0x100,0x101,255]))})
 projectile=obj(c,0x20,{0x330:pystub(c,0,this=True,ret=r.choice([0,3,4,4,7,7,8,0xffffffff])),0x32c:pystub(c,0,this=True,ret=r.choice([0,1,0x100,0x101,255]))})
 source=r.choice([0,me,rnd(c,0x20)])
 ids=r.sample(range(1,1000000),4)
 mapping={ids[0]:source,ids[1]:rnd(c,0x20),ids[2]:r.choice([0,projectile,projectile]),ids[3]:target}
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:mapping[em.arg32(0)])})
 e.w32(me+0x479,r.choice([0,ids[3],ids[3]]))
 hit=rnd(c,0x20);e.w32(hit,rnd(c,0x40))
 e.w32(hit+0xc,ids[0]);e.w32(hit+8,ids[1]);e.w32(hit+0x10,ids[2])
 return [me,hit]

def g33f0(c):
 base(c);e=c.emu;r=c.rng
 data=rnd(c,0x1210);counts=[r.randrange(5) for _ in range(4)]
 for off,n in zip((0x11e9,0x11f1,0x11ed,0x11f5),counts):e.w32(data+off,n)
 lengths=[counts[0]*164,counts[1]*12,counts[2]*8,counts[3]*4]
 for off,n in zip((0x11f9,0x11fd,0x1201,0x1205),lengths):e.w32(data+off,rnd(c,max(n,4)))
 output=rnd(c,0x1000)
 hook_rec(c,0x41e290,1,ret=output,pop=0)
 def copy(em,k):
  d,s,n=em.arg32(0),em.arg32(1),em.arg32(2)
  if n:em.wbytes(d,em.rbytes(s,n))
 hook_rec(c,0x634d22,3,pop=0,side=copy,ret=lambda em,k:em.arg32(0))
 me=rnd(c,0x5310);e.w32(me+0x52fe,data)
 return [me,rnd(c,4)]
S(0x51cae0,'GUESS classify projectile hit and send heli event','thiscall',None,ret=None,gen=gcae0)
S(0x5333f0,'GUESS pack four arrays behind count header','thiscall',None,ret='eax',gen=g33f0)
