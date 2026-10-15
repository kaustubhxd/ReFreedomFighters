from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 hook_rec(c,0x5aede0,0,this='mark',side=lambda em,k:em.wbytes(em.reg('ecx'),bytes(96)));hook_rec(c,0x65e090,0,this='mark',side=lambda em,k:em.wbytes(em.reg('ecx'),bytes(12)))
 hook_rec(c,0x5aee60,1,this='mark');hook_rec(c,0x5afbb0,2,this='mark',stackmark=(1,));hook_rec(c,0x5af1d0,1,this=True,ret=lambda em,k:values[k]);values=[r.getrandbits(32) for _ in range(5)]
 hook_rec(c,0x5af990,4,this='mark');hook_rec(c,0x5af8f0,2,this='mark')
 ids=[r.getrandbits(32),r.getrandbits(32)]
 def out(em,k):em.calllog.append(('initial',em.r32(em.arg32(1))));em.w32(em.arg32(1),ids[k])
 svc=obj(c,32,{0x88:pystub(c,2,this=True,stackmark=(1,),side=out)})
 sysobj(c,table_slots={0x138:pystub(c,0,this=True,ret=svc),0x58:pystub(c,1,this=True,ret=r.getrandbits(32))})
 return [rnd(c,0x50),r.getrandbits(32)]
S(0x5b0560,'GUESS apply_inventory_properties','thiscall',None,ret=None,gen=gen)
