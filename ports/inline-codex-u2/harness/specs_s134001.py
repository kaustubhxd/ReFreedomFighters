from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub
import struct

def gen(c):
    clear_hooks(c);e=c.emu;r=c.rng
    n=r.randrange(7); flags=rnd(c,24*max(n,1)); bounds=rnd(c,48*max(n,1)); matrices=rnd(c,48*max(n,1))
    for i in range(max(n,1)):
        e.w8(flags+i*24+4,r.choice([0,8,0xff,16]))
    for block,size in [(bounds,48*max(n,1)),(matrices,48*max(n,1))]:
        e.wbytes(block,struct.pack('<'+'f'*(size//4),*[r.uniform(-10,10) for _ in range(size//4)]))
    def adjust(em,k):
        for a in range(2):
            p=em.arg32(a); f=struct.unpack('<f',em.rbytes(p,4))[0]; em.wf32(p,f+1.25)
    owner=obj(c,0x80,{0x58:pystub(c,1,this=True,ret=matrices)})
    me=obj(c,0x80,{0x2cc:pystub(c,0,this=True,ret=bounds),0x98:pystub(c,2,this=True,deref={0:9,1:3},side=adjust)})
    base=rnd(c,0x80);e.w32(base+0x6c,r.choice([0,1,2]));e.w32(me+8,base);e.w32(me+0x1c,flags);e.w32(me+0x20,n);e.w32(me+0x6c,owner)
    a=obj(c,0x40,{0x54:pystub(c,4,this=True),0x6c:pystub(c,3,this=True,deref={0:9,1:3,2:3}),0x80:pystub(c,3,this=True,deref={0:9,1:3})})
    b=obj(c,0x40,{0x94:pystub(c,2,this=True,deref={0:9,1:3},side=adjust)})
    e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
    return [me,a,b,r.getrandbits(32),r.getrandbits(32)]
S(0x462640,'GUESS draw flagged linked bounds','thiscall',None,ret=None,gen=gen)
