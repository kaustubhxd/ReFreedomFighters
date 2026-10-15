from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def fb(c): return struct.unpack('<I',struct.pack('<f',c.rng.uniform(-8.0,8.0)))[0]
def g589b50(c):
    clear_hooks(c);e=c.emu;r=c.rng
    n=r.randrange(1,4);arr=rnd(c,4*(n+1));e.w32(arr,n)
    for i in range(n):
        vals=[fb(c) for _ in range(3)]
        def side(em,k,values=vals):
            a=em.arg32(0);b=em.arg32(1)
            for j,v in enumerate(values): em.w32(a+4*j,v);em.w32(b+4*j,v)
        slot=pystub(c,2,this=True,stackmark=(0,1),side=side)
        item=obj(c,4,{0x57c:slot});e.w32(arr+4+4*i,item)
    out=rnd(c,12)
    hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('eax'))
    return [arr,out]

S(0x589b50,'GUESS average callback vectors','thiscall',None,ret=None,gen=g589b50,note='batch100006')
