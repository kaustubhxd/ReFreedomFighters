"""Dependency predicate: valid type-3 direct owners or type-1 indirections.
Lookups may fail initially, fallback always succeeds (double-null path dereferences null in exe).
Logs include source lines and arguments; predicate and flag paths return AL.
"""
from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec
import struct

def gen(c):
    clear_hooks(c); e,r=c.emu,c.rng
    targets=[]
    for i in range(5):
        base=rnd(c,0x50); e.w32(base+4,r.choice([0,0,1,2]))
        e.wbytes(base+0x32,bytes([r.choice([0,0x10,0xff])]))
        targets.append(base+4)
    def first(em,_):
        k=em.arg32(0); em.calllog.append(('first',em.reg('ecx'),k))
        em.ret(eax=0 if r.random()<0.35 else targets[k%5],argbytes=4)
    def second(em,_):
        k=em.arg32(0); em.calllog.append(('second',em.reg('ecx'),k))
        em.ret(eax=targets[k%5],argbytes=4)
    table=obj(c,0x30,{0x58:e.stub_fn('fallback',second)})
    own=obj(c,0x40,{0x10:e.stub_fn('first',first)})
    e.w32(own+4,3); e.wbytes(own+0x11,struct.pack('<I',table))
    op=own+4
    if r.random()<0.5:
        op=rnd(c,0x20); e.w32(op,1); e.w32(op+8,own+4)
    nodes=[]
    for i in range(r.randrange(6)):
        n=rnd(c,0x10); e.w32(n,r.randrange(20)); e.wbytes(n+8,bytes([r.choice([0,1,2])]))
        nodes.append(n)
    def begin(em,_):
        em.w32(em.arg32(0),0); em.calllog.append(('begin',)); em.ret(eax=0,argbytes=4)
    def nxt(em,_):
        p=em.arg32(0); i=em.r32(p); em.w32(p,i+1)
        em.calllog.append(('next',i)); em.ret(eax=nodes[i] if i<len(nodes) else 0,argbytes=4)
    li=obj(c,0x30,{0x4c:e.stub_fn('begin',begin),0x64:e.stub_fn('next',nxt)})
    s=rnd(c,0x50); e.w32(s+0xc,op); e.wbytes(s+0x3e,struct.pack('<I',li if r.random()<0.9 else 0))
    hook_rec(c,0x437d60,0,this=True,pop=0,ret=lambda em,k:r.choice([0,1]))
    def log(em,_):
        em.calllog.append(('log',em.arg32(0),em.arg32(1))); em.ret(eax=0,argbytes=0)
    lo=obj(c,0x20,{0x2c:e.stub_fn('log',log)})
    def getlog(em,_):
        em.calllog.append(('getlog',em.arg32(0),em.arg32(1))); em.ret(eax=lo,argbytes=8)
    logger=obj(c,0x30,{0x20:e.stub_fn('getlog',getlog)})
    e.w32(0x700390,logger)
    return [s]
S(0x438380,'GUESS dependency predicate','thiscall',None,ret='al',gen=gen,note='batch38099')
