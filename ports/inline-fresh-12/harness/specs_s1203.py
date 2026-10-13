"""specs_s1203.py - fresh slice 12, batch 3 (13 functions). Exe callees hooked by address and logged; the failure
handler pointer 0x7003b0 is set to a logging stub (never null in these specs, so the int3 path is not exercised)."""
from pilot import S, F
from engine_stubs import zero_obj, logged_obj, set_global
from helpers12 import rand_obj, rand_fast, hk, hk_cdecl, done, com_obj, fail_stub
import struct


def _g5f4940(c):
    fail_stub(c, c.rng.getrandbits(32))
    o = rand_obj(c, 0xa0)
    nodes = []
    for k in range(c.rng.choice([0, 1, 2, 3])):
        n = rand_fast(c, 0xa0)
        lo = c.rng.randrange(0, 1000)
        c.emu.w32(n + 0x54, lo)
        c.emu.w32(n + 0x58, lo + c.rng.choice([0, 1, 5, 100]))
        nodes.append(n)
    for i, n in enumerate(nodes):
        c.emu.w32(n + 0x9c, nodes[i + 1] if i + 1 < len(nodes) else 0)
    c.emu.w32(o + 0x96, nodes[0] if nodes else 0)
    x = c.rng.choice([c.rng.randrange(0, 1200), c.rng.getrandbits(32)])
    if nodes and c.rng.random() < 0.3:
        x = c.emu.r32(c.rng.choice(nodes) + 0x58)   # hi is exclusive
    return done(c, [o, x])


S(0x5f4940, 'FUN_005f4940 map value through range list', 'thiscall', None, ret='eax', gen=_g5f4940)


def _s63a800(c):
    c.emu.hook(0x63fdd0, hk(0x63fdd0, 'f63fdd0', 2))


S(0x63a800, 'FUN_0063a800 init free list of 0x3ff entries', 'thiscall', None, ret='eax', setup=_s63a800,
  gen=lambda c: done(c, [rand_fast(c, 0x3410), c.rng.getrandbits(32), c.rng.getrandbits(32)]))


def _g5f32c0(c):
    fail_stub(c, c.rng.getrandbits(32))
    o = rand_obj(c, 0x10)
    buf = rand_obj(c, 8)
    c.emu.w32(o + 8, buf)
    c.emu.w32(o + 0xc, buf + c.rng.choice([0, 1, 2, 3, 4, 6]))
    return done(c, [o, c.rng.getrandbits(32)])


S(0x5f32c0, 'FUN_005f32c0 append u16 (fail on overflow)', 'thiscall', None, ret=None, gen=_g5f32c0)


def _s563440(c):
    c.emu.hook(0x4f21f0, hk(0x4f21f0, 'f4f21f0', 1))


def _g563440(c):
    r = rand_obj(c, 0x10)
    o = logged_obj(c, 'Obj', 0x30, impl={0x84: lambda e, a: (r, None)})
    c.emu.w8(o + 0x85, c.rng.choice([0, 0, 1, 7]))
    eng = zero_obj(c, 0x100)
    c.emu.w32(eng + 0x30, c.rng.getrandbits(32))
    set_global(c, 0x70039c, eng)
    return done(c, [o])


S(0x563440, 'FUN_00563440 start once (clock * 1/1024, slot 0x84 -> 0x4f21f0)', 'thiscall', None, ret=None,
  setup=_s563440, gen=_g563440)


def _g4b0c00(c):
    o = rand_obj(c, 0x60)
    eng = zero_obj(c, 0x1b00)
    tgt = logged_obj(c, 'Tgt', 0x40, argwords={0xcc: 1})
    c.emu.w32(eng + 0x1a9f, tgt)
    start = c.rng.getrandbits(32)
    c.emu.w32(o + 0x50, start)
    c.emu.w32(eng + 0x40, (start + c.rng.choice([0, 1, 50, 1000, 100000, c.rng.getrandbits(32)])) & 0xffffffff)
    c.emu.w32(o + 0x58, c.rng.choice([0, 1, 25, 1000, 0x7fffffff, c.rng.getrandbits(32)]))
    set_global(c, 0x70039c, eng)
    return done(c, [o])


S(0x4b0c00, 'FUN_004b0c00 timeout check -> engine+0x1a9f slot 0xcc(0)', 'thiscall', None, ret=None, gen=_g4b0c00)


def _g4f7ec0(c):
    o = rand_obj(c, 0xa4)
    a = c.rng.choice([c.rng.randrange(-1000, 1000), c.rng.getrandbits(32)])
    b = c.rng.choice([c.rng.randrange(-1000, 1000), c.rng.getrandbits(32)])
    c.emu.w32(o + 0x8f, a & 0xffffffff)
    c.emu.w32(o + 0x93, b & 0xffffffff)
    t = c.fv(-2.0, 2.0)
    c.emu.wbytes(o + 0x9f, struct.pack('<f', t))
    return done(c, [o])


S(0x4f7ec0, 'FUN_004f7ec0 lerp ints and round', 'thiscall', None, ret='eax', gen=_g4f7ec0)


