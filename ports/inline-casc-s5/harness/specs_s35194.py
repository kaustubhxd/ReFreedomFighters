"""specs_s35194.py - 0x4af170 (stdcall(unused, p1, p2) ret 0xc, ret='al', nan_heap). Engine (sysobj): floats at +0x9c7 / +0x9c3 (unaligned; each zero in 1/3, else random), slot 0x1c8 (Python handler: 2 args logged, returns the 64-bit value in EDX:EAX), slots 0x178 / 0x17c (3 args recorded); table +0xadc -> manager with slot 0x2e0
(Python handler: logs six args and the initialised Q fields (floats at +0, +4, +8, +0xc, +0x10, +0x14, dword +0x34, +0x44, byte +0x6c); returns al true/false from a list of two with garbage upper bytes). 0x440530 hooked (thiscall, 0 args). p1, p2: float triples."""
import struct
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _sf(c, lo, hi):
    v = c.fv(lo, hi)
    return v if (v == v and abs(v) < 1e6) else 0.5


def _g4af170(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c, table_size=0xae0)
    for off in (0x9c7, 0x9c3):
        e.wbytes(so + off, (0 if r.random() < 1 / 3 else _fb(_sf(c, -5, 5))).to_bytes(4, 'little'))
    ts = r.getrandbits(64)

    def h1c8(em, res_):
        em.calllog.append(('1c8', em.reg('ecx'), em.arg32(0), em.arg32(1)))
        em.mu.reg_write(REGS['edx'], ts >> 32)
        em.ret(eax=ts & 0xffffffff, argbytes=8)
    vt = e.r32(so)
    e.w32(vt + 0x1c8, e.stub_fn('1c8', h1c8))
    e.w32(vt + 0x178, pystub(c, 3, this=True))
    e.w32(vt + 0x17c, pystub(c, 3, this=True))
    res = [((r.getrandbits(24) << 8) | 1) if r.random() < 0.4 else (r.getrandbits(24) << 8) for _ in range(2)]
    cnt = [0]

    def h2e0(em, res_):
        q = em.arg32(0)
        em.calllog.append(('2e0', em.reg('ecx'), tuple(em.r32(q + o) for o in (0, 4, 8, 0xc, 0x10, 0x14, 0x34, 0x44)), em.rbytes(q + 0x6c, 1),
                           tuple(em.arg32(i) for i in range(1, 6))))
        v = res[min(cnt[0], 1)]
        cnt[0] += 1
        em.ret(eax=v, argbytes=24)
    mgr = obj(c, 0x20, {0x2e0: e.stub_fn('2e0', h2e0)}, nslots=0xc0)
    tab = e.r32(so + 0x9b)
    e.w32(tab + 0xadc, mgr)
    hook_rec(c, 0x440530, 0, this=True, pop=0)
    p1, p2 = rnd(c, 12), rnd(c, 12)
    for p in (p1, p2):
        for i in range(3):
            e.w32(p + 4 * i, _fb(_sf(c, -20, 20)))
    return [r.getrandbits(32), p1, p2]


S(0x4af170, 'GUESS clear line between two points and ground below target', 'stdcall', None, ret='al', gen=_g4af170, nan_heap=True, note='batch35194')
