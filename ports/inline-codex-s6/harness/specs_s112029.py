from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));hook_rec(c,0x63da80,1,this=True);hook_rec(c,0x658f50,0,this=True,ret=lambda em,k:values[min(k,len(values)-1)]);hook_rec(c,0x658d30,0,this=True,ret=r.randrange(2))
 me=obj(c,0x181d0,{0x48:pystub(c,1,this=True)});mgr=obj(c,32,{0xa0:pystub(c,1,this=True)});e.w32(me+0x1005d,mgr)
 for off in (0x10171,0x10199,0x101ad):
  o=obj(c,32,{8:pystub(c,1,this=True,deref={0:1})});e.w32(me+off,e.r32(o))
 tab=rnd(c,0x4000);e.w32(me+0x10071,tab);queue=rnd(c,0x9000);e.w32(queue,r.choice([0,1,0x1ffe,0x2000]));e.w32(me+0x181c5,queue if r.randrange(3) else 0)
 tail=0;values=[r.randrange(4) for _ in range(8)]
 for i in range(r.randrange(0,6)):
  slot=i+r.choice([0,0x800]);record=rnd(c,32);e.w32(record+12,r.choice([0,1,0xffffffff]));e.w32(tab+4*slot,record)
  idx=rnd(c,16);e.wbytes(idx+6,(slot | (r.randrange(16)<<12)).to_bytes(2,'little'));meta=rnd(c,32);e.w32(meta+8,idx);e.wbytes(meta+12,r.choice([0,1,65535]).to_bytes(2,'little'))
  data=rnd(c,0x50);e.wbytes(data+9,bytes([r.choice([0,1,255])]));e.w32(data+0x10,meta if r.randrange(4) else 0)
  res=rnd(c,32);e.w32(res+8,data);e.w32(res+0x1c,tail);tail=res
 main=rnd(c,32);data=rnd(c,0x50);e.w32(main+8,data);e.w32(main+0x1c,tail);e.w32(main+12,r.randrange(2));return [me,main]
S(0x64c090,'GUESS retain_resource_chain','thiscall',None,ret=None,gen=gen)
