from pilot import S
from recruits_util import clear_hooks,rnd,obj,pystub,hook_rec,reftab

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 hook_rec(c,0x4690b0,0,this=True)
 ids=[r.getrandbits(32) for _ in range(r.randrange(5))];lst=rnd(c,0x20);e.w32(lst+0x18,reftab(c,ids))
 box=rnd(c,8);boxmgr=obj(c,0x20,{0xcc:pystub(c,1,this=True,ret=box)});e.w32(0x70038c,boxmgr)
 geom=obj(c,0x900,{0xbc:pystub(c,1,this=True),0x100:pystub(c,1,this=True,ret=r.getrandbits(32))});e.w32(geom+0x85a,r.choice([0,r.getrandbits(32)]))
 world=obj(c,0x20,{0x25c:pystub(c,2,this=True,ret=r.choice([0,lst,lst,lst]))})
 db=obj(c,0xb00,{0x58:pystub(c,1,this=True,ret=lambda em,n:rtn[min(n,len(rtn)-1)])})
 rtn=[r.choice([0,geom]) for _ in range(6)]
 e.w32(db+0xadc,world)
 disp=obj(c,0x20,{0xdc:pystub(c,0,this=True,ret=r.choice([0,1,0x100,0x101]))})
 cl=obj(c,0x90,{0xc:pystub(c,1,this=True)});e.w8(cl+0x83,r.randrange(2))
 sys=obj(c,0x1a00,{0xbc:pystub(c,0,this=True,ret=disp)});e.w32(sys+0x9b,db);e.w32(sys+0x190f,cl);e.w32(0x70039c,sys)
 return [rnd(c,0x800)]
S(0x5cbad0,'ZFFCamera1 Init2','thiscall',None,ret=None,gen=gen)
