from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub,sysobj

def g(c):
    clear_hooks(c)
    r,e=c.rng,c.emu
    def slot(n,ret=0,**kw):return pystub(c,n,this=True,ret=ret,**kw)
    # Mixed arity cdecl diagnostic printer; first argument is the logger object.
    def pr(em,_):
        n=3 if em.arg32(1)==0x69c6b0 else 2
        em.calllog.append(('print',tuple(em.arg32(i) for i in range(n))))
        em.ret(0,0)
    log=obj(c,0x20,{0x2c:e.stub_fn('print',pr)})
    lg=obj(c,0x20,{0x20:slot(2,log)})
    e.w32(0x700390,lg)
    asrt=pystub(c,0,ret=r.getrandbits(32))
    e.w32(0x7003b0,asrt)
    nameobj=obj(c,0x20,{0x34:slot(0,r.getrandbits(32))})
    types=[r.choice([3,3,4,4,0,1,5])]+[r.choice([0,0,1,1,2,4]) for _ in range(3)]
    vals=[nameobj if types[0]==4 else r.getrandbits(32),r.choice([0,101,101]),102,r.getrandbits(32)]
    av=[]
    for t,v in zip(types,vals):
        a=rnd(c,8);e.w32(a,v);e.wbytes(a+4,bytes([t]));av.append(a)
    hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:av[em.arg32(0)])
    arg=rnd(c,0x10);e.w32(arg+4,rnd(c,0x20))
    dest_mode=r.randrange(4);src_mode=r.randrange(3)
    ns=r.choice([0,1,3,5,0xffffffff]);nd=r.choice([0,1,2,5,0xffffffff])
    sl=obj(c,0x20,{0x14:slot(0,ns),0x30:slot(1,ret=lambda em,k:200+em.arg32(0))})
    dl=obj(c,0x20,{0x14:slot(0,nd),0x30:slot(1,ret=lambda em,k:300+em.arg32(0))})
    def typ(mode):
        def f(em,k):
            a=em.arg32(0)
            return (1 if (a==0x800001a and mode==0) or (a==0x100001 and mode==1) or (a==0 and mode==2) else rzero)
        return f
    rzero=r.choice([0,0x100])
    source=obj(c,0x40,{0x1e0:slot(1,typ(src_mode))});e.w32(source+0x18,sl)
    target=obj(c,0x20,{0x128:slot(3,deref={1:2})})
    nodes=[rnd(c,0x60) for _ in range(r.randrange(5))]
    for node in nodes:e.w32(node+0x54,r.choice([0,target,target]))
    def nxt(em,k):
        ptr=em.arg32(0);old=em.r32(ptr)
        ix=nodes.index(old)+1
        em.w32(ptr,nodes[ix] if ix<len(nodes) else 0)
    dest=obj(c,0x40,{0x1e0:slot(1,typ(dest_mode)),0x50:slot(1,stackmark=(0,),side=nxt)})
    e.w32(dest+0x18,dl);e.w32(dest+8,nodes[0] if nodes else 0)
    valid={node:r.choice([0,1,1,0x100]) for node in nodes}
    hook_rec(c,0x4db9a0,1,this=True,ret=lambda em,k:valid[em.reg('ecx')])
    sysobj(c,table_slots={0x58:slot(1,ret=lambda em,k:dest if em.arg32(0)==101 else source if em.arg32(0)==102 else target),0x114:slot(4,r.getrandbits(32))})
    return [arg]
S(0x556a80,'GUESS dispatch paired script arguments','stdcall',None,ret=None,gen=g,note='batch46008')
