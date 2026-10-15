"""specs_s41006.py - t2 (Sonnet) batch 41006: 0x5b9050. Iterator slots and engine table slots are recorders; 0x4db7c0 and 0x451890 (x87) run as exe code; 0x633654 is a recorder."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _bits(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g5b9050(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    fw = [r.getrandbits(32) for _ in range(3)]
    n = r.choice([0, 1, 2, 3, 5])
    # st[0] after each 0x5c call: n values nonzero then 0 (n = 0: loop never runs)
    seq = [r.getrandbits(32) | 1 for _ in range(n)] + [0]
    ids = [r.getrandbits(32) for _ in range(8)]

    def fill(emu, k):
        b = emu.arg32(0)
        for i in range(3):
            emu.w32(b + 4 * i, fw[i])
        emu.calllog.append(('fill',))

    def adv(emu, k):
        emu.w32(emu.arg32(0), seq[min(k, len(seq) - 1)])
    it = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, nullflag=(0,), side=fill),
                       0x5c: pystub(c, 1, this=True, deref={0: 3}, side=adv,
                                    ret=lambda emu, k: ids[k % 8])}, nslots=0x60 // 4)
    objs = []
    for _ in range(3):
        blk = rnd(c, 0x60)
        for off in (0x40, 0x44, 0x48):
            e.wbytes(blk + off, struct.pack('<I', _bits(r.choice([r.uniform(-9, 9), 0.0, 1.0, r.uniform(-1e3, 1e3)]))))
        o = obj(c, 0x20, {0x78: pystub(c, 1, this=True, deref={0: 3})}, nslots=0x7c // 4)
        e.w32(o + 8, blk)
        objs.append(o)
    cyc = [0]
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda emu, k: objs[k % 3])})
    me = rnd(c, 0xc0)
    e.w32(me + 0x4c, it if r.random() < 0.9 else 0)
    for i in range(3):
        e.wbytes(me + 0xa2 + 4 * i, struct.pack('<I', _bits(r.choice([r.uniform(-9, 9), 0.0, 1.0, r.uniform(-100, 100)]))))
    acc = rnd(c, 0x10)
    for i in range(3):
        e.wbytes(acc + 4 * i, struct.pack('<I', _bits(r.choice([r.uniform(-9, 9), 0.0, 1.0, r.uniform(-100, 100)]))))
    return [me, acc]


S(0x5b9050, 'GUESS apply forces from iterator', 'thiscall', None, ret=None, gen=g5b9050, nan_heap=True, note='batch41006')
