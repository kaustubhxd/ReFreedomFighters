from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    timer1=obj(c,0x90,{}); timer2=obj(c,0x90,{})
    e.w32(timer1+0x60,r.getrandbits(32)); e.w32(timer1+0x64,r.getrandbits(32))
    e.w32(timer2+0x60,r.getrandbits(32)); e.w32(timer2+0x64,r.getrandbits(32))
    mapping={1:timer1,2:timer2}
    def lookup(em,_):
        key=em.arg32(0); em.calllog.append(('lookup',key)); em.ret(eax=mapping.get(key,0),argbytes=4)
    so=sysobj(c,table_slots={0x60:e.stub_fn('lookup',lookup)})
    e.wf32(so+0x48,r.uniform(0,10))
    selfp=rnd(c,0x220); clock=rnd(c,0x80); e.wf32(clock+0x24,r.uniform(0.1,100))
    e.w32(selfp+0x5c,clock); e.w32(selfp+0x8,rnd(c,0x30))
    e.w32(selfp+0x1d1,r.choice([0,1,2,3])); e.w32(selfp+0x1d9,r.choice([0,1,2,3]))
    e.wf32(selfp+0x1e1,r.uniform(0.1,3)); e.wf32(selfp+0x1e9,r.uniform(0.1,3))
    e.w32(selfp+0x1dd,r.getrandbits(32)); e.w32(selfp+0x1e5,r.getrandbits(32))
    e.w32(selfp+0x1f9,0); e.w32(selfp+0x1f5,0)
    e.wf32(selfp+0x1f1,r.uniform(0.1,1.5))
    vals=[r.getrandbits(32),r.getrandbits(32)]
    hook_rec(c,0x4db3b0,0,this=True,ret=r.choice([0,1,500,1000]))
    hook_rec(c,0x4bb6b0,1,this=True,pop=4,ret=r.choice([0,1]))
    e.w32(selfp+0x1ed,0)
    return [selfp]

S(0x5146c0,'GUESS update timers and animation ratio','thiscall',None,ret=None,gen=gen,note='batch65005')
