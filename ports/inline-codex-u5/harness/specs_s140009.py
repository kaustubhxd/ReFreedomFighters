from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 stream=obj(c,0x20,{off:pystub(c,1,this=True) for off in [0x3c,0x40,0x44,0x4c,0x64]})
 me=rnd(c,0x90);e.w32(me+0x7f,r.randrange(0,9));e.wbytes(me+0x19,bytes([r.choice([0,1,2,255])]))
 e.wbytes(me+0x7e,bytes([r.choice([0,1,2,255])]))
 nested=obj(c,0x20,{0x10:pystub(c,1,this=True)});e.w32(me+0x6a,nested)
 count=r.randrange(0,8);entries=rnd(c,max(16,count*16));e.w32(me+0x6e,entries);e.w32(me+0x72,entries+16*count)
 hook_rec(c,0x49b3a0,8,this=True)
 return [me,stream]
S(0x5ac4b0,'GUESS serialize packed control record','thiscall',None,ret=None,gen=gen)
