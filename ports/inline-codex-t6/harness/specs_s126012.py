from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0xa40);data=rnd(c,12);so=sysobj(c,table_size=0xb00)
 # Engine table link is unaligned.
 def textside(em,k):em.w32(data,0x12345678);em.w32(data+4,0x87654321)
 table=e.r32(so+0x9b);text=obj(c,0x20,{0:pystub(c,2,this=True,ret=r.getrandbits(32),side=textside)});e.w32(table+0xae4,text)
 e.w32(me+0xa17,rnd(c,0x20))
 keys=r.sample(range(65536),5)
 for off,key in zip([0x184,0x186,0x188,0x18a,0x196],keys):e.wbytes(me+off,key.to_bytes(2,'little'))
 for off in [0xa0a,0xa0b,0xa0d]:e.wbytes(me+off,bytes([r.randrange(2)]))
 hook_rec(c,0x59a5b0,3,this=True);hook_rec(c,0x566820,0,this=True);hook_rec(c,0x566a10,0,this=True);hook_rec(c,0x4f1520,2,this=True)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,r.choice(keys+[r.randrange(65536)])|(r.randrange(65536)<<16),data]
S(0x565f20,'GUESS briefing command dispatch','thiscall',None,ret='eax',gen=gen)
