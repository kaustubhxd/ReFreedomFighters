from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 n=r.randrange(6);capacity=n+r.randrange(3);data=rnd(c,(capacity+1)*64)+64
 if n==0 and capacity==0 and r.randrange(2):data=0
 at=data+64*r.randrange(n+1)
 s=rnd(c,12);e.w32(s,data);e.w32(s+4,data+n*64);e.w32(s+8,data+capacity*64)
 value=r.choice([rnd(c,64),data+64*r.randrange(n)]) if n else rnd(c,64)
 allocation=rnd(c,max(1,n*2)*64)
 hook_rec(c,0x6014a0,1,ret=allocation)
 hook_rec(c,0x54f870,2,this=True)
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [s,at,value]
S(0x5a3550,'GUESS insertRecord','thiscall',None,ret=None,gen=gen)
