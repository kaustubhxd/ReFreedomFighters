from pilot import S
from recruits_util import rnd,clear_hooks,pystub,obj,sysobj,hook_rec

def init(c):
    clear_hooks(c);e,r=c.emu,c.rng
    e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
    self=rnd(c,0x90)
    entity=obj(c,0x90,{0x27c:pystub(c,1,this=True),0x280:pystub(c,1,this=True)})
    child=rnd(c,0x50)
    flag=r.choice([0,0,1,2,255]);devflag=r.choice([0,0,1,2,255])
    def readflag(em,k):em.w8(em.arg32(1),flag)
    opts=obj(c,0x20,{0x90:pystub(c,2,this=True,stackmark=(1,),side=readflag)})
    drop_device=r.random()<0.25
    def after_device(em,k):
        if drop_device:em.w32(sys+0x190f,0)
    device=obj(c,0x100,{0xb8:pystub(c,1,this=True,side=after_device)})
    e.w8(device+0x81,devflag)
    sys=sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=r.choice([0,child])),0x134:pystub(c,0,this=True,ret=opts)})
    e.w32(sys+0x190f,device)
    e.w32(self+0x62,r.choice([0,0,1,r.getrandbits(32)]))
    hook_rec(c,0x5da470,0,this=True,ret=r.choice([0,entity,entity,entity]))
    return [self]
S(0x5da540,'GUESS_screen_entity_setup','thiscall',None,ret=None,gen=init)
