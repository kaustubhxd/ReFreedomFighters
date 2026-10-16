"""specs_s66083.py - cascade s4 batch 66083: 0x462d80 (/GS-protected: pick the candidate that satisfies a box test and has the smallest distance)."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _fl(x):
    return struct.pack('<f', x)


def _g462d80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    vals = [0.0, 0.5, 1.0, 2.0, 3.5, -1.0, -2.5, float('nan'), 1e9]
    hook_rec(c, 0x633654, 0, pop=0, this=True, ret=lambda em, k: em.reg('eax'))
    e.wbytes(0x67cd44, _fl(r.choice([1e30, 5.0, 100.0])))
    e._image_dirty = True
    n = r.choice([2, 3, 4, 6])
    A = e.alloc(0x30 * 8 + 0x40, 8)
    B = e.alloc(0x30 * 8 + 0x40, 8)
    for i in range(8):
        for off in range(0, 0x30, 4):
            e.wbytes(B + 0x30 * i + off, _fl(r.choice(vals)))
            e.wbytes(A + 0x30 * i + off, _fl(r.choice(vals)))
    struct_mode = r.random() < 0.5
    if struct_mode:
        for i in range(8):
            for j, v in enumerate((2.0, 2.0, 1.0)):
                e.wbytes(B + 0x30 * i + 0x10 + 4 * j, _fl(v))
    seq = {'v4': [], 'd': []}
    cnt = {'v4': 0, 'd': 0}
    for _ in range(24):
        seq['v4'].append(r.choice([[1.0, 1.0, 1.0], [1.0, -1.0, -1.0], [1.0, 1.0, 0.5], [0.5, -1.0, 1.0], [2.0, 1.0, 1.0], [-3.0, 1.0, 1.0], [-1.0, -3.0, 1.0]]) if struct_mode else [r.choice(vals) for _ in range(3)])
        seq['d'].append(r.choice(vals))

    def h460e20(em, rr):                  # fastcall (ecx = dst, edx = src): copy three floats
        d, s = em.reg('ecx'), em.reg('edx')
        em.calllog.append(('h460e20', s))
        em.wbytes(d, bytes(em.rbytes(s, 12)))
        em.ret(eax=0, argbytes=0)

    def h441970(em, rr):                  # fastcall (ecx = dst, edx = src) + 1 stack arg ret 4
        d, s = em.reg('ecx'), em.reg('edx')
        em.calllog.append(('h441970', em.arg32(0)))
        for k in range(3):
            em.wbytes(d + 4 * k, bytes(em.rbytes(s + 4 * k, 4)))
        em.ret(eax=0, argbytes=4)

    def h441940(em, rr):                  # fastcall (ecx = dst, edx = src)
        em.calllog.append(('h441940', em.reg('edx')))
        em.ret(eax=0, argbytes=0)

    def h43e920(em, rr):                  # fastcall (ecx = dst, edx = a) + 1 stack arg ret 4
        k = cnt['v4']
        cnt['v4'] += 1
        d = em.reg('ecx')
        em.calllog.append(('h43e920', em.reg('edx'), bytes(em.rbytes(em.arg32(0), 12))))
        for j in range(3):
            em.wbytes(d + 4 * j, _fl(seq['v4'][k % 24][j]))
        em.ret(eax=0, argbytes=4)

    def h441a60(em, rr):                  # fastcall (ecx = v, edx = a)
        em.calllog.append(('h441a60', em.reg('edx')))
        em.ret(eax=0, argbytes=0)

    def h465470(em, rr):                  # thiscall (ecx = v) -> float on st0
        k = cnt['d']
        cnt['d'] += 1
        em.calllog.append(('h465470',))
        em.ret(eax=0, argbytes=0, st0=seq['d'][k % 24])
    for a, h in ((0x460e20, h460e20), (0x441970, h441970), (0x441940, h441940), (0x43e920, h43e920), (0x441a60, h441a60), (0x465470, h465470)):
        e.hook(a, h)
    hook_rec(c, 0x463010, 0, this=True, ret=A)
    t = obj(c, 0x60, {0x2cc: pystub(c, 0, this=True, ret=B)})
    e.w32(t + 0x20, n)
    return [t, rnd(c, 0x40)]


S(0x462d80, 'GUESS /GS pick the box-test candidate with the smallest distance', 'thiscall', None, ret='eax', gen=_g462d80, note='batch66083')
