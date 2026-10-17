"""specs_s213163.py - batch 213163: ZLNKWHANDS style command dispatcher (message ids in globals, virtual command calls, float window tests), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def g472ae0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    ids = []
    while len(ids) < 9:
        v = r.getrandbits(16)
        if v not in ids:
            ids.append(v)
    names = [0x6ff99c, 0x6ff9a4, 0x6ff9a8, 0x6ff9b0, 0x6ff9ac, 0x6ff9bc, 0x6ff9a0, 0x6ff9b4, 0x6ff9b8]
    for a, v in zip(names, ids):
        e.wbytes(a, struct.pack('<H', v))
    bx = r.choice(ids[1:] * 2 + ids[:1] + [r.getrandbits(16)] + [ids[3], ids[3], ids[4], ids[4], ids[4]] * 3)
    D, E = ids[3], ids[4]
    isDE = bx in (D, E)

    def fl():
        return r.choice([0.0, 1.0, -1.0, r.uniform(-50, 50)])

    def comp():
        return r.choice([0.0, 80.0, -80.0, 79.9, -79.9, 60.0, 200.0, -200.0, 199.99, -199.99, 0.25, fl(), r.uniform(-250, 250)])

    def vec3(emu, ptr, vals=None):
        v = vals if vals is not None else [comp() for _ in range(3)]
        emu.wbytes(ptr, struct.pack('<3f', *[f32(x) for x in v]))

    forced = isDE and r.random() < 0.7
    fvec = [r.choice([0.0, 0.0, 80.0, 80.0, -80.0, 79.99, -79.99, 5.0, -5.0, 100.0, 1.0]),
            r.choice([200.0, -200.0, 199.99, -199.99, 0.0, 5.0, 300.0, 50.0, 50.0, 50.0]),
            r.choice([0.0, 0.0, 0.0, 0.0, 80.0, -80.0, 79.99, 5.0, 60.0])]

    def mat9(emu, ptr):
        if forced or r.random() < 0.6:
            m = [1, 0, 0, 0, 1, 0, 0, 0, 1]
        else:
            m = [r.uniform(-1, 1) for _ in range(9)]
        emu.wbytes(ptr, struct.pack('<9f', *[f32(x) for x in m]))

    def logb(tag, n):
        def f(emu, k):
            emu.calllog.append((tag, tuple(bytes(emu.rbytes(emu.arg32(i), nn)) for i, nn in enumerate(n))))
        return f

    # per-case objects
    o80 = obj(c, 0x40, {0x300: pystub(c, 0, this=True, ret=lambda emu, k: r.choice([0, 1, 1]))}, nslots=0x100)

    def s2e0(emu, k):
        mat9(emu, emu.arg32(0))
        vec3(emu, emu.arg32(1), fvec if forced else None)
        emu.calllog.append(('s2e0', bytes(emu.rbytes(emu.arg32(0), 36)), bytes(emu.rbytes(emu.arg32(1), 12))))
    Eo = obj(c, 0x40, {0x2e8: pystub(c, 0, this=True, ret=lambda emu, k: o80 if (isDE or r.random() < 0.7) else 0),
                       0x2e0: pystub(c, 2, this=True, stackmark=(0, 1), side=s2e0),
                       0x98: pystub(c, 2, this=True, stackmark=(0, 1), side=logb('s98o', (36, 12)))}, nslots=0x100)
    Sobj = obj(c, 0x20, {0xbc: pystub(c, 1, this=True)}, nslots=0x60)
    Cobj = obj(c, 0x20, {0x14: pystub(c, 0, this=True, ret=lambda emu, k: r.choice([0, 1, 2, 2, 3])),
                         0x30: pystub(c, 1, this=True, ret=lambda emu, k: rb())}, nslots=0x20)
    idv = rb()
    emap = {idv: Eo}

    def t58(emu, k):
        emu.calllog.append(('t58', emu.arg32(0)))
        return emap.get(emu.arg32(0), 0) if (isDE or r.random() < 0.85) else 0
    T = obj(c, 0x20, {0x58: pystub(c, 1, this=True, ret=t58),
                      0x4c: pystub(c, 1, this=True, ret=lambda emu, k: rb())}, nslots=0x60)
    eng = rnd(c, 0x200)
    e.w32(eng + 0x9b, T)
    e.w32(0x70039c, eng)
    v7c = r.choice([0, 1, 2, 2, 3])

    def s88(emu, k):
        nm, out = emu.arg32(0), emu.arg32(1)
        if nm == 0x688a30:
            emu.w32(out, idv)
        elif nm == 0x68983c:
            emu.w32(out, Cobj if r.random() < 0.85 else 0)
        elif nm == 0x689844:
            emu.w32(out, v7c)
        emu.calllog.append(('s88', nm))
    arg2 = obj(c, 0x20, {0x88: pystub(c, 2, this=True, stackmark=(1,), side=s88),
                         0x4c: pystub(c, 2, this=True)}, nslots=0x60)

    def s3a8(emu, k):
        mat9(emu, emu.arg32(0))
        vec3(emu, emu.arg32(1), [0.0, 0.0, 0.0] if forced else None)
        emu.calllog.append(('s3a8', bytes(emu.rbytes(emu.arg32(0), 36)), bytes(emu.rbytes(emu.arg32(1), 12))))

    def s80(emu, k):
        vec3(emu, emu.arg32(1))
        emu.calllog.append(('s80', bytes(emu.rbytes(emu.arg32(0), 36)), bytes(emu.rbytes(emu.arg32(1), 12))))
    s500 = Sobj if r.random() < 0.6 else 0
    s504 = rb() if r.random() < 0.6 else 0
    slots = {0x488: pystub(c, 1, this=True), 0x48c: pystub(c, 1, this=True), 0x484: pystub(c, 2, this=True),
             0x47c: pystub(c, 1, this=True), 0x480: pystub(c, 1, this=True), 0x448: pystub(c, 1, this=True),
             0x44c: pystub(c, 1, this=True), 0x3a8: pystub(c, 2, this=True, stackmark=(0, 1), side=s3a8, ret=lambda emu, k: rb()),
             0x390: pystub(c, 1, this=True), 0x98: pystub(c, 2, this=True, stackmark=(0, 1), side=logb('s98e', (36, 12))),
             0x80: pystub(c, 2, this=True, stackmark=(0, 1), side=s80),
             0x478: pystub(c, 1, this=True, ret=lambda emu, k: r.choice([0, 1, 2, 3, 3, 4, 4, 5, 5, 6, 7])),
             0x45c: pystub(c, 2, this=True), 0x500: pystub(c, 0, this=True, ret=s500),
             0x504: pystub(c, 0, this=True, ret=s504), 0x4ec: pystub(c, 1, this=True),
             0x16c: pystub(c, 2, this=True)}
    edi = obj(c, 0x200, slots, nslots=0x180)
    e.wbytes(edi + 0x167, struct.pack('<H', bx if r.random() < 0.4 else r.getrandbits(16)))
    e.w32(edi + 0x169, arg2 if r.random() < 0.7 else rb())
    return [edi, bx | (r.getrandbits(16) << 16), arg2]


S(0x472ae0, 'zlnkwhands_command', 'thiscall', None, ret='eax', gen=g472ae0, stack_arg_bytes=8)
