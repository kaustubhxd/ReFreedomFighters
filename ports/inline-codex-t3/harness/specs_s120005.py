from pilot import S
from recruits_util import rnd,clear_hooks,pystub,hook_rec

def setpos(c):
    clear_hooks(c);e,r=c.emu,c.rng
    e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
    it=rnd(c,0x40);oct=rnd(c,0x50);pos=rnd(c,6)
    e.w32(it,oct)
    levels=r.choice([0,1,4,31,32,33,64,r.getrandbits(32)]);e.w32(oct+0x38,levels)
    level=r.choice([levels,levels-1,levels+1,r.getrandbits(32)])&0xffffffff
    e.w32(it+0x12,level if r.random()<0.35 else r.getrandbits(32))
    data=bytes(r.getrandbits(8) for _ in range(12))
    def output(em,k):em.wbytes(em.arg32(0),data)
    hook_rec(c,0x5307c0,3,this=True,stackmark=(0,),deref={1:-6},side=output,ret=r.choice([0,1,r.getrandbits(32)]))
    return [it,pos,level]
S(0x531740,'GUESS_octree_iterator_set_position','thiscall',None,ret='ax',gen=setpos)
