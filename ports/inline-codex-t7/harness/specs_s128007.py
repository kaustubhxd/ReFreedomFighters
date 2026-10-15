from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 me=rnd(c,0x440);values=[r.getrandbits(32) for _ in range(39)]
 def slot(n,ret=0,**kw):return pystub(c,n,this=True,ret=ret,**kw)
 def widgetcall(em,k):em.calllog.append(('child',em.reg('ecx'),em.arg32(0),em.arg32(1)))
 widget=obj(c,32,{0x25c:slot(2,ret=lambda em,k:values[min(k,38)],side=widgetcall)})
 ref=r.getrandbits(32)
 def getref(em,k):em.calllog.append(('getref',em.arg32(0),em.r32(em.arg32(1))));em.w32(em.arg32(1),ref)
 res=obj(c,32,{0x60:slot(2),0x88:slot(2,stackmark=(1,),side=getref)})
 sysobj(c,table_slots={0x138:slot(0,res),0x4c:slot(2,r.getrandbits(32)),0x58:slot(1,widget)})
 init=r.getrandbits(32)
 hook_rec(c,0x562440,0,this=True,side=lambda em,k:em.w32(me+0x44,init))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x568900,'GUESS initialize UI widget handles','thiscall',None,ret='eax',gen=g,note='batch128007')
