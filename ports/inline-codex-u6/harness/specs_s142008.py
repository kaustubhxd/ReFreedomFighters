import struct
from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,logger

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 def fp(n):return struct.pack('<'+'f'*n,*[r.uniform(-1000,1000) for _ in range(n)])
 values=[fp(3),fp(3)];matrix=fp(9);objects=[]
 for val in values:
  def side(em,k,val=val):em.wbytes(em.arg32(0),matrix);em.wbytes(em.arg32(1),val)
  objects.append(obj(c,16,{0x80:pystub(c,2,this=True,stackmark=(0,1),side=side)}))
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:objects[k])})
 vs=[rnd(c,8) for _ in range(3)];e.wbytes(vs[2]+4,bytes([r.choice([0,1,2,3,255])]))
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:vs[k]);hook_rec(c,0x5002f0,1,this=True)
 logger(c,3);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 args=rnd(c,12);e.w32(args+4,rnd(c,16));e.w32(args+8,rnd(c,16))
 return [rnd(c,16),args]
S(0x510d40,'GUESS script object distance','thiscall',None,ret=None,gen=gen)
