from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu;e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 target=obj(c,16,{0xbc:pystub(c,1,this=True),0x250:pystub(c,1,this=True)})
 me=rnd(c,0x80);e.w32(me+0x44,target)
 codes=r.sample(range(65536),2)
 for off,v in zip([0x50,0x52],codes):e.wbytes(me+off,v.to_bytes(2,'little'))
 sys=r.choice([rnd(c,0x50),me+0x18]);e.w32(0x70039c,sys);e.w32(sys+0x40,r.getrandbits(32))
 return [me,r.choice(codes+[r.randrange(65536)])|(r.randrange(65536)<<16),r.choice([0,0,1,1000,0xffffffff,0x80000000,r.getrandbits(32)])]
S(0x5d6d40,'GUESS start timed opacity transition','thiscall',None,ret='eax',gen=g,note='batch124023')
