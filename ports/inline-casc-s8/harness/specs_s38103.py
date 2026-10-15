"""Read packed 0xfd-byte records and trailer arrays. Field reads write random contents;
counts scripted small or negative. Reset and handle-reader callees hooked and logged.
"""
import struct
from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec

def gen(c):
    clear_hooks(c); e,r=c.emu,c.rng
    s=rnd(c,0x1020); recs=rnd(c,0x600); trailer=rnd(c,0x30)
    e.w32(s,trailer); e.w32(s+8,recs)
    b1,b2=rnd(c,0x40),rnd(c,0x40); e.w32(trailer+4,b1); e.w32(s+4,b2)
    manager=rnd(c,0x10b0); system=sysobj(c); e.w32(system+0x1a9f,manager)
    def read(slot,width):
        def h(em,_):
            p=em.arg32(0)
            if p==s+0x100c: data=struct.pack('<I',r.choice([0,1,2,3,0xffffffff]))
            elif p==trailer+0x10: data=struct.pack('<I',r.randrange(5))
            else: data=bytes(r.getrandbits(8) for _ in range(width))
            em.calllog.append(('read',slot,p,data)); em.wbytes(p,data); em.ret(eax=0,argbytes=4)
        return e.stub_fn('read',h)
    def bulk(em,_):
        p,n=em.arg32(0),em.arg32(1)
        em.calllog.append(('bulk',p,n)); em.wbytes(p,bytes(r.getrandbits(8) for _ in range(n))); em.ret(eax=0,argbytes=8)
    def slot70(em,_):
        em.calllog.append(('slot70',em.arg32(0))); em.ret(eax=0,argbytes=4)
    st=obj(c,0x30,{0x40:read(0x40,4),0x48:read(0x48,4),0x50:read(0x50,4),0x58:read(0x58,2),0x6c:read(0x6c,12),0x70:e.stub_fn('slot70',slot70),0x18:e.stub_fn('bulk',bulk)})
    hook_rec(c,0x534190,0,this=True,pop=0,ret=0)
    hook_rec(c,0x534480,1,this=True,pop=4,ret=lambda em,k:r.getrandbits(32))
    def log(em,_):
        em.calllog.append(('log',em.arg32(0),em.arg32(1),em.arg32(2))); em.ret(eax=0,argbytes=0)
    lo=obj(c,0x20,{0x2c:e.stub_fn('log',log)})
    def lg(em,_):
        em.calllog.append(('logger',em.arg32(0),em.arg32(1))); em.ret(eax=lo,argbytes=8)
    logger=obj(c,0x20,{0x20:e.stub_fn('logger',lg)}); e.w32(0x700390,logger)
    return [s,st]
S(0x534220,'GUESS load packed records','thiscall',None,ret=None,gen=gen,note='batch38103')
