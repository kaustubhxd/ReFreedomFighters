from pilot import S
from recruits_util import rnd, obj, clear_hooks

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    def setvec(em, _):
        p=em.arg32(0); vals=[r.uniform(-2,2) for _ in range(3)]
        em.calllog.append(('slot84',tuple(vals)))
        for i,x in enumerate(vals): em.wf32(p+4*i,x)
        em.ret(argbytes=4)
    def gettm(em, _):
        p=em.arg32(0); q=em.arg32(1)
        vals=[r.uniform(-1,1) for _ in range(9)]
        em.calllog.append(('slot80',tuple(vals)))
        for i,x in enumerate(vals): em.wf32(p+4*i,x)
        em.ret(argbytes=8)
    selfp=obj(c,0x100,{0x84:e.stub_fn('slot84',setvec),0x80:e.stub_fn('slot80',gettm)},nslots=0x24)
    v=obj(c,0x50,{})
    for i in range(3): e.wf32(v+0x30+4*i,r.uniform(-1,1))
    e.w32(selfp+8,v)
    arg=rnd(c,12)
    e.wf32(arg,r.choice([-1.0,-0.5,0.5,1.0]))
    e.wf32(arg+4,r.uniform(-2,2)); e.wf32(arg+8,r.choice([-1.0,-0.5,0.5,1.0]))
    return [selfp,arg]
S(0x45eb30,'GUESS signed angle from transformed direction','thiscall',None,ret='st0',gen=gen,note='batch65006')
