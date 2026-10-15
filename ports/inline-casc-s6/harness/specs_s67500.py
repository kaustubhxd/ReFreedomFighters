"""specs_s67500.py - cascade s6 batch 67500 (0x5c4e50, thiscall(stream) ret 4, returns 1). The global readers 0x4e5e60 / 0x4e6180 (ecx = 0) are hooks (counts from 0 to 9, never negative:
a negative count loops about 4 billion times in the original); the allocator returns spec blocks; the stream's slots 0x58 / 0x40 / 0x48 / 0x6c / 0x68 log every call and write scripted
data; table slot 0x58, and the object at [+0x44]+0x18 slot 0x14; the assert hook is always set."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g5c4e50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    cnt = r.choice([0, 1, 2, 3, 5, 6, 9])
    reads = [r.getrandbits(32), cnt]
    hook_rec(c, 0x4e5e60, 0, this=True, ret=lambda em, k: reads[min(k, 1)])
    hook_rec(c, 0x4e6180, 1, this=True, stackmark=(0,), side=lambda em, k: em.w32(em.arg32(0), 0x1000 + k))
    pool = e.alloc(0x100, 4)
    e.wbytes(pool, bytes(r.getrandbits(8) for _ in range(0x100)))
    hook_rec(c, 0x41e290, 1, pop=0, ret=pool)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0x60)

    def mark(v):
        return v if 0x20000000 <= v < 0x30000000 else 1

    def mk(tag, fill):
        def f(em, k):
            em.calllog.append((tag, mark(em.arg32(0)), k))
            if fill:
                em.w32(em.arg32(0), fill(k))
        return f
    stream = obj(c, 0x20, {0x58: pystub(c, 1, this=True, side=mk('s58', None)), 0x40: pystub(c, 1, this=True, stackmark=(0,), side=mk('s40', lambda k: 0x40 + k)),
                           0x48: pystub(c, 1, this=True, side=mk('s48', lambda k: 0x4800 + k)), 0x6c: pystub(c, 1, this=True, side=mk('s6c', lambda k: 0x6c00 + k)),
                           0x68: pystub(c, 1, this=True, side=mk('s68', lambda k: 0x6800 + k))})
    holder = obj(c, 0x20, {0x14: pystub(c, 0, this=True, ret=lambda em, k: r.getrandbits(32))})
    blk = rnd(c, 0x40)
    _w(c, blk + 0x18, holder)
    t = rnd(c, 0x80)
    _w(c, t + 0x44, blk)
    return [t, stream]


S(0x5c4e50, 'GUESS load_record_list', 'thiscall', None, ret='al', gen=_g5c4e50, note='batch67500')
