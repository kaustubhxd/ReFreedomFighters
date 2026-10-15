from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));me=rnd(c,0x22010);n=r.randrange(1,7);threshold=r.randrange(n);levels=[]
 for i in range(n):
  p=rnd(c,24);size=r.randrange(0,33);data=rnd(c,40);e.w32(p,size);e.w32(p+4,r.choice([4,8,16,32]) if i<=threshold else r.choice([1,2,8]));e.w32(p+8,r.choice([4,8,16,32]) if i<=threshold else r.choice([1,2,8]));e.w32(p+16,data);levels.append(p)
 source=obj(c,32,{8:pystub(c,0,this=True,ret=r.choice([0x44585431,0x44585433,0])),0x34:pystub(c,0,this=True,ret=n),0x38:pystub(c,1,this=True,ret=lambda em,k:levels[em.arg32(0)])})
 dest=rnd(c,64)
 def lock(em,k):em.w32(em.arg32(2),0);em.w32(em.arg32(2)+4,dest)
 out=obj(c,32,{0x40:pystub(c,5,stackmark=(2,),side=lock),0x44:pystub(c,2)})
 factory=obj(c,32,{0x50:pystub(c,8,stackmark=(7,),side=lambda em,k:em.w32(em.arg32(7),out))});e.w32(me+0x22004,factory)
 so=sysobj(c);e.w32(so+0x93,r.randrange(n+4))
 def copy(em,k):em.wbytes(em.arg32(0),em.rbytes(em.arg32(1),em.arg32(2)))
 hook_rec(c,0x634d22,3,pop=0,side=copy)
 return [me,source]
S(0x612900,'GUESS create_compressed_texture','thiscall',None,ret='eax',gen=gen)
