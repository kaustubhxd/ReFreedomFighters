from pilot import S
from recruits_util import rnd,clear_hooks

def gen(c):
    clear_hooks(c);r=c.rng;e=c.emu
    n=r.choice([-2,-1,0,1,2,3,4,5,8,16,31])
    a=rnd(c,16*max(1,n));out=rnd(c,12)
    mode=r.randrange(4);axis=r.randrange(3)
    for j in range(max(0,n)):
        for k in range(4):
            if mode==0:x=r.randrange(-100,101)
            elif mode==1:x=r.getrandbits(32)
            elif mode==2:x=j if k==axis else 3
            else:x=j # equal variances
            e.w32(a+16*j+4*k,x&0xffffffff)
    return [n&0xffffffff,a,out]
S(0x63a580,'GUESS rank axes by integer sample variance','fastcall',None,ret=None,gen=gen,note='batch65994')
