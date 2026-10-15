"""specs_s32139.py - h2 (Sonnet) batch 32139: 0x51d000, 0x551830, 0x462510. Callees/slots are recorders."""
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


def g51d000(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    fv = r.choice([0.0, 1.0, r.uniform(-500, 500), r.uniform(0, 100)])
    cobj = obj(c, 0x40, {0xc: pystub(c, 1, this=True, pop=0, st0=fv)}, nslots=4)
    me_slots = {off: pystub(c, 0, this=True, side=_log('s%x' % off)) for off in (0x390, 0x374, 0x364)}
    me = obj(c, 0x520, me_slots, nslots=0x394 // 4)
    e.w32(me + 0x5c, cobj)
    o2 = rnd(c, 0x80)
    ret60 = r.choice([o2, o2, 0])
    so = sysobj(c, table_slots={0x60: pystub(c, 1, this=True, ret=ret60), 0x58: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    e.wbytes(me + 0x499, struct.pack('<I', r.choice([0, 0, r.getrandbits(32)])))
    e.wbytes(me + 0x4a9, struct.pack('<I', r.choice([_bits(r.uniform(-9, 9)), _bits(1.0), _bits(100.0), NAN, _bits(1e12)])))
    e.wbytes(me + 0x4a5, struct.pack('<I', r.choice([0, 5, r.getrandbits(32), 0xffffffff])))
    e.w32(cobj + 0x24, r.choice([_bits(r.uniform(-9, 9)), _bits(2.5), 0, _bits(1e10)]))
    hook_rec(c, 0x523520, 3, this=True, pop=12)
    hook_rec(c, 0x51db60, 0, this=True, pop=0, side=_log('db60'))
    hook_rec(c, 0x51cf10, 0, this=True, pop=0, side=_log('cf10'))
    return [me]


def g551830(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    evs = [rnd(c, 0x20) for _ in range(5)]
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=lambda emu, k: evs[min(k, 4)])
    hook_rec(c, 0x5002f0, 1, this=True, pop=4)
    hook_rec(c, 0x500360, 1, this=True, pop=4)
    inner = obj(c, 0x20, {0x4c: pystub(c, 0, this=True, ret=rnd(c, 0x20))}, nslots=0x50 // 4)
    ebx = r.choice([inner, inner, 0])
    o = obj(c, 0x20, {0x18: pystub(c, 1, this=True, ret=ebx)}, nslots=0x1c // 4)
    p = rnd(c, 0x20)
    for i in range(5):
        v = r.choice([_bits(r.uniform(-9, 9)), 0, NAN, r.getrandbits(32), _bits(1.0)])
        e.w32(p + 4 * i, v)
    return [o, r.getrandbits(32), p]


def g462510(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3])
    cbs = [pystub(c, 4, this=True, pop=16) for _ in range(2)]
    elems = []
    for _ in range(n):
        el = rnd(c, 0x20)
        e.w32(el + 4, r.choice([0, 1, r.getrandbits(32)]))
        e.w32(el + 8, r.choice(cbs))
        elems.append(el)
    seqs = elems + [0]
    stv = [r.choice([0.0, 1.0, r.uniform(-9, 9), struct.unpack('<f', struct.pack('<I', NAN))[0]]) for _ in range(4)]
    o = obj(c, 0x20, {0x0: pystub(c, 1, this=True, side=_log('dtor')),
                      0x4c: pystub(c, 1, this=True, nullflag=(0,)),
                      0x64: pystub(c, 1, this=True, nullflag=(0,), ret=lambda emu, k: seqs[min(k, n)]),
                      0x9c: pystub(c, 1, this=True, st0=lambda emu, k: stv[min(k, 3)])}, nslots=0xa0 // 4)
    me = rnd(c, 0x80)
    e.w32(me + 0x6c, r.choice([o, o, o, 0]))
    e.w32(me + 0x74, rnd(c, 0x10))
    return [me, r.choice([0, 1, 0x100, 0x1ff, r.getrandbits(32)])]


S(0x51d000, 'GUESS refresh state and chain', 'thiscall', None, ret=None, gen=g51d000, nan_heap=True, note='batch32139')
S(0x551830, 'GUESS fill entry fields from record', 'stdcall', None, ret='eax', gen=g551830, nan_heap=True, note='batch32139')
S(0x462510, 'GUESS release iterated owner object', 'thiscall', None, ret=None, gen=g462510, nan_heap=True, note='batch32139')
