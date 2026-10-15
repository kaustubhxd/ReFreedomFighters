from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec,logger,reftab

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));logger(c,3)
 a=rnd(c,8);b=rnd(c,8);e.wbytes(a+4,bytes([r.choice([0,1,2,3,4,255])]));e.wbytes(b+4,bytes([r.choice([0,1,2,255])]))
 e.w32(a,obj(c,32,{0x34:pystub(c,0,this=True,ret=r.getrandbits(32))}))
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:[a,b][k])
 sysobj(c,table_slots={0x114:pystub(c,4,this=True,ret=r.getrandbits(32))})
 elems=[r.getrandbits(32) for _ in range(r.randrange(0,6))];lst=reftab(c,elems)
 owner=obj(c,32,{0x12c:pystub(c,3,this=True)});e.w32(owner+24,lst if r.randrange(4) else 0)
 me=rnd(c,32);e.w32(me+12,owner)
 return [me,rnd(c,16)]
S(0x509d10,'GUESS broadcast_named_property','thiscall',None,ret=None,gen=gen)
