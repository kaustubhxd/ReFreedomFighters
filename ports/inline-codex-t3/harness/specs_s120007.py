from pilot import S
from recruits_util import rnd,clear_hooks,pystub,obj

def draw(c):
    clear_hooks(c);e,r=c.emu,c.rng
    e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
    self=rnd(c,0x30);prim=rnd(c,0x50);e.w32(self+8,prim)
    m=rnd(c,36)
    for addr,n in ((self+0x18,3),(prim+0x30,3),(m,9)):
        for i in range(n):e.wf32(addr+4*i,r.choice([0.0,-0.0,1.0,-1.0,r.uniform(-100,100)]))
    buf=obj(c,0x40,{0x30:pystub(c,4,this=True,deref={1:12})})
    return [self,buf,rnd(c,0x20),m,rnd(c,16)]
S(0x45a720,'ZPICOBJ::Draw','thiscall',None,ret=None,gen=draw)
