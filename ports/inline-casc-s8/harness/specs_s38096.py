"""specs_s38096.py - cascade s8 batch 38096. thiscall(stream) ret 4 -> bool. this = 0x300-byte random block. The base load 0x45f3c0 is hooked (false 10%). Stream slots 0x40 / 0x48 / 0x50 / 0x68 / 0x6c / 0x18 are Python stubs logging (slot, destination
offset relative to this or 'local') and writing fresh random bytes into the destination (the id-array count slot writes a small count 0..2 (the array at +0x24 overlaps +0x2c from its third entry) so the array loop runs); engine table slots 0x54 / 0x58 (lookups) log their argument and return
a random value."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def _g446040(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    this = rnd(c, 0x300)
    st_ = {'n': 0}

    def mk(slot, width, nargs=1):
        def h(em, res_):
            d = em.arg32(0)
            inside = this <= d < this + 0x300
            n = em.arg32(1) if nargs == 2 else width
            em.calllog.append(('slot%x' % slot, d - this if inside else 'local', n if nargs == 2 else 0))
            if inside and d == this + 0x2c:
                data = struct.pack('<I', r.choice([0, 1, 2, 2]))
            else:
                data = bytes(r.getrandbits(8) for _ in range(n))
            em.wbytes(d, data)
            em.ret(eax=0, argbytes=4 * nargs)
        return e.stub_fn('slot%x' % slot, h)
    st = obj(c, 0x80, {0x40: mk(0x40, 4), 0x48: mk(0x48, 4), 0x50: mk(0x50, 4), 0x68: mk(0x68, 1), 0x6c: mk(0x6c, 12), 0x18: mk(0x18, 0, 2)})
    sysobj(c, table_slots={0x54: e.stub_fn('l54', lambda em, res_: (em.calllog.append(('l54', em.arg32(0))), em.ret(eax=r.getrandbits(32), argbytes=4))),
                           0x58: e.stub_fn('l58', lambda em, res_: (em.calllog.append(('l58', em.arg32(0))), em.ret(eax=r.getrandbits(32), argbytes=4)))})
    hook_rec(c, 0x45f3c0, 1, this=True, pop=4, ret=lambda em, k: 0 if r.random() < 0.1 else 1)
    return [this, st]


S(0x446040, 'GUESS load record 3 from stream', 'thiscall', None, ret='al', gen=_g446040, note='batch38096')
