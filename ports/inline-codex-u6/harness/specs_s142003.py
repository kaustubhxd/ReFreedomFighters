import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub,logger

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 vals=[rnd(c,8) for i in range(3)]; target=r.choice([0,1,100,r.getrandbits(32)]);current=r.choice([0,target,200,r.getrandbits(32)])
 e.w32(vals[0],target);e.wbytes(vals[0]+4,bytes([r.choice([0,1,2,255])]))
 def get(em,k):return vals[min(k,2)]
 hook_rec(c,0x5003d0,1,this=True,ret=get)
 hook_rec(c,0x5002f0,1,this=True)
 logger(c,3);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 owner=obj(c,16,{0x4c8:pystub(c,1,this=True,stackmark=(0,),side=lambda em,k:em.w32(em.arg32(0),current)),0x4b4:pystub(c,5,this=True),0x4ac:pystub(c,7,this=True,deref={1:3}),0x724:pystub(c,0,this=True)})
 me=rnd(c,0x40);e.w32(me+0x1c,owner);args=rnd(c,12)
 for off in [4,8]:e.w32(args+off,rnd(c,16))
 return [me,args]
S(0x557fa0,'GUESS apply script target and blend','thiscall',None,ret=None,gen=gen)
