from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def base(c):
 clear_hooks(c)
 c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))

def gf2f0(c):
 base(c);e=c.emu;r=c.rng
 me=rnd(c,0x3700)
 n=r.randrange(10)
 pool=me+0x2d0
 slots=r.sample(range(128),n)
 for i,k in enumerate(slots):
  item=pool+104*k;e.w32(me+0xd0+4*i,item)
  e.w32(item+0x24,r.choice([0,1,2,3,4,5,6,7,8,0x80000001,0x80000002]))
 e.w32(me+0xc8,r.choice([0,1,1,r.getrandbits(32)]))
 e.w32(me+0xcc,n);e.w32(me+0xc4,r.choice([0,1,2,5,0xffffffff,0x80000000]))
 e.w16(pool+0x3400,n);e.w16(pool+0x3402,r.choice([0xffff,1,127]))
 hook_rec(c,0x65f070,1,this=True,deref={0:10})
 # Callee can set the low flag bit; the caller must reload flags afterward.
 def step(em,k):
  item=em.arg32(0);flags=em.r32(item+0x24)
  em.w32(item+0x24,flags^1)
 hook_rec(c,0x65e3b0,1,this=True,deref={0:10},side=step)
 hook_rec(c,0x65f210,1,this=True,deref={0:10})
 return [me]

def ga160(c):
 base(c);e=c.emu;r=c.rng
 first=rnd(c,0x108)+8;second=rnd(c,0x108)+8
 e.w32(first-8,0x100|r.choice([0,0x80000000,0xe0000000]))
 e.w32(second-8,0x100|r.choice([0,0x80000000,0xe0000000]))
 firstbase=r.choice([0,first,first]);secondbase=r.choice([0,second,second])
 flag=r.choice([0,1,0x100,0x101,0x80000000,255])
 manager=obj(c,0x20,{0x14:pystub(c,1,this=True,ret=flag),0x10:pystub(c,1,this=True,ret=r.getrandbits(32))})
 holder=rnd(c,0x20);e.w32(holder+0x18,manager)
 system=sysobj(c,table_size=0x1d00,table_slots={0x17c:pystub(c,0,this=True,ret=first+r.randrange(16)),0x180:pystub(c,0,this=True,ret=second+r.randrange(16))})
 table=e.r32(system+0x9b);e.w32(table+0x1c5d,firstbase);e.w32(table+0x44,secondbase);e.w32(system+0x1aa3,holder)
 ref=r.choice([0,first-1,first,first+1,first+255,first+256,second-1,second,second+255,second+256,r.getrandbits(32)])
 me=obj(c,0x20,{0xc:pystub(c,1,this=True)})
 return [me,ref]
S(0x65f2f0,'GUESS process flagged pool items with bounded refresh budget','thiscall',None,ret=None,gen=gf2f0)
S(0x49a160,'GUESS serialize reference type and offset','thiscall',None,ret=None,gen=ga160)
