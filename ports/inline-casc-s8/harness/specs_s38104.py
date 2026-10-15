"""Render-state defaults. Randomize cached globals and object bytes before reset.
Stage counts straddle zero, SIMD unroll and adjacent-array overlap boundaries.
"""
from pilot import S
from recruits_util import rnd,obj,clear_hooks

def gen(c):
    clear_hooks(c); e,r=c.emu,c.rng
    e.wbytes(0x724840,bytes(r.getrandbits(8) for _ in range(0x1d0)))
    e.w32(0x724a08,r.choice([0,1,2,3,4,5,7,8,9,12,16]))
    def method(em,_):
        p=em.reg('ecx'); em.calllog.append(('method',p)); em.ret(eax=0,argbytes=0)
    s=obj(c,0x1500,{0x13c:e.stub_fn('method',method)})
    def memset(em,_):
        p,v,n=em.arg32(0),em.arg32(1),em.arg32(2)
        em.calllog.append(('memset',p,v,n)); em.wbytes(p,bytes([v&255])*n); em.ret(eax=p,argbytes=0)
    e.hook(0x634d10,memset)
    return [s]
S(0x60f8e0,'GUESS reset render-state defaults','thiscall',None,ret=None,gen=gen,note='batch38104')
