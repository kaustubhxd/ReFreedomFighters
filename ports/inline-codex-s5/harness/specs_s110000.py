from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub,_HOOKED

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 n=r.randrange(2,8);items=rnd(c,n*36); cnt=rnd(c,4);e.w32(cnt,n)
 mgr=obj(c,0x20,{0xfc:pystub(c,1,ret=items,this=True),0x100:pystub(c,1,ret=cnt,this=True)})
 a=rnd(c,0x30);e.w32(a+0x18,mgr);g=rnd(c,0x1ab0);e.w32(g+0x1aa3,a);e.w32(0x70039c,g)
 t=rnd(c,0x20);sub=rnd(c,0x80);e.w32(t+8,sub);p=rnd(c,0x10)
 hook_rec(c,0x7003b0,0)
 e.w32(0x7003b0,e.stub_fn('assert',lambda em,_:(em.calllog.append(('assert',)),em.ret())))
 distances=[r.choice([-10.,-2.,0.,1.,10.,1e30]) for _ in range(n*3)]
 # use named register constants
 from unicorn.x86_const import UC_X86_REG_ECX,UC_X86_REG_EDX
 def distance(em,_):
  x=em.mu.reg_read(UC_X86_REG_ECX);y=em.mu.reg_read(UC_X86_REG_EDX)
  em.calllog.append(('distance',x,y));em.ret(st0=distances[(x-items)//12])
 e.hook(0x4e0830,distance);_HOOKED.add(0x4e0830)
 hook_rec(c,0x460100,5,this='mark',pop=20)
 hook_rec(c,0x4602b0,4,this='mark',pop=16,nullflag=(2,),st0=0.25)
 return [t,p,r.choice([0,0,items+36*r.randrange(n),items+4])]
S(0x44b140,'GUESS nearest spline segment','thiscall',None,ret='st0',gen=gen)
