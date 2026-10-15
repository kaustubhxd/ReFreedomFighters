from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def base(c):
 clear_hooks(c)
 c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))
 c.emu.hook(0x633654,lambda e,r:e.ret(eax=e.reg('eax'),argbytes=0))

def gac30(c):
 base(c);e=c.emu;r=c.rng
 mask=r.choice(list(range(16))+[16,0x80000000,r.getrandbits(32)])
 manager=obj(c,0x20,{0x4c:pystub(c,0,ret=mask,this=True)})
 e.w32(0x7003a0,manager)
 items={}
 me=obj(c,0x1c0,{0xd0:pystub(c,1,this=True)})
 for i in range(4):
  ident=r.getrandbits(32);e.w32(me+0x19c+4*i,ident)
  items[ident]=obj(c,0x20,{0x2d8:pystub(c,0,this=True),0x2dc:pystub(c,0,this=True)})
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:items[em.arg32(0)])})
 return [me]

def gef50(c):
 base(c);e=c.emu;r=c.rng
 me=rnd(c,0x600)
 oldlen=r.randrange(40);newlen=r.randrange(40)
 if r.randrange(3)==0:newlen=max(0,32-oldlen+r.choice([-1,0,1]))
 old=bytes(r.choice(b'abc XYZ') for _ in range(oldlen))
 text=bytes(r.choice(b'abc XYZ') for _ in range(newlen))
 e.wbytes(me+0x1c9,old+b'\0')
 p=rnd(c,0x80);e.wbytes(p,text+b'\0')
 e.w32(me+0x4b2,r.randrange(16))
 def display(em,k):
  p=em.arg32(0);out=[]
  while em.r8(p):out.append(em.r8(p));p+=1
  em.calllog.append(('display_text',bytes(out)))
 e.w32(me+0x5ce,obj(c,0x20,{0x284:pystub(c,1,this=True,side=display)}))
 e.w32(me+0x5ca,obj(c,0x20,{0x248:pystub(c,1,this=True)}))
 e.w32(me+0x5da,obj(c,0x20,{0xbc:pystub(c,1,this=True)}))
 hook_rec(c,0x56fb10,0,this=True)
 return [me,p]
S(0x56ac30,'GUESS dispatch four controls using manager mask','thiscall',None,ret=None,gen=gac30)
S(0x56ef50,'GUESS append input text with length and space guards','thiscall',None,ret=None,gen=gef50)
