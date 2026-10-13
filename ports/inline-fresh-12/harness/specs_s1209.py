"""specs_s1209.py - fresh slice 12, batch 9 (4 functions). Exe callees hooked by address and logged; calls given a
pointer to a stack local log the value (and may change it), never the address."""
import struct
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global
from helpers12 import rand_obj, hk, done


def _eng(c, en):
    eng = zero_obj(c, 0x100)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)


def _g448ec0(c):
    c.emu.hook(0x4dc630, hk(0x4dc630, 'f4dc630', 2))
    ids = [c.rng.getrandbits(32) for _ in range(c.rng.choice([0, 1, 2, 4]))]
    st = {'i': 0}

    def l4c(em, r):
        em.calllog.append(('L', 0x4c, 0, ()))
        em.w32(em.arg32(0), 0x99)
        st['i'] = 0
        em.ret(eax=0, argbytes=4)

    def l5c(em, r):
        p = em.arg32(0)
        em.calllog.append(('L', 0x5c, 0, (em.r32(p),)))
        if st['i'] < len(ids):
            em.w32(p, 1)
            v = ids[st['i']]
            st['i'] += 1
        else:
            em.w32(p, 0)
            v = 0x5c5c
        em.ret(eax=v, argbytes=4)
    o = rand_obj(c, 0x20)
    if c.rng.random() < 0.85:
        l = zero_obj(c, 0x10)
        c.emu.w32(l, c.emu.fake_vtable('L', 0x20, {0x4c: l4c, 0x5c: l5c}))
        c.emu.w32(o + 0x1c, l)
    else:
        c.emu.w32(o + 0x1c, 0)
    objs = {i: logged_obj(c, 'T%d' % k, 0x90) for k, i in enumerate(ids) if c.rng.random() < 0.7}
    _eng(c, logged_obj(c, 'Eng', 0x30, impl={0x58: lambda e, a: (objs.get(a[0], 0), None)}, argwords={0x58: 1}))
    return done(c, [o])


S(0x448ec0, 'FUN_00448ec0 notify listed objects, 0x4dc630, flags |= 9', 'thiscall', None, ret=None, gen=_g448ec0,
  note='0x4dc630 (SetControl, blocked on the render manager) hooked')


def _g4fbfc0(c):
    for a in (0x4fbab0, 0x4fd800, 0x4fbb20):
        c.emu.hook(a, hk(a, 'f%x' % a, 1))
    o = rand_obj(c, 0x64)
    t = logged_obj(c, 'T', 0x50, argwords={0x128: 3})
    _eng(c, logged_obj(c, 'Eng', 0x30, impl={0x58: lambda e, ar: (t, None)}, argwords={0x58: 1}))
    pick = c.rng.choice([0x54, 0x56, 0x5a, 0x60, None])
    idv = struct.unpack('<H', bytes(c.emu.rbytes(o + pick, 2)))[0] if pick else c.rng.getrandbits(16)
    return done(c, [o, idv | (c.rng.getrandbits(16) << 16), c.rng.getrandbits(32)])


S(0x4fbfc0, 'FUN_004fbfc0 event id switch', 'thiscall', None, ret='eax', gen=_g4fbfc0)


def _g574600(c):
    r = rand_obj(c, 0x30)
    for i in range(4):
        c.emu.w32(r + 0x18 + 4 * i, c.rng.choice([0, c.rng.getrandbits(32)]))
    q = logged_obj(c, 'Q', 0xa0, impl={0x25c: lambda e, a: (r, None)}, argwords={0x25c: 2})
    o = logged_obj(c, 'O', 0x10, impl={0x20: lambda e, a: (q, None)})
    found = c.rng.choice([o, o, 0])
    _eng(c, logged_obj(c, 'Eng', 0x30, impl={0x58: lambda e, a: (found, None)}, argwords={0x58: 1}))
    return done(c, [rand_obj(c, 0x1c0), c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])])


S(0x574600, 'FUN_00574600 attach to first free slot', 'thiscall', None, ret='eax', gen=_g574600)


def _g567180(c):
    busy = c.rng.choice([0, 0, 1, 0x100])
    o = logged_obj(c, 'O', 0x40, impl={0xd8: lambda e, a: (0xee00 | busy, None)})
    c.emu.hook(0x562d90, hk(0x562d90, 'f562d90', 1, lambda em: em.arg32(0) ^ 0x5555))
    t0 = c.rng.getrandbits(32)
    c.emu.hook(0x566f10, hk(0x566f10, 'f566f10', 0, lambda em: t0))
    for a in (0x563d20, 0x563d40):
        def h(em, r, a=a):
            p = em.arg32(1)
            em.calllog.append(('f%x' % a, 0, em.reg('ecx'), (em.arg32(0), em.r32(p), em.arg32(2))))
            em.w32(p, em.r32(p) ^ 0x0f0f)   # the callee may update the value
            em.ret(eax=0, argbytes=0xc)
        c.emu.hook(a, h)
    c.emu.hook(0x5672c0, hk(0x5672c0, 'f5672c0', 1))
    c.emu.hook(0x567510, hk(0x567510, 'f567510', 0, lambda em: 0x77777700))
    return done(c, [o, c.rng.choice([0x102, 0x103, 0x101, 0x104, c.rng.getrandbits(32)])])


S(0x567180, 'FUN_00567180 handle 0x102/0x103 or forward', 'thiscall', None, ret='al', gen=_g567180)
