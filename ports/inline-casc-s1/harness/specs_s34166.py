"""specs_s34166.py - 0x518190 (escalated, 137 instructions). Every callee is a recorder; the register-argument vector helpers log the markers of ecx / edx and the 12-byte vectors they point to (stack addresses never reach the log), after writing their outputs.
523330 writes the input vector v (zero vector, some zero components, random floats); 43e920 / 441940 / 43e960 / 446ee0 write random vectors through ecx; 4e0030 returns a float in st0; the /GS check keeps eax; the CRT sqrt stub comes from the harness."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, HEAP_LO, HEAP_HI


def _fbits(r, edge=0.1):
    k = r.random()
    if k < edge:
        v = r.choice(EDGE_F)
    elif k < edge + 0.04:
        return r.getrandbits(32)
    else:
        v = r.uniform(-50, 50)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def _mark(p):
    return p if HEAP_LO <= p < HEAP_HI else 0x57ac0000


def _vec(r, em, p, zero=0.0):
    if r.random() < 0.5:   # small vectors around the length threshold of 0.25 (exact 0.25 included)
        pick = r.choice([(0.1, 0, 0), (0, 0.1, 0), (0, 0, -0.1), (0.25, 0, 0), (0, -0.25, 0), (0, 0, 0.25), (0, 0, 0), (0.1, 0.1, 0.1), (0.2, 0, 0), (0.3, 0, 0), (0.15, 0.2, 0.0), (-0.25, 0, 0)])
        em.wbytes(p, b''.join(struct.pack('<f', x) for x in pick))
        return
    em.wbytes(p, b''.join(_fbits(r).to_bytes(4, 'little') for _ in range(3)))


def _g518190(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def logmem(em, regs):
        row = ['regs']
        for name in regs:
            p = em.reg(name)
            row.append(_mark(p))
            row.append(bytes(em.rbytes(p, 12)))
        em.calllog.append(tuple(row))

    def s_523330(em, k):
        p = em.arg32(0)
        m = r.random()
        if m < 0.3:
            em.wbytes(p, bytes(12))
        elif m < 0.5:
            vals = [0 if r.random() < 0.5 else _fbits(r) for _ in range(3)]
            em.wbytes(p, b''.join(v.to_bytes(4, 'little') for v in vals))
        else:
            _vec(r, em, p)

    def s_4e0d00(em, k):
        logmem(em, ['ecx'])

    def s_4e0be0(em, k):
        logmem(em, ['ecx', 'edx'])

    def s_443ef0(em, k):
        _vec(r, em, em.reg('ecx'))
        logmem(em, ['ecx', 'edx'])

    def s_43e920(em, k):
        _vec(r, em, em.reg('ecx'))
        logmem(em, ['ecx', 'edx'])

    def s_441940(em, k):
        if r.random() < 0.7:
            _vec(r, em, em.reg('ecx'))
        logmem(em, ['ecx', 'edx'])

    def s_43e960(em, k):
        if r.random() < 0.8:
            _vec(r, em, em.reg('ecx'))
        logmem(em, ['ecx', 'edx'])

    def s_4e0030(em, k):
        logmem(em, ['ecx', 'edx'])

    def s_446ee0(em, k):
        p = em.reg('ecx')
        vals = [_fbits(r), r.choice([0x3f800000, 0xbf800000, 0, 0x80000000, _fbits(r)]), _fbits(r)]
        em.wbytes(p, b''.join(v.to_bytes(4, 'little') for v in vals))
        logmem(em, ['ecx', 'edx'])
        em.calllog.append(('t', bytes(em.rbytes(em.arg32(0), 12))))

    hook_rec(c, 0x523330, 1, this=True, pop=4, side=s_523330)
    hook_rec(c, 0x4e0d00, 1, this='mark', pop=4, side=s_4e0d00)
    hook_rec(c, 0x4e0be0, 0, this='mark', pop=0, side=s_4e0be0)
    hook_rec(c, 0x443ef0, 2, this='mark', pop=8, side=s_443ef0)
    hook_rec(c, 0x43e920, 1, this='mark', pop=4, side=s_43e920)
    hook_rec(c, 0x441940, 0, this='mark', pop=0, side=s_441940)
    hook_rec(c, 0x43e960, 0, this='mark', pop=0, side=s_43e960)
    hook_rec(c, 0x4e0030, 0, this='mark', pop=0, st0=lambda em, k: _f32(r.choice([r.uniform(-10, 10), 0.0, 1.0, -1.0, 100.0])), side=s_4e0030)
    hook_rec(c, 0x446ee0, 1, this='mark', pop=4, stackmark=(0,), side=s_446ee0)
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))
    me = rnd(c, 0x1620)
    F = 0 if r.random() < 0.3 else _fbits(r)
    e.wbytes(me + 0x15fb, F.to_bytes(4, 'little'))
    e.wbytes(me + 0x15f7, _fbits(r).to_bytes(4, 'little'))
    for off in (0x378, 0x37c):
        e.w32(me + off, _fbits(r))
    e.w32(me + 0x5c, rnd(c, 0x20))
    a0, a1 = rnd(c, 0x20), rnd(c, 0x20)
    v = rnd(c, 0x20)
    out = rnd(c, 0x10)
    e.w32(out, _fbits(r))
    return [me, a0, a1, v, out]


S(0x518190, 'GUESS moving point direction and signed length', 'thiscall', None, ret=None, gen=_g518190, note='batch34166')
