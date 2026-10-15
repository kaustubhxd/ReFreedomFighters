import struct
from pilot import S
from recruits_util import rnd,obj,pystub,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 s=rnd(c,0xc90);text=rnd(c,100);msg=bytes(r.choice([10,10,65,66,13,255]) for _ in range(r.randrange(80)))+b'\0';e.wbytes(text,msg)
 field=obj(c,0xb0,{0xbc:pystub(c,1,this=True),0x284:pystub(c,1,this=True,side=lambda em,k:em.w32(em.reg('ecx')+0x97,text))})
 e.w32(field+0x97,text)
 shape=rnd(c,0x50);ref=obj(c,0x20,{0xbc:pystub(c,1,this=True)});e.w32(ref+8,shape)
 target=obj(c,0x20,{0xbc:pystub(c,1,this=True),0x70:pystub(c,1,this=True,deref={0:3})})
 e.w32(s+0xc62,field);e.w32(s+0xc76,ref);e.w32(s+0xc7a,target)
 vector=struct.pack('<3f',*[r.uniform(-100,100) for _ in range(3)])
 hook_rec(c,0x4db500,1,this=True,stackmark=(0,),side=lambda em,k:em.wbytes(em.arg32(0),vector))
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [s,r.choice([0,text,text,text]),r.choice([0,1,255])|(r.getrandbits(24)<<8),r.choice([0,1,0xffffffff,0x7fffffff,r.getrandbits(32)])]
S(0x565240,'GUESS layoutMessage','thiscall',None,ret=None,gen=gen)
