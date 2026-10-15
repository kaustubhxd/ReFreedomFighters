from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;s=rnd(c,0x1000);src=s if r.randrange(4)==0 else rnd(c,0x1000)
 def copy(em,k):em.wbytes(em.reg('ecx')+4,em.rbytes(em.arg32(0)+4,32))
 hook_rec(c,0x56eb60,1,this=True,deref={0:16},side=copy)
 hook_rec(c,0x56ed00,1,this=True,deref={0:16},side=copy)
 hook_rec(c,0x7003b0,0,pop=0,ret=r.getrandbits(32))
 return [s,src]
S(0x56e9d0,'GUESS assign snapshot with nested records','thiscall',None,ret='eax',gen=gen)
