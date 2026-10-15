from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub
import struct

def g4bf520(c):
    clear_hooks(c); e=c.emu; r=c.rng
    count=r.randrange(1,5); base=r.randrange(0,5)
    values={}
    for i in range(count+base):
        ident=0x300+i
        if r.randrange(4):
            item=rnd(c,0x30)
            e.w32(item+0x20,struct.unpack('<I',struct.pack('<f',r.uniform(0.25,5)))[0])
            values[ident]=item
        else: values[ident]=0
    def get_id(em,k): return 0x300+em.arg32(0)
    index_obj=obj(c,0x40,{0x30:pystub(c,1,this=True,ret=get_id)})
    lookup=pystub(c,1,this=True,ret=lambda em,k:values.get(em.arg32(0),0))
    sysobj(c,table_slots={0x58:lookup})
    me=rnd(c,0xa0); e.w32(me+0x6d,index_obj)
    e.w32(me+0x69,r.randrange(0,5)); e.w32(me+0x75,0)
    e.w32(me+0x79,struct.unpack('<I',struct.pack('<f',r.uniform(0.4,3)))[0])
    e.w32(me+0x85,r.randrange(0,5)); e.w32(me+0x8d,r.randrange(1,12))
    e.w32(me+0x91,count-1); e.w32(me+0x95,0)
    for off in (0x7d,0x81,0x99):e.w32(me+off,0)
    hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('ecx'))
    hook_rec(c,0x7003b0,0,ret=lambda em,k:em.rng.getrandbits(32))
    return [me,r.getrandbits(32)]

S(0x4bf520,'GUESS advance resource progress and timing','thiscall',None,ret=None,gen=g4bf520,note='batch100011')
