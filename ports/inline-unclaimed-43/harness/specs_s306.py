"""specs_s306.py - unclaimed-43 batch 306: ZGEOM::ActivateEvents() (0x45c6a0), thiscall, no arguments.
Mocks (values drawn in gen):
  - ZBaseGeom::ChkEvents (exe code, 0x4da3a0) reads this+8 -> +0x54 -> +0x10 -> +8: the spec makes it true in 80% of cases;
  - X (this+0x10 -> +8): slot 0x4c writes a count c0 (1..3) through its pointer; slot 0x5c writes the current count and
    counts down (so the loop body runs c0 times), returns a value; slot 0x44 writes 0 and ends the count;
  - g2 (global 0x70038c) slot 0xcc returns a record r or NULL (by the argument's low bit); r+8 holds a random dword;
  - this slot 0x11c logs its two arguments (r and r+8).
The count pointer is a stack address (logged as 'stack'); the logged calls carry every value the loop takes."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

NSLOTS_X = 0x60 // 4          # slots 0x44, 0x4c, 0x5c
NSLOTS_G2 = 0xd0 // 4         # slot 0xcc
NSLOTS_SELF = 0x120 // 4      # slot 0x11c


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _vtable(c, name, nslots, impl, argwords, cdecl=()):
    slots = {}
    for i in range(nslots):
        off = 4 * i

        def h(e, r, off=off):
            n = argwords.get(off, 0)
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple(_nostack(x) for x in args)))
            f = impl.get(off)
            eax, st0 = (f(e, args) if f else (0, None))
            e.ret(eax=eax, argbytes=0 if off in cdecl else 4 * n, st0=st0)
        slots[off] = h
    return c.emu.fake_vtable(name, nslots, slots)


def _gen(c):
    r = c.rng
    self_ = E.zero_obj(c, 0x40)
    geom = E.zero_obj(c, 0x40)
    c.emu.w32(self_ + 8, geom)
    if r.random() < 0.8:
        z = E.zero_obj(c, 0x40)
        w = E.zero_obj(c, 0x40)
        c.emu.w32(w + 8, 1 if r.random() < 0.9 else 0)
        c.emu.w32(z + 0x10, w)
        c.emu.w32(geom + 0x54, z)
    eobj = E.zero_obj(c, 0x40)
    c0 = r.randrange(1, 4)
    state = {'cnt': 0}
    vals = [r.getrandbits(32) for _ in range(4)]

    def m4c(e, a):
        e.w32(a[0], c0)
        state['cnt'] = c0
        return (None, None)

    def m5c(e, a):
        e.w32(a[0], state['cnt'])
        v = vals[state['cnt'] % 4]
        if state['cnt'] > 0:
            state['cnt'] -= 1
        return (v, None)

    def m44(e, a):
        e.w32(a[0], 0)
        state['cnt'] = 0
        return (None, None)

    x = E.zero_obj(c, 0x40)
    xvt = _vtable(c, 'ZGEOMEVENTS', NSLOTS_X, {0x4c: m4c, 0x5c: m5c, 0x44: m44}, {0x4c: 1, 0x5c: 1, 0x44: 1})
    c.emu.w32(x, xvt)
    if r.random() < 0.9:
        c.emu.w32(eobj + 8, x)
    c.emu.w32(self_ + 0x10, eobj)

    rec = E.zero_obj(c, 0x40)
    c.emu.w32(rec + 8, r.getrandbits(32))

    def m_cc(e, a):
        # deterministic in the argument (a random draw here would differ between the original and the port run)
        return (rec if (e.arg32(0) & 1) else 0, None)

    g2 = E.zero_obj(c, 0x40)
    g2vt = _vtable(c, 'ZGEOMG2', NSLOTS_G2, {0xcc: m_cc}, {0xcc: 1})
    c.emu.w32(g2, g2vt)
    E.set_global(c, 0x70038c, g2)

    selfvt = _vtable(c, 'ZGEOMSELF', NSLOTS_SELF, {}, {0x11c: 2})
    c.emu.w32(self_, selfvt)
    c.emu.mu.ctl_flush_tb()
    return [self_]


S(0x45c6a0, 'ZGEOM::ActivateEvents()', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-43 batch 306; ChkEvents 0x4da3a0 is original exe code')
