from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 lo=obj(c,32,{0x2c:pystub(c,2,pop=0),0x30:pystub(c,3,pop=0)});lg=obj(c,32,{0x20:pystub(c,2,this=True,ret=lo)});e.w32(0x700390,lg)
 count=r.randrange(0,7);values=[r.getrandbits(32) for _ in range(max(count,1))]
 lst=obj(c,32,{0x14:pystub(c,0,this=True,ret=count),0x30:pystub(c,1,this=True,ret=lambda em,k:values[(em.arg32(0) if em.arg32(0)<0x80000000 else em.arg32(0)-0x100000000)%max(count,1)])})
 owner=rnd(c,32);e.w32(owner+24,lst);e.w32(owner+4,r.choice([0,rnd(c,32)]));me=rnd(c,32);e.w32(me+12,owner if r.randrange(4) else 0)
 sysobj(c,{0x1bc:pystub(c,2,this=True,ret=r.choice([0,1,0xffffffff,0x80000000,r.getrandbits(32)]))})
 inp=rnd(c,8);e.w32(inp,r.choice(values));out=rnd(c,8);inputtab=rnd(c,16);outputtab=rnd(c,16);args=rnd(c,16);e.w32(args+4,inputtab);e.w32(args+8,outputtab)
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:inp if em.reg('ecx')==inputtab else out);hook_rec(c,0x5002f0,1,this=True,side=lambda em,k:em.w32(em.reg('ecx'),em.arg32(0)))
 return [me,args]
S(0x509970,'GUESS choose_random_alternate','thiscall',None,ret=None,gen=gen)
