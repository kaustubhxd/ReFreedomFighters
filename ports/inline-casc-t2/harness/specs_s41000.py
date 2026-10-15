"""specs_s41000.py - t2 (Sonnet) batch 41000: 0x462510, 0x51d000. Callees (0x523520, 0x51db60, 0x51cf10) and vtable slots are recorders."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _bits(f):
    try:
        return struct.unpack('<I', struct.pack('<f', f))[0]
    except OverflowError:
        return 0x7f800000


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g462510(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5])
    elems = []
    for _ in range(n):
        el = rnd(c, 0x10)
        fn = pystub(c, 4, this=True, pop=None)
        e.w32(el + 4, r.choice([0, 1, r.getrandbits(32) | 1, 0x80000000, 0x100]))
        e.w32(el + 8, fn)
        elems.append(el)
    seq = elems + [0]

    fw = [r.getrandbits(32) for _ in range(30)]

    def fill(emu, k):
        b = emu.arg32(0)
        for i in range(3):
            emu.w32(b + 4 * i, fw[(3 * k + i) % 30])
        emu.calllog.append(('fill',))
    fvals = [r.choice([0.0, 1.0, -2.5, r.uniform(-9, 9), 1e30]) for _ in range(8)]
    cnt = [0]

    def fv(emu, k):
        return None
    m = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, nullflag=(0,), side=fill),
                      0x64: pystub(c, 1, this=True, deref={0: 3}, ret=lambda emu, k: seq[min(k, len(seq) - 1)]),
                      0x9c: pystub(c, 1, this=True, st0=lambda emu, k: fvals[k % 8]),
                      0x00: pystub(c, 1, this=True, side=_log('del'))}, nslots=0xa0 // 4)
    me = rnd(c, 0x90)
    e.w32(me + 0x6c, m if r.random() < 0.85 else 0)
    e.w32(me + 0x74, rnd(c, 0x10))
    flag = r.choice([0, 1, 0x100, 0xff, r.getrandbits(32), 1, 1, 1])
    return [me, flag]


def g51d000(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x523520, 3, this=True, pop=12)
    hook_rec(c, 0x51db60, 0, this=True, pop=0)
    hook_rec(c, 0x51cf10, 0, this=True, pop=0)
    rb = rnd(c, 0x80)
    tbl_slots = {0x60: pystub(c, 1, this=True, ret=(lambda x: lambda emu, k: x)(rb if r.random() < 0.8 else 0)), 0x58: pystub(c, 1, this=True)}
    sysobj(c, table_slots=tbl_slots)
    A = obj(c, 0x40, {0xc: pystub(c, 0, this=True, st0=r.choice([0.0, 1.0, -3.5, r.uniform(-9, 9), 1e30]))}, nslots=4)
    for off in (0x24,):
        e.wbytes(A + off, struct.pack('<I', r.choice([_bits(r.uniform(-9, 9)), _bits(r.uniform(-1e5, 1e5)), NAN, 0x7f800000, _bits(1e12), 0])))
    me = rnd(c, 0x4c0)
    e.w32(me + 0x5c, A)
    e.w32(me + 0x499 if False else me + 0x499, 0)
    if r.random() < 0.7:
        e.wbytes(me + 0x499, struct.pack('<I', r.getrandbits(32) | 1))
    else:
        e.wbytes(me + 0x499, bytes(4))
    e.wbytes(me + 0x4a9, struct.pack('<I', r.choice([_bits(r.uniform(-9, 9)), _bits(30.0), NAN, 0])))
    vt = e.alloc(0x3a0, 4)
    for off in (0x390, 0x374, 0x364):
        e.w32(vt + off, pystub(c, 0, this=True))
    e.w32(me, vt)
    return [me]


S(0x462510, 'GUESS update and delete sound list', 'thiscall', None, ret=None, gen=g462510, nan_heap=True, note='batch41000')
S(0x51d000, 'GUESS init from camera and refresh', 'thiscall', None, ret=None, gen=g51d000, nan_heap=True, note='batch41000')
