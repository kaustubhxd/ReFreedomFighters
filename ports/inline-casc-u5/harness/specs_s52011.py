"""specs_s52011.py - tier H. 0x4bf6b0: fields at unaligned offsets; engine tick (+0x40) is often set to exactly one of the four float thresholds (or one more / less); table slot 0x58 returns scripted objects (or 0) whose slots 0x1e0 / 0x210 are recorders and whose [+0x18] block is written; this slot 0x68 recorder."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def tr(v):
    if v != v or abs(v) >= 2147483648.0:
        return 0x80000000
    return int(v)


def _g4bf6b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ch = lambda: r.choice([0.0, f32(r.uniform(0, 2)), f32(r.uniform(0, 4)), 0.5, 1.0])
    t56 = r.choice([0.0, f32(r.uniform(0, 5)), f32(r.uniform(0, 5)), 1.0])
    f5a, f5e, f6a, f66 = ch(), ch(), ch(), ch()
    f62 = f32(r.uniform(-1, 2))
    dt = r.choice([0.0, 0.016, f32(r.uniform(0, 0.5))])
    tick = r.randrange(0, 9000)
    t56e = t56 if t56 != 0.0 else None
    if t56e is not None and r.random() < 0.6:
        c1 = 1024.0
        s = f32(f32(f5a + t56) + f66)
        th = [tr(f32(f32(f5a + t56) * c1)), tr(f32(s * c1)), tr(f32(f32(f5e + t56) * c1)), tr(f32(f32(f32(f5e + t56) + f6a) * c1))]
        tick = r.choice(th) + r.choice([0, 0, 0, 1, -1])
    objs = []
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: objs[min(k, 4)])})
    e.w32(so + 0x40, tick & 0xffffffff)
    e.w32(so + 0x48, fb(dt))
    for i in range(5):
        if r.random() < 0.2:
            objs.append(0)
        else:
            blk = rnd(c, 0x100)
            o = obj(c, 0x40, {0x1e0: pystub(c, 1, this=True), 0x210: pystub(c, 1, this=True)}, nslots=0x214 // 4)
            e.w32(o + 0x18, blk)
            objs.append(o)
    me = obj(c, 0x90, {0x68: pystub(c, 2, this=True)}, nslots=0x6c // 4)
    e.wbytes(me + 0x6e, bytes([r.choice([0, 1, 1, 1, 1, r.getrandbits(8)])]))
    e.wbytes(me + 0x4a, r.choice([0, r.getrandbits(32) | 1, r.getrandbits(32) | 1]).to_bytes(4, 'little'))
    e.wbytes(me + 0x52, r.choice([0, 0, r.getrandbits(32) | 1]).to_bytes(4, 'little'))
    for off, v in ((0x56, t56), (0x5a, f5a), (0x5e, f5e), (0x62, f62), (0x66, f66), (0x6a, f6a)):
        e.wbytes(me + off, fb(v).to_bytes(4, 'little'))
    return [me]


S(0x4bf6b0, 'GUESS timed fade of level', 'thiscall', None, ret=None, gen=_g4bf6b0, note='batch52011')
