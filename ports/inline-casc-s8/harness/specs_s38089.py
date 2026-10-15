"""specs_s38089.py - cascade s8 batch 38089. thiscall(void); this = 0x1000-byte random block (pointer this[0x94] -> a block, only used as an address). 0x57fa80 (11-stack-argument widget init, thiscall) is a custom
hook logging (ecx - this, the 11 arguments); the stores into this are compared through the heap."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks


def _g564b50(c):
    clear_hooks(c)
    e = c.emu
    this = rnd(c, 0x1000)
    blk = rnd(c, 0x500)
    e.wbytes(this + 0x94, struct.pack('<I', blk))

    def w(em, res_):
        em.calllog.append(('widget', em.reg('ecx') - this) + tuple(em.arg32(i) for i in range(11)))
        em.ret(eax=0, argbytes=44)
    e.hook(0x57fa80, w)
    return [this]


S(0x564b50, 'GUESS init dialog controls', 'thiscall', None, ret=None, gen=_g564b50, note='batch38089')
