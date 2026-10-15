import struct
from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 pos=[r.uniform(-20,20) for _ in range(3)];src=rnd(c,12);e.wbytes(src,struct.pack('<3f',*pos));targetpos=pos if r.randrange(4)==0 else [r.uniform(-20,20) for _ in range(3)]
 velocity=[r.uniform(-50,50) for _ in range(3)]
 def position(em,k):em.wbytes(em.arg32(0),struct.pack('<3f',*targetpos))
 def speed(em,k):em.wbytes(em.arg32(0),struct.pack('<3f',*velocity))
 target=obj(c,0x30,{0x84:pystub(c,1,this=True,deref={0:3},side=position)})
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=target)})
 hook_rec(c,0x453a50,1,this=True,stackmark=(0,),side=speed)
 hook_rec(c,0x7003b0,0,pop=0,ret=r.getrandbits(32))
 return [src,r.getrandbits(32)]
S(0x53bec0,'GUESS project target velocity toward position','fastcall',None,ret='st0',gen=gen)
