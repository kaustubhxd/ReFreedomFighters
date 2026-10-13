"""specs_s705.py - soldier AI batch 705: CCheckVisible::FrameUpdate helpers (timer setter, UpdateVisible,
GetObjectPosSneak, GetSeerPosDir). The geom is a fake whose slots log their inputs (contents of stack matrices, not
their addresses), write random outputs and return random values (bools with random upper bits)."""
import math
import struct
from pilot import S, f32
from specs_s701 import _world, _cv, _rnd
from specs_s702 import _inv


def _bool(c):
    return (c.rng.getrandbits(24) << 8) | c.rng.choice([0, 1])


def _fl(c):
    return struct.pack('<f', f32(c.rng.choice([c.rng.uniform(-100, 100), 0.0, math.nan, 1e30])))


def nostk(v):
    import pe_emu
    return 'stk' if isinstance(v, int) and pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= v < pe_emu.STACK_TOP else v


def geom_fake(c, extra=None, size=64):
    e = c.emu
    rd = lambda a, n: tuple(struct.unpack('<%dI' % n, e.rbytes(a, 4 * n)))

    def log(name, off, args):     # stack addresses differ between the two codes: logged as 'stk'
        e.calllog.append((name, off, e.reg('ecx'), tuple(nostk(a) for a in args)))

    def s_ret(off, gen):
        def h(em, r):
            log('geom', off, ())
            em.ret(eax=gen(), argbytes=0)
        return h

    def s390(em, r):
        bone, mat, pos = em.arg32(0), em.arg32(1), em.arg32(2)
        log('geom', 0x390, (bone, pos))
        em.wbytes(mat, b''.join(_fl(c) for _ in range(9)))
        em.wbytes(pos, b''.join(_fl(c) for _ in range(3)))
        em.ret(eax=_bool(c), argbytes=12)

    def s2ac(em, r):
        mat, pos = em.arg32(0), em.arg32(1)
        log('geom', 0x2ac, rd(mat, 9) + (pos,))
        em.wbytes(pos, b''.join(_fl(c) for _ in range(3)))
        em.ret(eax=c.rng.getrandbits(32), argbytes=8)

    def s84(off):
        def h(em, r):
            p = em.arg32(0)
            log('geom', off, rd(p, 3) + (p,))
            em.wbytes(p, b''.join(_fl(c) for _ in range(3)))
            em.ret(eax=c.rng.getrandbits(32), argbytes=4)
        return h

    def s98(em, r):
        mat, pos = em.arg32(0), em.arg32(1)
        log('geom', 0x98, rd(mat, 9) + rd(pos, 3) + (pos,))
        em.wbytes(mat, b''.join(_fl(c) for _ in range(9)))
        em.wbytes(pos, b''.join(_fl(c) for _ in range(3)))
        em.ret(eax=c.rng.getrandbits(32), argbytes=8)
    slots = {0x84: s84(0x84), 0x88: s84(0x88), 0x98: s98, 0x2ac: s2ac, 0x390: s390,
             0x3a0: s_ret(0x3a0, lambda: c.rng.choice([0x17, c.rng.getrandbits(32)])),
             0x3a8: s_ret(0x3a8, lambda: c.rng.choice([0x16, c.rng.getrandbits(32)])),
             0x420: s_ret(0x420, lambda: c.rng.choice([0, 1, 1, 2, 0x101])),
             0x438: s_ret(0x438, lambda: _bool(c)), 0x434: s_ret(0x434, lambda: _bool(c)),
             0x430: s_ret(0x430, lambda: _bool(c))}
    slots.update(extra or {})
    g = _rnd(c, size)
    e.w32(g, e.fake_vtable('geom', 0x1b0, slots))
    return g


def _timer(c):
    _world(c)
    w = _rnd(c, 8)
    v = c.rng.choice([0, 1, 0x3fff, 0x4000, -1, c.rng.randrange(0x4000), c.rng.getrandbits(32)])
    return [w + c.rng.choice([0, 2]), v & 0xffffffff]


S(0x4ab8e0, 'CCheckVisible state timer setter (unnamed)', 'thiscall', None, ret=None, gen=_timer, note='b705')


def _uv(c):
    _world(c)
    _inv(c)
    cv = _cv(c)
    k, i = c.rng.randrange(200), c.rng.randrange(200)
    c.emu.w16(cv + 0x6bc + k * 0x1b8 + 2 * i, c.rng.choice([0, 0x4000, 0x8000, 0xc000]) | c.rng.getrandbits(14))
    return [cv, k, i, _bool(c), _bool(c)]


S(0x4ab920, 'CCheckVisible::UpdateVisible (inferred)', 'thiscall', None, ret=None, gen=_uv, note='b705')


def _ops(c):
    _world(c)
    g = geom_fake(c)
    pos = _rnd(c, 16)
    sn = _rnd(c, 4)
    return [_rnd(c, 16), pos, sn, g, _bool(c)]


S(0x4aaa50, 'CCheckVisible::GetObjectPosSneak (inferred)', 'thiscall', None, ret=None, gen=_ops, note='b705')


def _spd(c):
    _world(c)
    g = geom_fake(c)
    pos, d, off = _rnd(c, 16), _rnd(c, 16), _rnd(c, 16)
    return [_rnd(c, 16), pos, d, g, off, _bool(c)]


S(0x4aabe0, 'CCheckVisible::GetSeerPosDir (inferred)', 'thiscall', None, ret=None, gen=_spd, note='b705')
