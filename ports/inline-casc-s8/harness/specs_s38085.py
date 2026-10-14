"""specs_s38085.py - cascade s8 batch 38085. thiscall(stream) ret 4 -> bool. this = 0x2800-byte random block. Stream slots 0x6c / 0x50 / 0x18 / 0x68 / 0x40 / 0x48 are Python stubs that log (slot, destination offset relative to this) and write
fresh random bytes into the destination (12 / 4 / n / 1 / 4 / 4 bytes); calls whose destination is not inside this (the stack local used as the id out parameter) log only a marker and write a random id. Engine table slots 0x58 (lookup:
logs its argument, returns a random value) and 0x138 -> object with slot 0x88 (writes a random id into its out pointer). 0x5159b0 (false 10%), 0x528740 and 0x5274a0 are hooked."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def _g521070(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    this = rnd(c, 0x2800)

    def mk(slot, width, nargs=1):
        def h(em, res_):
            d = em.arg32(0)
            inside = this <= d < this + 0x2800
            n = em.arg32(1) if nargs == 2 else width
            em.calllog.append(('slot%x' % slot, d - this if inside else 'local', n if nargs == 2 else 0))
            em.wbytes(d, bytes(r.getrandbits(8) for _ in range(n)))
            em.ret(eax=0, argbytes=4 * nargs)
        return e.stub_fn('slot%x' % slot, h)
    st = obj(c, 0x80, {0x6c: mk(0x6c, 12), 0x50: mk(0x50, 4), 0x18: mk(0x18, 0, 2), 0x68: mk(0x68, 1), 0x40: mk(0x40, 4), 0x48: mk(0x48, 4)})

    def z88(em, res_):
        em.calllog.append(('z88', em.arg32(0)))
        em.w32(em.arg32(1), r.getrandbits(32))
        em.ret(eax=0, argbytes=8)
    Z = obj(c, 0x20, {0x88: e.stub_fn('z88', z88)})
    sysobj(c, table_slots={0x58: e.stub_fn('lookup', lambda em, res_: (em.calllog.append(('lookup', em.arg32(0))), em.ret(eax=r.getrandbits(32), argbytes=4))),
                           0x138: e.stub_fn('s138', lambda em, res_: (em.calllog.append(('s138',)), em.ret(eax=Z)))})
    hook_rec(c, 0x5159b0, 1, this=True, pop=4, ret=lambda em, k: 0 if r.random() < 0.1 else 1)
    hook_rec(c, 0x528740, 1, this=True, pop=4)
    hook_rec(c, 0x5274a0, 1, this=True, pop=4)
    return [this, st]


S(0x521070, 'GUESS load record from stream', 'thiscall', None, ret='al', gen=_g521070, note='batch38085')
