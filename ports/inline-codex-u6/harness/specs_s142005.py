import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 p=rnd(c,36);cols=r.randrange(1,5);rows=r.randrange(0,15);mode=r.choice([0,1,1,2,2,3,-1]);root=r.choice([2,3,4])
 src=rnd(c,max(root,cols*rows,1)*4);dst=rnd(c,max(4,cols*rows*4))
 for i in range(max(root,cols*rows,1)):e.w32(src+4*i,r.choice([0,1,-1,2147483647,-2147483648,r.randrange(-10000,10000)])&0xffffffff)
 for i,v in enumerate([cols,rows,0,mode,r.getrandbits(32),r.getrandbits(32),0,r.choice([0,1,5]),src]):e.w32(p+4*i,v&0xffffffff)
 scale=r.uniform(-2,2);bias=r.uniform(-20,20)
 hook_rec(c,0x4050a0,1,pop=0,st0=lambda em,k:scale if k==0 else bias)
 hook_rec(c,0x634df4,2,pop=0,ret=dst)
 hook_rec(c,0x4053f0,1,pop=0,ret=root)
 return [p]
S(0x405460,'GUESS build scaled absolute coefficient table','cdecl',None,ret='eax',gen=gen)
