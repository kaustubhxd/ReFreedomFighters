import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;n=r.choice([0,1,2,3,4,8,16,20,32]);p=rnd(c,max(53,n*53));shape=r.randrange(5)
 keys=[r.choice([-1.,0.,1.,r.uniform(-100,100)]) for _ in range(n)]
 if shape==0:keys.sort()
 if shape==1:keys.sort(reverse=True)
 if shape==2:keys=[0.]*n
 for i,key in enumerate(keys):e.wbytes(p+i*53,struct.pack('<f',key))
 hook_rec(c,0x7003b0,0,pop=0,ret=r.getrandbits(32))
 return [p,p+n*53]
S(0x4add60,'GUESS insertion sort 53 byte records','fastcall',None,ret=None,gen=gen)
