from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 array=rnd(c,16);slots=[rnd(c,8) for _ in range(8)]
 entry=obj(c,0x10,{0x4c:pystub(c,0,this=True,ret=array)})
 table=obj(c,0x10,{0x18:pystub(c,1,this=True,ret=r.choice([0,entry,entry,entry]))})
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:slots[em.arg32(0)%8])
 def assign(em,k):em.w32(em.reg('ecx'),em.arg32(0));em.wbytes(em.reg('ecx')+4,b'\x02')
 def assign_int(em,k):em.w32(em.reg('ecx'),em.arg32(0));em.wbytes(em.reg('ecx')+4,b'\x01')
 hook_rec(c,0x500360,1,this=True,side=assign)
 hook_rec(c,0x5002f0,1,this=True,side=assign_int)
 data=rnd(c,32)
 return [table,r.getrandbits(32),data]
S(0x551240,'GUESS initialize eight-field script record','stdcall',None,ret='eax',gen=gen)
