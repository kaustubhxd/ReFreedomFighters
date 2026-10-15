from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    vals=[(r.randrange(-100,101),r.randrange(-100,101),r.randrange(-100,101)) for _ in range(8)]
    def side(em,k):
        p=em.arg32(0); triple=vals[(k-1)%len(vals)]
        for i,v in enumerate(triple): em.w16(p+2*i,v & 0xffff)
    hook_rec(c,0x530e80,5,this=True,ret=lambda em,k:r.getrandbits(32),deref={1:3},side=side)
    selfp=rnd(c,0x20); obj=rnd(c,0x60)
    e.w32(selfp,obj)
    # Nonzero finite coordinate deltas avoid the source function's divide-by-zero paths.
    for off in (6,10,14,18,22,26): e.wf32(obj+off,r.choice([-8.0,-4.0,-2.0,1.0,3.0,7.0,12.0]))
    for off in (0x3c,0x40,0x44): e.w32(obj+off,r.choice([1,2,3,10,100]))
    point=rnd(c,0x10)
    for i,off in enumerate((6,10,14)):
        e.wf32(point+4*i,e.rf32(obj+off)+r.choice([1.0,2.0,4.0]))
    output=rnd(c,0x10); flag=rnd(c,1)
    return [selfp,output,point,flag]
S(0x530bf0,'GUESS scale widget point','thiscall',None,ret=None,gen=gen,note='batch104021')
