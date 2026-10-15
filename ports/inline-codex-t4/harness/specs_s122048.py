from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 s=rnd(c,0x80);rec=e.alloc(16*4,4)
 def save(em,k):em.w32(rec+4*k,em.arg32(0))
 stream=obj(c,0x20,{0x10:pystub(c,2,this=True,deref={0:27}),0x24:pystub(c,1,this=True),0x3c:pystub(c,1,this=True,side=save),0x44:pystub(c,1,this=True),0x4c:pystub(c,1,this=True)})
 entries=[rnd(c,12) for _ in range(r.randrange(6))]
 for p in entries:e.w32(p+8,r.choice([0,r.getrandbits(32)]))
 def begin(em,k):em.wbytes(em.arg32(0),bytes(12))
 list=obj(c,0x20,{0x14:pystub(c,0,this=True,ret=len(entries)),0x4c:pystub(c,1,this=True,stackmark=(0,),side=begin),0x64:pystub(c,1,this=True,deref={0:3},ret=lambda em,k:entries[k] if k<len(entries) else 0),0x9c:pystub(c,1,this=True,st0=r.uniform(-100,100))})
 e.w32(s+0x6c,list if r.randrange(4) else 0);e.w32(s+0x74,obj(c,0x20,{0x314:pystub(c,1,this=True,ret=r.getrandbits(32))}))
 return [s,stream]
S(0x463ff0,'GUESS serialize link record and entries','thiscall',None,ret='al',gen=gen)
