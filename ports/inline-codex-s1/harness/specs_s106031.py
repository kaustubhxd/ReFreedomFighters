from pilot import S,EDGE_F
from recruits_util import rnd,obj,logger,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 text=e.cstr('sample');source=rnd(c,8);tag=r.choice([3,4,0,2,0xff]);e.wbytes(source+4,bytes([tag]))
 objp=obj(c,16,{0x34:pystub(c,0,this=True,ret=text)})
 e.w32(source,objp if tag==4 else text)
 output=rnd(c,8);e.wbytes(output+4,bytes([r.choice([0,2,1,4,0xff])]))
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:[source,output][k%2])
 hook_rec(c,0x589c40,2,this=True,st0=r.choice(EDGE_F+[r.uniform(-100,100)]),side=lambda em,k:em.calllog.append(('lookup-args',em.reg('ecx'),em.arg32(0),em.arg32(1))))
 e.w32(0x7003b8,rnd(c,16));logger(c,nargs=3);e.w32(0x7003b0,pystub(c,0))
 event=rnd(c,16);e.w32(event+4,rnd(c,16));e.w32(event+8,rnd(c,16))
 return [event]
S(0x559dc0,'resolve scalar and update tagged output','stdcall',None,ret=None,gen=gen,nan_heap=True)
