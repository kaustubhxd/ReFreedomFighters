import struct
from pilot import S,EDGE_F
from recruits_util import rnd,obj,sysobj,logger,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 matrices=[bytes(r.getrandbits(8) for _ in range(36)) for _ in range(2)];position=bytes(r.getrandbits(8) for _ in range(12))
 def fill(em,k,i):em.wbytes(em.arg32(0),matrices[i]);em.wbytes(em.arg32(1),position)
 actor=obj(c,16,{0x80:pystub(c,2,this=True,nullflag=(0,1),side=lambda em,k:fill(em,k,0))})
 me=rnd(c,0x20);e.w32(me+0xc,actor)
 source=rnd(c,8);out=rnd(c,8);e.w32(source,r.choice([0,r.getrandbits(32)]));e.wbytes(source+4,bytes([r.choice([0,1,2,4])]))
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:[source,out][k%2])
 angles=[r.choice(EDGE_F+[r.uniform(-10,10)]) for _ in range(2)]
 hook_rec(c,0x4dda90,2,st0=lambda em,k:angles[k%2],side=lambda em,k:em.calllog.append(('angle-args',em.arg32(0),em.arg32(1))))
 hook_rec(c,0x4db6c0,2,this=True,nullflag=(0,1),side=lambda em,k:fill(em,k,1))
 sysobj(c,table_slots={0x54:pystub(c,1,this=True,ret=rnd(c,16))})
 e.w32(0x700f74,r.getrandbits(32))
 hook_rec(c,0x500360,1,this=True,ret=r.getrandbits(32),side=lambda em,k:em.calllog.append(('angle-global',em.r32(0x700f74))))
 hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('eax'));logger(c,nargs=3);e.w32(0x7003b0,pystub(c,0))
 event=rnd(c,16);e.w32(event+4,rnd(c,16));e.w32(event+8,rnd(c,16))
 return [me,event]
S(0x500ee0,'write wrapped orientation difference','thiscall',None,ret='eax',gen=gen,nan_heap=True)
