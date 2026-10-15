from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    selfp=rnd(c,0x320)
    e.w32(selfp+0x180,1); e.w32(selfp+0x184,2)
    state=obj(c,0x120,{0x374:pystub(c,2,this=True),0x388:pystub(c,0,this=True,ret=lambda em,k: 1+k%20)})
    e.w32(selfp+0x310,state)
    objs=[]
    for _ in range(2):
        vt={0x1e0:pystub(c,1,this=True,ret=lambda em,k:1),0x2d8:pystub(c,0,this=True,ret=1),0x2dc:pystub(c,0,this=True,ret=0)}
        objs.append(obj(c,0x10,vt))
    sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:objs[em.arg32(0)-1] if em.arg32(0) in (1,2) else 0)})
    return [selfp,r.randrange(0,10)]
S(0x57ece0,'GUESS update two related objects','thiscall',None,ret='al',gen=gen,note='batch104015')
