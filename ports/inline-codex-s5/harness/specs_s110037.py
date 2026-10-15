"""specs_s5818.py - unclaimed-57, batch 118: 0x5d4ff0 (GUESS name unnamed_5d4ff0). Thiscall, no stack args, plain ret. The engine (global 0x70039c) has a fake vtable
with slot +0x1c0 (two args, returns st0 as a float: the two per-case values for the arguments 0x19 and 0x26, which are the only two calls). The
object at this+0x44 has fake slot +0x50c (no args, returns the object o, or null in about one case in five). o has fake slots +0x35c (no args, returns a
per-case dword), +0x360 (one arg, logged), +0x354 (no args, returns a per-case value whose low byte is tested), and +0x2d0 (two args, logged). this+0x48 is -1024
in about two cases in five (block 1 runs), otherwise random. The float constants are the exe's data. The float values are small so the products are exact enough
to exercise the rounding path."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d4ff0(c):
    from recruits_util import clear_hooks,pystub
    clear_hooks(c)
    e = c.emu
    e.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32)))
    # wide exponent range, so the long double sum needs more than 53 bits in some cases (double rounding would show)
    v19 = c.rng.uniform(-3.0, 3.0) * 10.0 ** c.rng.randrange(-8, 3)
    v26 = c.rng.uniform(-3.0, 3.0) * 10.0 ** c.rng.randrange(-8, 3)
    calls = [0]
    o_obj = _rnd(c, 0x40)
    null_o = c.rng.random() < 0.2
    r35c = c.rng.choice([0, 1])
    r354 = c.rng.choice([0, 1, 2])

    def h1c0(em, r):
        calls[0] += 1
        em.calllog.append(('1c0', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(st0=v19 if em.arg32(1) == 0x19 else v26, argbytes=8)

    def h50c(em, r):
        em.calllog.append(('50c', 0, None, ()))
        em.ret(eax=0 if null_o else o_obj, argbytes=0)

    def h35c(em, r):
        em.calllog.append(('35c', 0, None, ()))
        em.ret(eax=r35c, argbytes=0)

    def h360(em, r):
        em.calllog.append(('360', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h354(em, r):
        em.calllog.append(('354', 0, None, ()))
        em.ret(eax=r354, argbytes=0)

    def h2d0(em, r):
        em.calllog.append(('2d0', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    vt_eng = e.fake_vtable('d4ff0_eng', 1000, {0x1c0: h1c0})
    vt_o = e.fake_vtable('d4ff0_o', 1000, {0x35c: h35c, 0x360: h360, 0x354: h354, 0x2d0: h2d0})
    vt_obj = e.fake_vtable('d4ff0_obj', 1000, {0x50c: h50c})
    e.w32(o_obj, vt_o)
    obj = _rnd(c, 0x40)
    e.w32(obj, vt_obj)
    eng = _rnd(c, 0x2000)
    e.w32(eng, vt_eng)
    eng40 = c.rng.randrange(-300, 301)
    e.w32(eng + 0x40, eng40 & 0xffffffff)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x200)
    e.w32(self_obj + 0x44, obj)
    if c.rng.random() < 0.4:
        e.w32(self_obj + 0x48, 0xfffffc00)
    elif c.rng.random() < 0.3:
        e.w32(self_obj + 0x48, eng40 & 0xffffffff)  # equal to the engine value in some cases (the strict test is checked at its edge)
    else:
        e.w32(self_obj + 0x48, c.rng.randrange(-300, 301) & 0xffffffff)
    return [self_obj]


S(0x5d4ff0, 'unnamed_5d4ff0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d4ff0,
  note='unclaimed-57 batch 118; x87 rows in long double; engine slot +0x1c0 returns st0; object slots +0x50c, +0x35c, +0x360, +0x354, +0x2d0 fake')
