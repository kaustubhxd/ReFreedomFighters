"""specs_s66086.py - cascade s4 batch 66086: 0x4e9280 (/GS-protected walk over a chain of polygons, scaling a vector and testing every triangle with 0x4dddf0)."""
import struct
from pilot import S
from recruits_util import clear_hooks, hook_rec


def _fl(x):
    return struct.pack('<f', x)


def _g4e9280(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True, ret=lambda em, k: em.reg('eax'))
    e.wbytes(0x678858, _fl(r.choice([1.0, 2.0, 0.5])))
    e._image_dirty = True
    vals = [0.0, 0.5, 1.0, 2.0, -4.0, 8.0, float('nan'), float('inf'), 0.25]
    npoly = r.choice([0, 1, 2, 3, 5])
    sizes = [r.choice([2, 2, 3, 3, 4, 5, 7]) for _ in range(npoly)]
    base = e.alloc(sum(0xc * n + 0x18 for n in sizes) + 0x100, 8)
    p = base
    for n in sizes:
        e.w32(p, n)
        for off in range(4, 0xc * n + 0x18, 4):
            e.wbytes(p + off, _fl(r.choice(vals)))
        p += 0xc * n + 0x18
    t = e.alloc(0x20, 8)
    e.w32(t + 8, npoly)
    e.w32(t + 0xc, base)
    a = e.alloc(0x30, 8)
    for k in range(9):
        e.wbytes(a + 4 * k, _fl(r.choice(vals)))
    cc = e.alloc(0x10, 8)
    for k in range(3):
        e.wbytes(cc + 4 * k, _fl(r.choice(vals + [3.0, -2.0])))
    b = e.alloc(0x20, 8)
    hit = r.choice([-1, -1, 0, 1, 2, 4, 9])
    st = {'k': 0}

    def h4dddf0(em, rr):                  # fastcall (ecx = b, edx = &vec) + 3 stack args ret 0xc
        k = st['k']
        st['k'] += 1
        em.calllog.append(('h4dddf0', em.reg('ecx'), bytes(em.rbytes(em.reg('edx'), 12)), em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=1 if k == hit else (0, 0x100, 0x12300)[k % 3], argbytes=12)
    e.hook(0x4dddf0, h4dddf0)
    return [t, a, b, cc]


S(0x4e9280, 'GUESS test every triangle of a polygon chain against a scaled vector', 'thiscall', None, ret='al', gen=_g4e9280, note='batch66086')
