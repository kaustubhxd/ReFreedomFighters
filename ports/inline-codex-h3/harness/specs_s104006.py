from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,sysobj,hook_rec

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    vals=[r.choice([0,0,1,2,5,80,101,0xffffffff]),r.choice([0,1,20,100,150,0xffffffff])]
    def read_setting(em,k):
        if k<len(vals): em.w32(em.arg32(1),vals[k])
    cfg=obj(c,0x20,{0x88:pystub(c,2,this=True,stackmark=(1,),side=read_setting)})
    table_slots={0x134:pystub(c,0,this=True,ret=cfg)}
    level=obj(c,0x20,{0x7c:pystub(c,0,this=True,ret=r.choice([-5,0,32,100,140])),0x80:pystub(c,1,this=True),})
    actor=obj(c,0x220,{0xdc:pystub(c,0,this=True,ret=r.choice([0,1,25,100,255])),0xd8:pystub(c,1,this=True),0x134:pystub(c,3,this=True),0x138:pystub(c,2,this=True),0x50:pystub(c,0,this=True)})
    log=0 if r.random()<0.3 else obj(c,0x20,{0xc:pystub(c,3,this=True)})
    sys=sysobj(c,slots={0x1cc:pystub(c,1,this=True,ret=r.randrange(0,1000)),0xbc:pystub(c,0,this=True,ret=level)},table_slots=table_slots)
    e.w32(sys+0x40,0x20020000); e.w32(sys+0x1907,log); e.w32(sys+0x190f,actor)
    me=obj(c,0x1f00,{0x1fc:pystub(c,3,this=True)}); e.w32(me+0x1c8,r.getrandbits(32))
    return [me]
S(0x5d78e0,'GUESS refresh global timing and actor state','thiscall',None,ret=None,gen=gen,note='batch104006')
