"""Reconcile object links. Real pointer sorting in hook; scripted relation queries.
Array/stack query buffers logged by contents, not addresses. Hooked callees' internals excluded.
"""
from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec

def gen(c):
    clear_hooks(c); e,r=c.emu,c.rng
    pool=[rnd(c,0x80) for _ in range(8)]
    for p in pool: e.w32(p+0x68,r.randrange(20))
    target=r.choice(pool)
    n=r.randrange(6); lo=r.randrange(3); count=r.randrange(5)
    arrays=[rnd(c,0x50) for _ in range(3)]
    for a in arrays:
        for i in range(20): e.w32(a+4*i,r.choice(pool))
    s=rnd(c,0x50)
    for off,a in zip([0x35,0x39,0x3d],arrays): e.w32(s+off,a)
    def sort(em,_):
        a=em.reg('ecx'); low=em.reg('edx'); high=em.arg32(0)
        em.calllog.append(('sort',a,low,high))
        vals=sorted(em.r32(a+4*i) for i in range(low,high+1))
        for i,x in enumerate(vals,low): em.w32(a+4*i,x)
        em.ret(eax=0,argbytes=4)
    e.hook(0x4e6a80,sort)
    hook_rec(c,0x49c980,2,this=True,pop=8,ret=(count<<16)|lo)
    def copy(em,_):
        dest=em.reg('ecx'); low=em.arg32(0); src=em.arg32(1); num=em.arg32(2)
        em.calllog.append(('copy',dest,low,src,num))
        em.wbytes(dest+4*low,em.rbytes(src,4*num)); em.ret(eax=0,argbytes=12)
    e.hook(0x49c6d0,copy)
    hook_rec(c,0x49cbb0,3,this=True,pop=12,ret=lambda em,k:r.choice([0,1,2,3]))
    hook_rec(c,0x49ccc0,3,this=True,pop=12,ret=0)
    def query(em,_):
        key,a,num=em.arg32(0),em.arg32(1),em.arg32(2)
        vals=tuple(em.r32(a+4*i) for i in range(num))
        em.calllog.append(('query',em.reg('ecx'),key,num,vals))
        got=r.choice([0,num,num,num+1])
        em.ret(eax=got,argbytes=12)
    e.hook(0x49c310,query)
    def log(em,_):
        em.calllog.append(('log',em.arg32(0),em.arg32(1))); em.ret(eax=0,argbytes=0)
    logobj=obj(c,0x20,{0x30:e.stub_fn('log',log)})
    def lg(em,_):
        em.calllog.append(('logger',em.arg32(0),em.arg32(1))); em.ret(eax=logobj,argbytes=8)
    logger=obj(c,0x20,{0x20:e.stub_fn('logger',lg)}); e.w32(0x700390,logger)
    return [s,n,target]
S(0x49b730,'GUESS reconcile object links','thiscall',None,ret=None,gen=gen,note='batch38100')
