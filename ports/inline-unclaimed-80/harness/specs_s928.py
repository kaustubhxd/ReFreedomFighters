"""specs_s928.py - unclaimed-80 claim 8 (docs/20-unclaimed-80.md): CAction::Run (0x4a18b0). Every call is a logging fake:
the global sub-object (slot +0x58 returns b, slot +0x114 five arguments returns a word), the CAction object itself (slot +0x84
returns al), the object at +0x44 (slots +0x130 with two arguments and +0x12c with three), and b (slots +0x1e0 returns al and
+0x42c, one argument each). this+0x48 is 7 (30%), 6 (30%) or another value (40%); the pointer at +0x4e and the word at +0x4c
are zero about a fifth of the time. Only the used slots are defined; the rest of each table is left zero."""
from pilot import S
import importlib


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fake(c, name, nslots, handlers, argc):
    """handlers: {off: (nargs, impl(emu, args) -> (eax, st0))}; logs every call with its arguments."""
    slots = {}
    for off, (n, fn) in handlers.items():
        def h(e, r, off=off, n=n, fn=fn):
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple(args)))
            eax, st0 = fn(e, args)
            e.ret(eax=eax, argbytes=4 * n)
        slots[off] = h
    return c.emu.fake_vtable(name, nslots, slots)


def _run(c):
    a1 = c.rng.getrandbits(32)
    b = _rnd(c, 0x40)
    v84 = c.rng.choice([0, 1, 0x101, c.rng.getrandbits(32)])
    v1e0 = c.rng.choice([0, 1, c.rng.getrandbits(32)])
    w114 = c.rng.getrandbits(16)
    bh = c.rng.getrandbits(32)
    b_vt = _fake(c, 'ZRunB', 0x110, {0x1e0: (1, lambda e, a, v=v1e0: (v, None)),
                                    0x42c: (1, lambda e, a: (0, None))}, 1)
    c.emu.w32(b, b_vt)
    sub = _rnd(c, 0x40)
    sub_vt = _fake(c, 'ZRunSub', 0x50, {0x58: (1, lambda e, a, bb=b: (bb, None)),
                                       0x114: (5, lambda e, a, w=w114: (w, None))}, 5)
    c.emu.w32(sub, sub_vt)
    obj = _rnd(c, 0x40)
    obj_vt = _fake(c, 'ZRunObj', 0x50, {0x130: (2, lambda e, a: (0, None)), 0x12c: (3, lambda e, a: (0, None))}, 3)
    c.emu.w32(obj, obj_vt)
    g = _rnd(c, 0x100)
    c.emu.w32(g + 0x9b, sub)
    c.emu.w32(0x70039c, g)
    self_o = _rnd(c, 0x100)
    self_vt = _fake(c, 'ZRunSelf', 0x90, {0x84: (1, lambda e, a, v=v84: (v, None))}, 1)
    c.emu.w32(self_o, self_vt)
    r = c.rng.random()
    c.emu.w32(self_o + 0x48, 7 if r < 0.3 else (6 if r < 0.6 else c.rng.getrandbits(32)))
    c.emu.w32(self_o + 0x44, obj)
    c.emu.w32(self_o + 0x4e, 0 if c.rng.random() < 0.2 else c.rng.getrandbits(32))
    c.emu.w16(self_o + 0x4c, 0 if c.rng.random() < 0.2 else c.rng.getrandbits(16))
    return [self_o, a1]


S(0x4a18b0, 'CAction::Run (unknown) thiscall', 'thiscall', None, ret=None, gen=_run,
  note='unclaimed-80 claim 8; all calls virtual logging fakes (sub 0x58 and 0x114, this 0x84, obj 0x130 and 0x12c, b 0x1e0 and 0x42c)')
