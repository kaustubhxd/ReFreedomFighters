from pilot import S
from recruits_util import rnd,obj,pystub,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 a=rnd(c,0x808);b=rnd(c,0x1818)
 hook_rec(c,0x41e290,1,pop=0,ret=lambda em,k:a if k==0 else b)
 values=[r.choice([0.,0.,1.,-1.,r.uniform(-10,10)]) for i in range(768)]
 if c.case%4==0:values[:3]=[0.,0.,0.]
 so=obj(c,0x40,{0x1c0:pystub(c,2,this=True,st0=lambda em,k:values[k])});e.w32(0x70039c,so)
 # Indirect CRT rand is redirected through its IAT, recording call count and output dependence.
 sequence=[r.getrandbits(32) for i in range(256)]
 e.w32(0x67644c,pystub(c,0,ret=lambda em,k:sequence[k]))
 e.wbytes(0x6ff980,bytes([r.randrange(256)]))
 return []
S(0x4513e0,'GUESS initialize duplicated random gradient tables','cdecl',None,ret=None,gen=gen)
