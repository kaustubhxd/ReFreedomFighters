from pilot import S
from recruits_util import rnd,clear_hooks,pystub

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu;e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 n=r.choice([0,1,2,3,4,5,7,8,28,31,32,33,63,64,65,127,128,129,255,r.randrange(256)])
 mem=rnd(c,768,16);a=mem+r.randrange(8)
 b=r.choice([a,a+1,a+4,a+16,a+128,mem+384+r.randrange(8)])
 if r.random()<.5:a,b=b,a
 return [a,b,n]
S(0x4f9520,'GUESS xor swap memory blocks','fastcall',None,ret=None,gen=g,note='batch124013')