def _g63b0c0(c):
    o = rand_fast(c, 64 * 17)
    c.emu.w16(o + 2, c.rng.choice([0xffff, c.rng.randrange(0, 16)])) if hasattr(c.emu, 'w16') else \
        c.emu.wbytes(o + 2, struct.pack('<H', c.rng.choice([0xffff, c.rng.randrange(0, 16)])))
    return done(c, [o])


S(0x63b0c0, 'FUN_0063b0c0 pop free-list entry', 'thiscall', None, ret='eax', gen=_g63b0c0)


def _g492200(c):
    o = logged_obj(c, 'O', 0x10, argwords={0xc: 1})
    m = logged_obj(c, 'M1', 0x10, impl={8: lambda e, a: (0x1111, None)}, argwords={8: 1})
    m2 = logged_obj(c, 'M2', 0x10, impl={8: lambda e, a: (0x2222 ^ a[0], None)}, argwords={8: 1})
    en = logged_obj(c, 'Eng', 0x60, impl={0x138: lambda e, a: (m, None), 0x134: lambda e, a: (m2, None)})
    eng = zero_obj(c, 0x100)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    return done(c, [rand_obj(c, 0x10), o])


S(0x492200, 'FUN_00492200 register with engine lists 0x138 and 0x134', 'thiscall', None, ret='eax', gen=_g492200)


def _g4a8500(c):
    s = logged_obj(c, 'Stream', 0x20, argwords={0x40: 1, 0x44: 1, 0x48: 1})
    return done(c, [rand_obj(c, 0x60), s])


S(0x4a8500, 'FUN_004a8500 read five fields from stream', 'thiscall', None, ret='al', gen=_g4a8500)


def _g613980(c):
    more = c.rng.choice([0, 1])
    c.emu.hook(0x613ba0, hk(0x613ba0, 'f613ba0', 0, lambda em: 0xabcdef00 | more))
    c.emu.hook(0x613a70, hk(0x613a70, 'f613a70', 0, lambda em: em.reg('ecx') ^ 0x5a5a))
    o = rand_obj(c, 0x10)
    k = c.rng.choice([0, 1, 2, 3, 4])
    nodes = [rand_obj(c, 0x10) for _ in range(k)]
    for n in nodes:
        if c.rng.random() < 0.6:
            c.emu.wbytes(n + 2, b'\xff\xff')
    ring = c.rng.random() < 0.6
    for i, n in enumerate(nodes):
        c.emu.w32(n + 8, nodes[i + 1] if i + 1 < k else (nodes[0] if ring else 0))
    if nodes and not ring and c.rng.random() < 0.5:   # start in the middle of a ring
        pass
    c.emu.w32(o + 8, nodes[c.rng.randrange(k)] if (nodes and ring) else (nodes[0] if nodes else 0))
    return done(c, [o])


S(0x613980, 'FUN_00613980 iterator next (skip dead nodes)', 'thiscall', None, ret='eax', gen=_g613980)


def _s54c380(c):
    c.emu.hook(0x54f2b0, lambda em, r: (em.calllog.append(('f54f2b0', 0, em.reg('ecx'), (em.reg('edx'),))),
                                        em.ret(eax=0, argbytes=0)))


def _g54c380(c):
    o = zero_obj(c, 0x6400)
    c.emu.w32(o, c.emu.logging_vtable('Obj', 0x20, argwords={0x2c: 1}))
    hr = c.rng.choice([0, 0x80004005, 1])
    p = com_obj(c, 'Dev', 0x10, impl={0x30: lambda e, a: hr}, argwords={0x34: 2, 0x30: 4})
    c.emu.w32(o + 0x63ec, p)
    return done(c, [o, c.rng.choice([0, 1, 0x100, 0xff, c.rng.getrandbits(32)])])


S(0x54c380, 'FUN_0054c380 device calls 0x34/0x30 (COM stdcall)', 'thiscall', None, ret=None, setup=_s54c380,
  gen=_g54c380)


def _s43b7c0(c):
    c.emu.hook(0x4cbec0, hk(0x4cbec0, 'member_dtor', 0))
    c.emu.hook(0x61ba60, hk(0x61ba60, 'base_dtor', 0))
    c.emu.hook(0x634273, hk_cdecl(0x634273, 'delete_sized', 2))


S(0x43b7c0, 'FUN_0043b7c0 scalar deleting dtor (size 0x24b)', 'thiscall', None, ret='eax', setup=_s43b7c0,
  gen=lambda c: done(c, [rand_obj(c, 0x40), c.rng.getrandbits(32)]))


def _g4b3400(c):
    o = rand_obj(c, 0x60)
    pr = com_obj(c, 'Printer', 0x10, argwords={0x2c: 2}, callee_pops=False)
    log = logged_obj(c, 'Log', 0x10, impl={0x20: lambda e, a: (pr, None)}, argwords={0x20: 2})
    set_global(c, 0x700390, log)
    pick = c.rng.choice([0x51, 0x53, 0x55, None])
    idw = c.emu.r32(o + pick) & 0xffff if pick else c.rng.getrandbits(16)
    out = zero_obj(c, 8)
    return done(c, [o, idw | (c.rng.getrandbits(16) << 16), out])


S(0x4b3400, 'FUN_004b3400 resource lookup by id (logs unknown ids)', 'thiscall', None, ret='eax', gen=_g4b3400)
