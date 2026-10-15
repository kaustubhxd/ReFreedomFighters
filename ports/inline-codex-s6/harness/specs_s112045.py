from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,reftab

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 id=r.getrandbits(32);elems=[r.choice([id,r.getrandbits(32)]) for _ in range(r.randrange(0,6))];lst=reftab(c,elems);me=obj(c,0x1e0,{0x84:pystub(c,1,this=True),0x94:pystub(c,2,this=True),0x8c:pystub(c,1,this=True)});e.w32(me+0x4c,e.r32(lst))
 for off in (0x1b9,0x1ba):e.wbytes(me+off,bytes([r.randrange(2)]))
 e.w32(me+0x1cf,r.choice([0,1,2]));e.w32(me+0x1cb,r.randrange(2));value=r.getrandbits(32);so=sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=value)},table_size=0xae0);e.w32(e.r32(so+0x9b)+0xadc,r.choice([value,r.getrandbits(32)]));return [me,id]
S(0x4bef70,'GUESS notify_membership_transition','thiscall',None,ret=None,gen=gen)
