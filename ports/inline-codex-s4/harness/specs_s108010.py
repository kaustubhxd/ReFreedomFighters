from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def base(c):
 clear_hooks(c);c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))

def gfd00(c):
 base(c);e=c.emu;r=c.rng
 ids=[r.choice([0,r.getrandbits(32)|1]) for _ in range(2)]
 current=[];records={}
 for ident in ids:
  cap=r.choice([0,1,10,100,0xffffffff,r.getrandbits(32)])
  cur=r.choice([0,cap,max(0,cap-1),r.getrandbits(32)])
  current.append(cur)
  rec=rnd(c,0x10);e.w32(rec+8,r.choice([0,1,2,3,99,0xffffffff,r.getrandbits(32)]));e.w32(rec+12,cap);records[ident]=rec
 weapons=[rnd(c,4),rnd(c,4)];ammo=[rnd(c,4),rnd(c,4)]
 def setup(em,k):em.w32(em.arg32(0),ids[k]);em.w32(em.arg32(1),current[k])
 hook_rec(c,0x5af5b0,3,this=True,deref={0:1,1:1},side=setup)
 hook_rec(c,0x5af130,1,this=True,ret=lambda em,k:records[em.arg32(0)])
 def change(em,k):
  p=ammo[k%2];em.w32(p,(em.r32(p)+3)&0xffffffff)
 hook_rec(c,0x5af7c0,3,this=True,side=change if r.randrange(3)==0 else None)
 me=rnd(c,0x50);e.w32(me+0x14,rnd(c,0x20))
 return [me,weapons[0],ammo[0],weapons[1],ammo[1]]

def gebe00(c):
 base(c);e=c.emu;r=c.rng
 me=obj(c,0x80,{0x18:pystub(c,0,this=True)})
 count=r.randrange(7);e.w32(me+0x3e,count);e.w32(me+0x3a,rnd(c,0x10))
 info=rnd(c,12)
 array=rnd(c,4*16)
 mode=r.randrange(3)
 if mode==0:count=min(count,1);e.w32(me+0x3e,count)
 e.w32(me+0x66,0 if mode==0 else array)
 e.w32(me+0x6a,(4*count if mode==0 else array+4*(0 if mode==1 else count+2)))
 outputs=[rnd(c,0x2c) for _ in range(count)]+[rnd(c,max(4,0x28*count))]
 hook_rec(c,0x41e290,1,pop=0,ret=lambda em,k:outputs[k])
 # Growth inserts the pointer by value, avoiding the stack-local pointer's address.
 def grow(em,k):
  record=em.r32(em.arg32(1));index=k
  em.w32(array+4*index,record)
  em.w32(me+0x66,array+4*(index+1));em.w32(me+0x6a,array+4*(index+1))
 hook_rec(c,0x5fe3b0,2,this=True,deref={1:1},side=grow)
 return [me,info,r.getrandbits(32),r.getrandbits(32),r.choice([0,0x10000,r.getrandbits(32)]),r.choice([0,0x10000,r.getrandbits(32)])]
S(0x5afd00,'GUESS give third of ammo-box amount to two weapons','thiscall',None,ret='al',gen=gfd00)
S(0x5ebe00,'GUESS create repeated records and allocate backing array','thiscall',None,ret=None,gen=gebe00)
