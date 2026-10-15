from pilot import S
from recruits_util import rnd,clear_hooks,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 me=rnd(c,0x8220);base=r.choice([0x10000000,0x20000000,0xffffffff]);gran=r.choice([16,32,256,1024]);e.w32(me+0x20f,base);e.w32(me+0x8217,gran);e.w32(me+0x213,r.getrandbits(32));i=r.choice([0,1,2,31,8186,8190,8191,8192]);offset=gran*i+r.randrange(gran);size=r.choice([0,1,gran-16,gran,gran*2,gran*6])
 return [me,(base+offset)&0xffffffff,size]
S(0x4d09b0,'GUESS mark_heap_span_pages','thiscall',None,ret=None,gen=gen)
