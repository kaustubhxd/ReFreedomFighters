from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 n=r.choice([8,16,32,64,128]);out=rnd(c,4*n)
 hook_rec(c,0x634df4,2,pop=0,ret=out,side=lambda e,k:e.wbytes(out,bytes(4*n)))
 hook_rec(c,0x634d52,1,pop=0)
 left=r.randrange(n//2+1);right=r.randrange(n//2+1)
 return [r.choice([0,0,0,1,2]),n,left,right]
S(0x406470,'GUESS vorbis asymmetric window','cdecl',None,ret='eax',gen=gen)
