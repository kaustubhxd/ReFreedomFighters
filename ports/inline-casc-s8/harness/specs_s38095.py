"""specs_s38095.py - cascade s8 batch 38095. thiscall(stream) ret 4 -> bool. this = 0x1400-byte random block; stream slots 0x6c / 0x74 / 0x50 / 0x48 / 0x68 / 0x40 are Python stubs logging (slot, destination offset relative to this, or
'local' for the stack out parameter) and writing fresh random bytes (12 / 8? / 4 / 2 / 1 / 4). Engine table slot 0x58 (lookup) logs its argument and returns a random value. The sub-record readers 0x516470 / 0x529d00 / 0x529d70 /
0x516d10 are hooked (their ecx, a heap address inside this, is recorded)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def _g525bc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    this = rnd(c, 0x1400)

    def mk(slot, width):
        def h(em, res_):
            d = em.arg32(0)
            inside = this <= d < this + 0x1400
            em.calllog.append(('slot%x' % slot, d - this if inside else 'local'))
            em.wbytes(d, bytes(r.getrandbits(8) for _ in range(width)))
            em.ret(eax=0, argbytes=4)
        return e.stub_fn('slot%x' % slot, h)
    st = obj(c, 0x80, {0x6c: mk(0x6c, 12), 0x74: mk(0x74, 4), 0x50: mk(0x50, 4), 0x48: mk(0x48, 2), 0x68: mk(0x68, 1), 0x40: mk(0x40, 4)})
    sysobj(c, table_slots={0x58: e.stub_fn('lookup', lambda em, res_: (em.calllog.append(('lookup', em.arg32(0))), em.ret(eax=r.getrandbits(32), argbytes=4)))})
    for a in (0x516470, 0x529d00, 0x529d70, 0x516d10):
        hook_rec(c, a, 1, this=True, pop=4)
    return [this, st]


S(0x525bc0, 'GUESS load record 2 from stream', 'thiscall', None, ret='al', gen=_g525bc0, note='batch38095')
