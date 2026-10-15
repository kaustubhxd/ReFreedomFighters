from pilot import S
from recruits_util import rnd, sysobj, clear_hooks, hook_rec
import struct

def g5772c0(c):
    clear_hooks(c);e=c.emu;r=c.rng
    so=sysobj(c);e.w32(so+0x30,100000)
    me=rnd(c,0x240);e.w8(me+0x20f,1)
    e.w32(me+0x211,struct.unpack('<I',struct.pack('<f',r.uniform(-100,100)))[0])
    hook_rec(c,0x562280,2,this=True,ret=0,stackmark=(0,1))
    hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('ecx'))
    hook_rec(c,0x7003b0,0,ret=lambda em,k:em.rng.getrandbits(32))
    return [me]

S(0x5772c0,'GUESS request gated particle resource','thiscall',None,ret=None,gen=g5772c0,note='batch100016')
