from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 position=bytes(r.getrandbits(8) for _ in range(12));hook_rec(c,0x4daf90,1,this=True,stackmark=(0,),side=lambda em,k:em.wbytes(em.arg32(0),position));hook_rec(c,0x5bda50,2,this=True)
 found=obj(c,32,{0x84:pystub(c,1,this=True,deref={0:3})});e.w32(found+8,rnd(c,32))
 parent=obj(c,32,{0x8c:pystub(c,1,this=True,deref={0:3}),0x180:pystub(c,2,this=True,deref={0:3},ret=r.randrange(2))})
 index=r.choice([-31,-1,0,1,31,32,63,255,319])
 provider=obj(c,32,{0x8c:pystub(c,2,this=True,ret=found if r.randrange(4) else 0,side=lambda em,k:em.w32(em.arg32(0),index&0xffffffff))})
 me=rnd(c,0xa0);e.w32(me+0x44,parent);e.w32(me+0x81,provider);e.wbytes(me+0x75,r.choice([0,r.randrange(65536)]).to_bytes(2,'little'));e.wbytes(me+0x77,r.choice([0,r.randrange(65536)]).to_bytes(2,'little'));return [me]
S(0x5bd7b0,'GUESS update_inside_type_bits','thiscall',None,ret=None,gen=gen)
