"""Render entry compaction and sorted pending merge. qsort logs records by content.
Small lists cover prefix retention, removals, rekeys, disabled queue items and both merge orientations.
"""
import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
    clear_hooks(c); e,r=c.emu,c.rng
    s=rnd(c,0x18200)
    queue=rnd(c,0x100)
    e.wbytes(s+0x181c5,struct.pack('<I',queue))
    def mk(flags=None):
        p=rnd(c,0x30)
        e.wbytes(p+5,bytes([flags if flags is not None else r.choice([0,1,8,9,3,11])]))
        a=rnd(c,0x20); d=rnd(c,0x20); ob=rnd(c,0x30)
        e.wbytes(a+0xa,struct.pack('<H',r.choice([0,1,2])))
        e.w32(a+0x10,d); e.w32(d+8,ob)
        res=rnd(c,0x20); desc=rnd(c,0x10); e.w32(res+0xc,desc)
        e.wbytes(desc,struct.pack('<H',r.choice([0,1,0x7ff,0x800,0xffff,r.randrange(65536)])))
        e.w32(d+0x10,res if r.random()<0.75 else 0)
        e.w32(p+8,a)
        mat=rnd(c,0x80); m=rnd(c,0x30); e.w32(m+0x20,mat if r.random()<0.8 else 0); e.w32(p+0x14,m)
        return p,res
    returns={}
    n=r.randrange(7)
    keys=sorted(r.getrandbits(32) for _ in range(n))
    for i,key in enumerate(keys):
        p,res=mk(); returns[e.r32(p+8)]=res
        e.w32(s+0x28+8*i,key); e.w32(s+0x2c+8*i,p)
        e.wbytes(p+0x12,struct.pack('<H',r.choice([i,r.randrange(65536)])))
    e.w32(s+0x20,n)
    qn=r.randrange(5); e.w32(queue,qn)
    for i in range(qn):
        p,res=mk(r.choice([0,1,3,9])); returns[e.r32(p+8)]=res; e.w32(queue+4+4*i,p)
    def resolve(em,_):
        p=em.reg('ecx'); em.calllog.append(('resolve',p)); em.ret(eax=returns[p],argbytes=0)
    e.hook(0x659000,resolve)
    hook_rec(c,0x6496e0,1,pop=4,ret=lambda em,k:r.randrange(16))
    def sort(em,_):
        a,num,sz,cmp=map(em.arg32,range(4))
        vals=[(em.r32(a+8*i),em.r32(a+8*i+4)) for i in range(num)]
        em.calllog.append(('qsort',num,sz,cmp,tuple(vals)))
        for i,(key,p) in enumerate(sorted(vals,key=lambda pair:pair[0])):
            em.w32(a+8*i,key); em.w32(a+8*i+4,p)
        em.ret(eax=0,argbytes=0)
    e.w32(0x676450,e.stub_fn('qsort',sort))
    # Assertion is installed even though these bounded lists never exceed 8192.
    e.w32(0x7003b0,e.stub_fn('assert',lambda em,_:(em.calllog.append(('assert',)),em.ret(eax=0,argbytes=0))))
    return [s]
S(0x64ead0,'GUESS compact and merge render entries','thiscall',None,ret=None,gen=gen,note='batch38101')
