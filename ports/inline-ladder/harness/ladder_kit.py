"""ladder_kit.py - shared fake engine pieces for the ladder thread's specs (batches 204+).

Builds, on the pilot's fake heap: the engine global 0x70039c, ladder shapes with fake vtables (local/world transforms,
bound distance), the segment resource manager GetSegment (0x44ad50) reads, BasicShape spline records, and the
ladder-list iterator. Every stub logs (name, slot, this, values read from its pointer arguments) into emu.calllog,
so the two runs are compared on what the code asked for, not only on what it wrote."""
import struct
from pilot import F  # noqa: F401
import pe_emu
from pe_emu import f32

ENGINE = 0x70039c


def rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def rv3(e, a):
    return [e.rf32(a + 4 * i) for i in range(3)]


def bits3(e, a):
    return tuple(e.r32(a + 4 * i) for i in range(3))


def wv3(e, a, v):
    for i in range(3):
        e.wf32(a + 4 * i, f32(v[i]))


def nostack(x):
    """Stack addresses differ between the original and the port (frame layout); log them as 'stack'."""
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def vt(c, name, slots, nslots=0x70):
    """slots: {off: (nargs, fn(e, args) -> (eax, st0))}; the stub logs and pops nargs words."""
    e = c.emu
    hs = {}
    for off, (n, fn) in slots.items():
        def h(e2, r, off=off, n=n, fn=fn):
            args = [e2.arg32(k) for k in range(n)]
            eax, st0, extra = fn(e2, args)
            e2.calllog.append((name, off, e2.reg('ecx'), tuple(nostack(x) for x in args), extra))
            e2.ret(eax=eax, argbytes=4 * n, st0=st0)
        hs[off] = h
    return e.fake_vtable(name, nslots, hs)


def engine(c):
    e = c.emu
    eng = rnd(c, 0x1c00)
    e.w32(ENGINE, eng)
    return eng


def make_shape(c, eng_res, key, qlocal_hint=None, spread=70.0):
    """A ladder shape: vtable (0x84 local->world, 0x88 dir rotate, 0x8c world->local, 0x190 bound distance),
    +8 -> object with key at +0x6c, +0x1c BasicShape (records at +0x28, count at +0x2c). Registers the key's
    segment points with the resource manager dict eng_res."""
    e, r = c.emu, c.rng
    off = [f32(r.uniform(-200, 200)) for _ in range(3)]

    def to_world(e2, a):
        a0 = a[0]
        before = bits3(e2, a0)
        wv3(e2, a0, [f32(x + o) for x, o in zip(rv3(e2, a0), off)])
        return 0, None, before

    def to_local(e2, a):
        a0 = a[0]
        before = bits3(e2, a0)
        wv3(e2, a0, [f32(x - o) for x, o in zip(rv3(e2, a0), off)])
        return 0, None, before

    def rot(e2, a):
        a0 = a[0]
        before = bits3(e2, a0)
        x, y, z = rv3(e2, a0)
        if r.random() < 0.08:          # a degenerate direction, so the "exactly zero, do not normalise" path runs
            x = y = z = 0.0
        wv3(e2, a0, [z, y, -x])
        return 0, None, before

    def bound(e2, a):
        k = r.random()
        d = r.uniform(0, 45) if k < 0.75 else (r.uniform(45, 300) if k < 0.95 else r.choice([50.0, float('nan'), float('inf')]))
        return 0, d, bits3(e2, a[0])

    shape = rnd(c, 0x60)
    e.w32(shape, vt(c, 'shape%d' % key, {0x84: (1, to_world), 0x88: (1, rot), 0x8c: (1, to_local), 0x190: (1, bound)}))
    ko = rnd(c, 0x80)
    e.w32(shape + 8, ko)
    e.w32(ko + 0x6c, key)
    n = r.randint(1, 3)
    rec = rnd(c, 56 * n + 8)
    for i in range(n):
        for j in range(1, 13):
            e.wf32(rec + 56 * i + 4 * j, c.fv(-50.0, 50.0))
    e.w32(shape + 0x1c + 0xc, rec)
    e.w32(shape + 0x1c + 0x10, n)
    # segment points (local space), near the hint so ends come within reach
    m = r.randint(2, 4)
    pts = e.alloc(36 * m + 64, 4)
    hint = qlocal_hint if qlocal_hint is not None else [0.0, 0.0, 0.0]
    base = [h - o for h, o in zip(hint, off)]
    for i in range((36 * m + 48) // 4):
        e.wf32(pts + 4 * i, f32(base[i % 3] + r.uniform(-spread, spread)))
    cnt = e.alloc(8, 4)
    e.w32(cnt, m)
    eng_res[key] = (pts, cnt)
    return shape


def resource_manager(c, eng, eng_res):
    e = c.emu
    rm = rnd(c, 0x40)
    rm2 = rnd(c, 0x20)
    e.w32(eng + 0x1aa3, rm)
    e.w32(rm + 0x18, rm2)

    def pts(e2, a):
        return eng_res.get(a[0], (0, 0))[0], None, None

    def cnt(e2, a):
        return eng_res.get(a[0], (0, 0))[1], None, None
    e.w32(rm2, vt(c, 'segres', {0xfc: (1, pts), 0x100: (1, cnt)}))
