from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub
import struct

def g4a9250(c):
    clear_hooks(c);e=c.emu;r=c.rng
    target=obj(c,0x40,{0x44:pystub(c,1,this=True),0x60:pystub(c,1,this=True),
                       0x4c:pystub(c,1,this=True),0x68:pystub(c,1,this=True,deref={0:3}),
                       0x3c:pystub(c,1,this=True)})
    me=rnd(c,0x110);e.w32(me+4,r.getrandbits(32))
    for off in (0x4a,0x5b,0x5f,0x75,0xbb,0xbf,0xc3,0xc9,0xd2,0x52):e.w32(me+off,r.getrandbits(32))
    for off in (0x5a,0xd1):e.w8(me+off,r.randrange(256))
    e.w32(me+0x63,struct.unpack('<I',struct.pack('<f',r.uniform(-10,10)))[0])
    for base in (0x7d,0x8b,0x97):
        for j in range(3):e.w32(me+base+4*j,r.getrandbits(32))
    hook_rec(c,0x7003b0,0,ret=lambda em,k:em.rng.getrandbits(32))
    return [me,target]

S(0x4a9250,'GUESS serialize resource profile fields','thiscall',None,ret='al',gen=g4a9250,note='batch100017')
