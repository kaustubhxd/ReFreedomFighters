from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu;e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 target=obj(c,0x20,{0x250:pystub(c,0,this=True),0x254:pystub(c,0,this=True)})
 player=obj(c,0x20,{0xac:pystub(c,2,this=True),0xb8:pystub(c,1,this=True)})
 sys=rnd(c,0x1920);e.w32(0x70039c,sys);e.w32(sys+0x190f,player)
 hook_rec(c,0x5da470,0,this=True,ret=r.choice([0,target,target,target]))
 hook_rec(c,0x5da670,2,this=True,deref={1:4})
 me=rnd(c,0x80);codes=r.sample(range(65536),3)
 for off,v in zip([0x50,0x52,0x54],codes):e.wbytes(me+off,v.to_bytes(2,'little'))
 e.w32(me+0x4c,r.choice([0,0,1,2,3,0xffffffff]))
 return [me,r.choice(codes+[r.randrange(65536)])|(r.randrange(65536)<<16),r.getrandbits(32)]
S(0x5da160,'GUESS handle three playback transition commands','thiscall',None,ret='eax',gen=g,note='batch124020')
