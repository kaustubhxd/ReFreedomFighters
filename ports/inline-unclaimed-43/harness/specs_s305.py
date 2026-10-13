"""specs_s305.py - unclaimed-43 batch 305: path probe (0x558fe0), thiscall, one stack argument, ret 4.
Mocks (all logging, values drawn in gen):
  - the engine (g_pSysInterface at 0x70039c, member +0x9b) with slot 0x58 returning an object r2 whose slot 0x84 writes and
    logs three values into tmp;
  - the object at this+0x1c (M): slot 0x5d0 returns a path object (70%) or NULL (30%); slot 0x84 logs the three floats it is
    given (it does not write them, so the caller's values are what gets compared); M+8 is a ZBaseGeom-like block with the
    position at +0x24;
  - the printer at 0x700390: slot 0x20 (thiscall, two args) returns P1; P1 slot 0x2c is cdecl (the caller pops 8);
  - the hook pointer at 0x7003b0 is a stub (the exe calls it with no arguments before FindPathLength returns).
Element records (8 bytes) have type 0 or 2, the only types the normal path accepts (other types reach printer code)."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

NSLOTS_M = 0x5d4 // 4        # slot 0x5d0
NSLOTS_EN = 0x5c // 4        # slot 0x58
NSLOTS_R2 = 0x88 // 4        # slot 0x84
NSLOTS_P0 = 0x24 // 4        # slot 0x20
NSLOTS_P1 = 0x30 // 4        # slot 0x2c


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _vtable(c, name, nslots, impl, argwords, cdecl=()):
    """Logging vtable. argwords: stack words per slot; cdecl: slots whose caller pops the arguments (argbytes 0)."""
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


def _array(c, n_elems, start, count=None):
    """Two-level array as 5003d0 reads it: the object {T, start, count} whose T is {data, -, count2}; the element at
    data + 8 * index (index = start + i) is valid for index < count2. Element records are 8 bytes of random data.
    Returns (object, data)."""
    n = count or n_elems
    data = c.emu.alloc(8 * n + 16, 8)
    c.emu.wbytes(data, bytes(c.rng.getrandbits(8) for _ in range(8 * n + 16)))
    t = E.zero_obj(c, 0x20)
    c.emu.w32(t, data)
    c.emu.w32(t + 8, n)
    a = E.zero_obj(c, 0x20)
    c.emu.w32(a, t)
    c.emu.w32(a + 4, start)
    c.emu.w32(a + 8, n)
    return a, data


def _gen(c):
    r = c.rng

    def wf(e, a):
        # logs the three floats the probe passes (no write: the values the exe and the port produce are what is compared)
        e.calllog.append(('vec3', 0, 0, (e.rbytes(a[0], 12),)))
        return (None, None)

    fp = E.zero_obj(c, 0x40)
    path = r.random() < 0.7
    impl_m = {0x5d0: lambda e, a: (fp if path else 0, None), 0x84: wf}
    m = E.zero_obj(c, 0x40)
    mobj = _vtable(c, 'ZPATHOWNER', NSLOTS_M, impl_m, {0x5d0: 0, 0x84: 1})
    c.emu.w32(m, mobj)
    g = E.zero_obj(c, 0x40)
    for k in range(3):
        c.emu.wf32(g + 0x24 + 4 * k, c.fv(-50.0, 50.0))
    c.emu.w32(m + 8, g)

    tvals = [c.fv(-50.0, 50.0) for _ in range(3)]    # drawn once per case: the exe and the port must see the same values

    def wr(e, a):
        # r2 writes three values into tmp and logs them
        for k, v in enumerate(tvals):
            e.wf32(a[0] + 4 * k, v)
        e.calllog.append(('tmp3', 0, 0, tuple(struct.unpack('<I', struct.pack('<f', v))[0] for v in tvals)))   # bits: NaN never compares equal
        return (None, None)

    r2 = E.zero_obj(c, 0x40)
    r2vt = _vtable(c, 'ZPATHTMP', NSLOTS_R2, {0x84: wr}, {0x84: 1})
    c.emu.w32(r2, r2vt)
    en = E.zero_obj(c, 0x40)
    env = _vtable(c, 'ZPATHENGINE', NSLOTS_EN, {0x58: lambda e, a: (r2, None)}, {0x58: 1})
    c.emu.w32(en, env)
    eng = E.zero_obj(c, 0x400)
    c.emu.w32(eng + 0x9b, en)
    E.set_global(c, 0x70039c, eng)

    p1 = E.zero_obj(c, 0x40)
    p1vt = _vtable(c, 'ZPRINTER1', NSLOTS_P1, {}, {0x2c: 2}, cdecl=(0x2c,))
    c.emu.w32(p1, p1vt)
    p0 = E.zero_obj(c, 0x40)
    p0vt = _vtable(c, 'ZPRINTER0', NSLOTS_P0, {0x20: lambda e, a: (p1, None)}, {0x20: 2})
    c.emu.w32(p0, p0vt)
    E.set_global(c, 0x700390, p0)
    E.set_global(c, 0x7003b0, c.emu._new_stub('hook0', lambda e, rr: e.ret(eax=0, argbytes=0)))

    p = E.zero_obj(c, 0x40)
    a1s, _b1 = _array(c, 3, r.randrange(3), count=3)
    c.emu.w32(p + 4, a1s)
    q, qb = _array(c, 3, r.randrange(3), count=3)
    qstart = c.emu.r32(q + 4)
    c.emu.wbytes(qb + 8 * qstart + 4, bytes([2 if r.random() < 0.5 else 0]))
    c.emu.w32(p + 8, q)
    self_ = E.zero_obj(c, 0x40)
    c.emu.w32(self_ + 0x1c, m)
    c.emu.mu.ctl_flush_tb()
    return [self_, p]


S(0x558fe0, 'path probe (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-43 batch 305; FindPathLength 0x52b330 is original exe code (prints via the 0x700390 printer, returns 0)')
