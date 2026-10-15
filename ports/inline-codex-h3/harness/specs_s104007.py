from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,sysobj,hook_rec

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    frame=r.choice([0,50,100,250,500,1000]); rand=r.choice([0.0,0.01,0.2,0.5,0.9,1.0])
    sys=sysobj(c,rand=rand); e.w32(sys+0x40,frame)
    def emit(em,k):
        p=em.arg32(0); vals=[r.getrandbits(32) for _ in range(3)]
        for i,v in enumerate(vals): em.w32(p+4*i,v)
    child=obj(c,0x20,{0x84:pystub(c,1,this=True,deref={0:3},side=emit)})
    result=rnd(c,0x30); handles=[r.getrandbits(32),r.getrandbits(32)]
    def setvec(em,k):
        p=em.arg32(1)
        for i in range(3): em.wf32(p+4*i,[0.25,-0.5,1.25][i]+k)
    modes=obj(c,0x20,{0x3b4:pystub(c,0,this=True,ret=handles[0]),0x3b8:pystub(c,0,this=True,ret=handles[1]),0x398:pystub(c,2,this=True,side=setvec)})
    me=rnd(c,0x40); e.w32(me+4,child); e.w32(me+8,0 if r.random()<0.2 else modes)
    e.wf32(me+0x14,r.choice([-1.0,0.0,0.25,1.0,5.0,20.0]))
    for off in (0x18,0x1c,0x20,0x24,0x28,0x2c): e.w32(me+off,r.getrandbits(32))
    out=rnd(c,0xc)
    return [me,out]
S(0x512ca0,'GUESS gate vector update and emit state','thiscall',None,ret=None,gen=gen,note='batch104007')
