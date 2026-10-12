"""specs_s319.py - gap band, batch 319: two buffer-cursor readers (thiscall, ret 8). The buffer object at [this] has a vtable whose slot
0x2c is a stdcall stub with five arguments (buf, a, b, &slot, count). The stub writes its slot value and returns eax (zero or not),
both chosen per run. The stub logs the arguments with the slot pointer replaced by the value written."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _make(name):
    def gen(c):
        e = c.emu
        rng = c.rng
        slotval = rng.getrandbits(32)
        eaxv = rng.choice([0, 0, 1])

        def h2c(em, r):
            a = [em.arg32(k) for k in range(5)]
            em.w32(a[3], slotval)
            em.calllog.append(('slot2c', 0x2c, None, (a[0], a[1], a[2], ('slot', slotval), a[4])))
            em.ret(eax=eaxv, argbytes=20)

        buf = e.alloc(0x40, 4)
        e.w32(buf, e.fake_vtable('buf', 0x40, {0x2c: h2c}))
        self_ = _rnd(c, 0x40)
        limit = rng.randrange(0, 0x40)
        e.w32(self_ + 4, limit)
        e.w32(self_ + 8, rng.randrange(0, 0x40))
        e.wbytes(self_ + 0xc, bytes([rng.choice([0, 1])]))
        e.wbytes(self_ + 0xd, bytes([rng.choice([0, 0, 1])]))
        e.wbytes(self_ + 0x10, bytes([rng.choice([0, 1])]))
        e.wbytes(self_ + 0x11, bytes([rng.choice([0, 0, 1])]))
        e.w32(self_, buf if rng.random() < 0.9 else 0)
        pp = _rnd(c, 4)
        e.w32(pp, rng.choice([0, rng.randrange(0, 0x40), rng.randrange(0, 0x40), rng.getrandbits(32)]))
        pout = _rnd(c, 4)
        return [self_, pp, pout]
    return gen


S(0x60ed80, 'cursorRead60ed80 (GUESS)', 'thiscall', None, ret='eax', gen=_make('a'), note='batch319; ret 8; slot 0x2c stubbed')
S(0x60ee10, 'cursorRead60ee10 (GUESS)', 'thiscall', None, ret='eax', gen=_make('b'), note='batch319; ret 8; slot 0x2c stubbed')
