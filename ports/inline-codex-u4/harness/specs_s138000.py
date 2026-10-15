from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,logger

def gen(c):
    clear_hooks(c)
    e=c.emu; r=c.rng
    self=rnd(c,0x80); stream=rnd(c,0x40)
    e.w8(stream+0xc,r.choice([0,0,1,255]))
    keys=[]
    for i in range(8):
        key=e.r32(0x6a7400+4*i)
        if not key: break
        keys.append(key)
    vals=[r.choice([1,1,1,0,2,0xffffffff])]+[r.getrandbits(32) for _ in range(8)]
    for key in keys:
        vals += [r.choice([0,0,1,0xffffffff]),r.getrandbits(32)]
    vals += [r.getrandbits(32)]
    cursor=e.alloc(4)
    def read(em,k):
        i=em.r32(cursor)
        em.w32(em.arg32(0),vals[i]); em.w32(cursor,i+1)
    hook_rec(c,0x5f0280,1,this=True,stackmark=(0,),side=read)
    hook_rec(c,0x5af2a0,2,this=True)
    hook_rec(c,0x5aee20,2,this=True)
    hook_rec(c,0x7003b0,2,ret=r.getrandbits(32),pop=0)
    logger(c)
    return [self,stream]
S(0x5b0810,'GUESS readSettings','thiscall',None,ret='al',gen=gen)
