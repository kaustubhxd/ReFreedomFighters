from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub
import struct

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    def floats(n): return [r.uniform(-100,100) for _ in range(n)]
    def put(p,vs): e.wbytes(p,struct.pack('<'+'f'*len(vs),*vs))
    q=floats(4); pos=floats(3); axes=[floats(3) for _ in range(3)]
    def output(vs):
        def side(em,k): em.wbytes(em.arg32(0),struct.pack('<'+'f'*len(vs),*vs))
        return side
    rect=obj(c,0x80,{0x240:pystub(c,1,this=True,nullflag=(0,),side=output(q))})
    state=rnd(c,0x80); e.w32(state+0x6f,rect)
    a=obj(c,0x80,{0x1e0:pystub(c,1,this=True,ret=r.choice([0,1,2,255,256])),0x2c4:pystub(c,0,this=True,ret=state),0x70:pystub(c,1,this=True,deref={0:3})})
    def transform(em,k):
        em.wbytes(em.arg32(1),struct.pack('<3f',*pos))
    def axis(em,k): em.wbytes(em.arg32(0),struct.pack('<3f',*axes[k%3]))
    b=obj(c,0x80,{0x278:pystub(c,2,this=True,deref={0:3},nullflag=(1,),side=transform),0x84:pystub(c,1,this=True,deref={0:3},side=output(pos)),0x88:pystub(c,1,this=True,deref={0:3},side=axis)})
    put(b+0x5c,[r.choice([0.1,1,10,-2,3.25])])
    dest=obj(c,0x80,{0x7c:pystub(c,2,this=True,deref={0:9,1:3})})
    sys=sysobj(c); e.w32(sys+0x6f,r.choice([0,1,640,1920,0x7fffffff,0x80000000])); e.w32(sys+0x73,r.choice([0,1,480,1080,0x7fffffff,0x80000000]))
    e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
    me=rnd(c,0x100); e.w32(me+0x44,a); e.w32(me+0x56,b); e.w32(me+0x4e,dest); put(me+0x8b,floats(2))
    return [me]
S(0x4a93b0,'GUESS update normalized UI placement','thiscall',None,ret=None,gen=gen)
