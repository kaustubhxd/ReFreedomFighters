"""specs_s38084.py - cascade s8 batch 38084. thiscall(void); this = 0x5e00-byte random block whose 21 unaligned pointer fields (+0x5d49 ... +0x5d9d, step 4, skipping +0x5d81) are each null (30%) or an object with a logging slot 0
(deleting destructor); the engine object's slot 0x1a8 logs its argument."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks

OFFS = [0x5d49, 0x5d4d, 0x5d51, 0x5d55, 0x5d59, 0x5d5d, 0x5d61, 0x5d65, 0x5d69, 0x5d6d, 0x5d71, 0x5d75, 0x5d79, 0x5d7d, 0x5d85, 0x5d89, 0x5d8d, 0x5d91, 0x5d95, 0x5d99, 0x5d9d]


def _g493c20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sysobj(c, slots={0x1a8: e.stub_fn('s1a8', lambda em, res_: (em.calllog.append(('s1a8', em.reg('ecx') != 0, em.arg32(0))), em.ret(eax=0, argbytes=4)))})
    this = rnd(c, 0x5e00)

    def dtor(em, res_):
        em.calllog.append(('dtor', em.reg('ecx'), em.arg32(0)))
        em.ret(eax=0, argbytes=4)
    for off in OFFS:
        v = 0 if r.random() < 0.3 else obj(c, 0x20, {0: e.stub_fn('dtor', dtor)})
        e.wbytes(this + off, struct.pack('<I', v))
    return [this]


S(0x493c20, 'GUESS release owned objects', 'thiscall', None, ret=None, gen=_g493c20, note='batch38084')
