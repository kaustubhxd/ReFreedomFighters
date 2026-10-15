"""XML context serializer. Grow hook extends a bounded output pool or fails.
Arrays contain null, disabled and active entries; byte output, cursor, calls and return compared.
"""
from pilot import S
from recruits_util import rnd, clear_hooks

def gen(c):
    clear_hooks(c)
    e,r=c.emu,c.rng
    s=rnd(c,0x280)
    out=rnd(c,0x400)
    def string():
        b=bytes(r.choice(b'abCD012') for _ in range(r.randrange(9)))
        p=rnd(c,16); e.wbytes(p,b+b'\0'); return p
    def value():
        v=rnd(c,0x20); p=rnd(c,16)
        e.w32(v+0x10,p); e.w32(v+0x14,r.choice([0,1,2,3,7,8,0xffffffff]))
        return v
    e.w32(s+0x1e0, value() if r.random()<0.65 else 0)
    e.wbytes(s+0x268,bytes([r.choice([0,1,2])]))
    for off,cnt,attrs in [(0x194,0x198,True),(0x158,0x15c,False)]:
        n=r.randrange(5); a=rnd(c,0x20)
        for i in range(n):
            item=0
            if r.random()<0.8:
                item=rnd(c,0x24); e.w32(item,string())
                if attrs: e.w32(item+4,value() if r.random()<0.75 else 0)
                else: e.wbytes(item+0x1c,bytes([r.choice([0,1,2])]))
            e.w32(a+i*4,item)
        e.w32(s+off,a); e.w32(s+cnt,n)
    e.w32(s+0x238,out)
    e.w32(s+0x234,out+r.choice([0,1,2,3,7,16,32,128]))
    e.w32(s+0x23c,out)
    def grow(em,_):
        pool=em.arg32(0)
        cursor=em.r32(pool+12)
        ok=r.random()<0.8
        em.calllog.append(('grow',pool,cursor,ok))
        if ok: em.w32(pool+8,cursor+r.choice([1,2,3,8,32]))
        em.ret(eax=int(ok),argbytes=0)
    e.hook(0x6206e0,grow)
    return [s]
S(0x61f7f0,'GUESS XML context serializer','cdecl',None,ret='eax',gen=gen,note='batch38098')
