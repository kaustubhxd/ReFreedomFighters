import struct
from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
    clear_hooks(c);e=c.emu;r=c.rng
    def string(em,p):
        b=[]
        for k in range(32):
            v=em.rbytes(p+k,1)[0]
            if v==0:break
            b.append(v)
        return tuple(b)
    def log(em,_):
        fmt=em.arg32(3)
        head=tuple(em.arg32(k) for k in range(4))
        if fmt==0x6a3408:rest=(em.arg32(4),)
        elif fmt==0x6a3448:
            rest=(string(em,em.arg32(4)),)+tuple(em.arg32(k) for k in range(5,9))+(string(em,em.arg32(9)),em.arg32(10))
        else:rest=()
        em.calllog.append(('console',head,rest));em.ret()
    out=obj(c,0x20,{0x184:e.stub_fn('console',log)})
    sysobj(c,slots={0x190:pystub(c,0,this=True,ret=out)})
    me=rnd(c,0x8064)
    n=r.choice([-1,0,1,2,3,5]);tab=rnd(c,0x20)
    e.w32(me+0x803d,tab);e.w32(me+0x805d,n&0xffffffff)
    for i in range(max(n,0)):
        item=rnd(c,0x63e0) if r.randrange(5) else 0
        e.w32(tab+4*i,item)
        if item:
            ref=rnd(c,0x24) if r.randrange(3) else 0
            e.w32(item+0x5d,ref)
            e.wbytes(item+0x7d,bytes([r.randrange(2)]))
            e.wbytes(item+0x63d7,struct.pack('<f',r.uniform(-100,100)))
            if ref:e.w32(ref+8,r.choice([0,1,2,0x80000001,r.getrandbits(32)]))
    hook_rec(c,0x54db90,1,this=True,ret=r.getrandbits(32))
    return [me]
S(0x549e80,'GUESS print audio channel debug table','thiscall',None,ret=None,gen=gen,note='batch65992')
