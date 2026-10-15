from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub,logger

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 slots=rnd(c,12*8)
 for i in range(12):e.w8(slots+i*8+4,0)
 args=rnd(c,32)
 def lookup(em,k):return slots+(em.arg32(0)%12)*8
 hook_rec(c,0x5003d0,1,this=True,ret=lookup)
 entity=obj(c,0x80,{0x4c:pystub(c,0,this=True,ret=args)})
 table=obj(c,0x40,{0x18:pystub(c,1,this=True,ret=r.choice([0,entity,entity]))})
 logger(c,3);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 values=rnd(c,48)
 return [table,r.getrandbits(32),values]
S(0x551a70,'GUESS populate twelve entity arguments','stdcall',None,ret='eax',gen=gen)
