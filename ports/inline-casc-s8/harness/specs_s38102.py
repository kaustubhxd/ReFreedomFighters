"""Load scripted event records. Covers existing IDs and both creation modes, optional payloads,
assertions and error logs. Missing IDs / invalid kinds dereference null in exe and are excluded.
"""
from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec
import struct

def gen(c):
    clear_hooks(c); e,r=c.emu,c.rng
    def action(slot):
        def h(em,_):
            p=em.reg('ecx'); em.calllog.append(('action',slot,p,em.arg32(0)))
            if slot==0x20 and r.random()<0.4: em.w32(p+4,em.r32(p+4)&~0x40)
            em.ret(eax=r.choice([0,1,1]),argbytes=4)
        return e.stub_fn('action',h)
    items=[obj(c,0x60,{0x20:action(0x20),0x28:action(0x28)}) for _ in range(5)]
    for i,p in enumerate(items):
        e.w32(p+0x20,i+1); e.w32(p+0x28,items[i+1] if i+1<len(items) else 0)
        e.w32(p+0x1c,r.choice([0,1])); e.w32(p+4,r.getrandbits(32))
        d=rnd(c,0x10); e.w32(p+0x40,d)
    def tablecall(slot):
        return e.stub_fn('tablecall',lambda em,_:(em.calllog.append(('table',slot,em.reg('ecx'))),em.ret(eax=0,argbytes=0)))
    system=sysobj(c,table_size=0x5d40,table_slots={0x74:tablecall(0x74),0x78:tablecall(0x78)})
    t=e.r32(system+0x9b)
    e.w32(t+0x5d29,items[0])
    def create(slot):
        def h(em,_):
            em.calllog.append(('create',slot,em.reg('ecx'),em.arg32(0),em.arg32(1)))
            em.ret(eax=r.choice(items),argbytes=8)
        return e.stub_fn('create',h)
    factories=[obj(c,0x30,{0x108:create(0x108),0x10c:create(0x10c),0x110:create(0x110)}) for _ in range(3)]
    classes=rnd(c,0x150)
    for i,f in enumerate(factories): e.w32(classes+i*0x70+0x54,f)
    data=rnd(c,0x10); e.w32(data+4,classes)
    s=rnd(c,0x40); e.w32(s+0x14,data)
    seq=[]
    for _ in range(r.randrange(4)):
        seq.append(r.randrange(3))
        for _ in range(r.randrange(4)):
            if r.random()<0.7:
                seq.append(0x80000000); kind=r.choice([0,1]); seq.append(kind)
                seq.extend([r.getrandbits(32),r.getrandbits(32)])
            else: seq.append(r.randrange(1,6))
            seq.append(r.choice([0,1,2]))
        seq.append(0xffffffff)
    seq.append(0xffffffff)
    state={'i':0}
    def read(em,_):
        dst,num=em.arg32(0),em.arg32(1); i=state['i']; state['i']+=1
        val=seq[i]; em.calllog.append(('read',num,val)); em.w32(dst,val); em.ret(eax=0,argbytes=8)
    def simple(slot):
        return e.stub_fn('simple',lambda em,_:(em.calllog.append(('stream',slot,em.arg32(0))),em.ret(eax=0,argbytes=4)))
    def name(em,_):
        val=r.getrandbits(32); em.w32(em.arg32(0),val); em.calllog.append(('name',val)); em.ret(eax=0,argbytes=4)
    st=obj(c,0x30,{0xc:simple(0xc),0x18:e.stub_fn('read',read),0x34:simple(0x34),0x60:e.stub_fn('name',name)})
    def log(em,_):
        em.calllog.append(('log',em.arg32(0),em.arg32(1),em.arg32(2))); em.ret(eax=0,argbytes=0)
    lo=obj(c,0x20,{0x2c:e.stub_fn('log',log)})
    def lg(em,_):
        em.calllog.append(('logger',em.arg32(0),em.arg32(1))); em.ret(eax=lo,argbytes=8)
    logger=obj(c,0x20,{0x20:e.stub_fn('logger',lg)}); e.w32(0x700390,logger)
    e.w32(0x7003b0,e.stub_fn('assert',lambda em,_:(em.calllog.append(('assert',)),em.ret(eax=r.getrandbits(32),argbytes=0))))
    return [s,st]
S(0x497fe0,'GUESS load event records','thiscall',None,ret=None,gen=gen,note='batch38102')
